import rclpy
import cv2
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int16MultiArray
from std_msgs.msg import Int16
from std_msgs.msg import Float32
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from geometry_msgs.msg import Pose
from geometry_msgs.msg import Pose
from rclpy.qos import qos_profile_sensor_data
from custom_msgs.msg import FireSeverity as FireSeverityMsg
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
from custom_srvs.srv import Policy
from custom_srvs.srv import MoveOrder
import psutil
import numpy
import math
import random
import time
from enum import Enum


class UGV2Main(Node):

    def __init__(self):
        super().__init__("UGV2Main")

        #define possible states of UGV:
        #self.State = Enum('State', ['Transit','Attending', 'Idle', 'Waiting','Do Not Disturb'])
        self.state = "Idle"
        #Transit = Heading to a specific location
        #Attending = Attending to a given fire
        #Idle = Is stationary and not completing a given task
        #Waiting = Waiting for action of other robots
        #DND = Will not respond to other robots.
        Publisher_name = '/Z2FireSeverity'
        
        self.x = 0.0; #this will be the x coodinate of the agent retrieved from the navigation node.
        self.y = 0.0; #this will be the y coodinate of the agent retrieved from the navigation node.
        self.publisher = self.create_publisher(FireSeverityMsg,Publisher_name,10)
        self.publishMoveOrder = self.create_publisher(Pose,"/poseOrder1",10) #publisher to test the navigation system (for testing purposes)
        self.state_publisher = self.create_publisher(String,"/UGV2State",10)
        self.GO_publisher = self.create_publisher(Int16, '/GO',10) #for purposes of debugging
        self.CPUPublisher = self.create_publisher(Float32,"/UGV2CPU",10) #publisher to test the navigation system (for testing purposes)
        self.RAMPublisher = self.create_publisher(Float32,"/UGV2RAM",10) #publisher to test the navigation system (for testing purposes)
        self.GO_subscriber = self.create_subscription(Int16,'/GO',self.GO_message, qos_profile_sensor_data)
        self.moveOrderSubscription = self.create_subscription(Pose,"/poseOrder0",self.UGV1PoseOrder_message, qos_profile_sensor_data) #fetches its friend's location
        self.subscription = self.create_subscription(Int16MultiArray,"/UGV2Detections",self.detections_message, qos_profile_sensor_data)
        self.reachedGoalSubscription = self.create_subscription(Int16,"/reaching_goal1",self.reaching_goal, qos_profile_sensor_data)
        self.subscription2 = self.create_subscription(FireSeverityMsg,"/Z1FireSeverity",self.Z1_detections_message, qos_profile_sensor_data)
        self.subscription3 = self.create_subscription(LEDLocationsMsg,"/LEDLocations",self.LED_message, qos_profile_sensor_data)
        self.FireSeverity= FireSeverityMsg()
        self.UGVDetections = Int16MultiArray()
        self.UGVDetections.data = [0,0,0,0]
        self.timer_period = 0.5
        self.orderCount = 0 #for testing purposes
        self.i = 0
        self.atWayPose = 0
        #EXTERNAL INPUTS FOR STATE MACHINE
        self.currentStateNumber = 0b00
        self.nextStateNumber = 0b00
        self.LEDLocationsisled2 = 0b01 #add back . between LEDLocationsisled1
        self.CommsTimeoutUAV = 0b0
        self.CommsTimeoutUGV = 0b0
        self.LEDDetected = 0b1
        self.FireSeverityIsDetected = 0b0
        self.UGV1to2Ack = 0b1
        self.UGV1Jump = 0b0
        self.GO = 0b0
        self.UGVCount = 0b0
        self.UGV1to2Ack = "Null"
        self.stateDescription = "Idle"
        self.Z1Intensity = 0
        self.Z2Intensity = 0

        #Locations:

        self.z0=Pose()
        self.z0.position.x = 0.0
        self.z0.position.y = -0.30
        self.z0.position.z = 0.0

        self.z1=Pose()
        self.z1.position.x = -0.7
        self.z1.position.y = 0.23
        self.z1.position.z = 0.0

        self.z2=Pose()
        self.z2.position.x = -0.6
        self.z2.position.y = -0.7
        self.z2.position.z = 0.0

        self.z3=Pose()
        self.z3.position.x = 0.65
        self.z3.position.y = -0.69
        self.z3.position.z = 0.0

        self.z4=Pose()
        self.z4.position.x = 0.65
        self.z4.position.y = 0.23
        self.z4.position.z = 0.0

        self.z1pose = self.z0
        self.z2pose = self.z0 #replace with detected LEDDetections.led2

        self.Pose_msg = self.z0

        #StateMachine
        self.timer = self.create_timer(self.timer_period,self.timer_callback)
        #Testing Services:
        self.UGV2Ack = self.create_service(Policy, '/UGV2Ack', self.UGVResponse)

        self.cli = self.create_client(Policy, '/UGV1Ack')

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('/UGVAck1'+' service not available, waiting again...')
        self.req = Policy.Request()

    def send_request(self, a, b):
        self.req.location = a
        self.req.eta = b
        self.future = self.cli.call_async(self.req)
        #rclpy.spin_until_future_complete(self, self.future)
        print("Sending Request" + str(a) + " with eta: " + str(b))
        return self.future.result()

    def reaching_goal(self,data):
        self.atWayPose = data.data

    def UGV1PoseOrder_message(self,data):
        if (self.z1pose != self.z2pose):
            self.z1pose = data

    def Z1_detections_message(self,data):
        Z1Sev = data.severity
        if (Z1Sev == "Low"):
            self.Z1Intensity = 1
        elif (Z1Sev == "Medium"):
            self.Z1Intensity = 2
        elif (Z1Sev == "High"):
            self.Z1Intensity = 3
        else:
            self.Z1Intensity = 0

    def UGVResponse(self, request, response):
        response.ack = "Yes"
        self.UGV1to2Ack = "Yes"
        print(request)
        return response

    def LED_message(self,data):
        self.LEDLocations = data
        print("Recieved LED Detections are:")
        self.LEDLocationsisled2 = data.isled2
        if (data.isled1 == 1):
            if (data.led1 == 1):
                self.z1pose = self.z1
            elif (data.led1 == 2):
                self.z1pose = self.z2
            elif (data.led1 == 3):
                self.z1pose = self.z3
            elif (data.led1 == 4):
                self.z1pose = self.z4
        else:
            self.z1pose = self.z0
        if (data.isled2 == 1):
            if (data.led2 == 1):
                self.z2pose = self.z1
            elif (data.led2 == 2):
                self.z2pose = self.z2
            elif (data.led2 == 3):
                self.z2pose = self.z3
            elif (data.led2 == 4):
                self.z2pose = self.z4
        else:
            self.z2pose = self.z0

        print("==========================")
        print("Zone 1 and 2 are:")
        print(self.z1pose)
        print(self.z2pose)
        print("==========================")
        #determine LED Location from here

        print(self.LEDLocations)

    def GO_message(self,data):
        self.GO = data.data

    def detections_message(self,data):
        self.UGVDetections = data.data
        print(data)

    #This function writes a frame to the camerapublisher topic every time it runs, this will be absorbed by the state machine    
    def timer_callback(self):
        self.get_logger().info('Publishing Severity locations, state and movement order')
        #order = Pose()
        #self.orderCount = self.orderCount + 1 #for testing purposes
        #if (self.orderCount <= 80):
        #    self.state = "Return to centre"
        #    order = self.z0            
        #elif (self.orderCount <= 160):
        #    self.state = "Transit"
        #    order = self.z1
        #elif (self.orderCount <= 240):
        #    self.state = "Return to centre"
        #    order = self.z0
        #elif (self.orderCount <= 320):
        #    self.state = "Transit"
        #    order = self.z2
        #elif (self.orderCount <= 400):
        #    self.state = "Return to centre"
        #    order = self.z0
        #elif(self.orderCount <= 480):
        #    self.orderCount = 0
        #    order = self.z0
        #print(self.orderCount)
        #self.publishMoveOrder.publish(order)

        #testing send policy program:
        #self.Pose_msg = Pose()
        #self.Pose_msg.x = 0.0
        #self.Pose_msg.y = 0.0
        #self.Pose_msg.z = 0.0
        #float_msg = 1.1
        #self.send_request(self.Pose_msg, float(float_msg))
        self.StateMachine()

    def determineSeverity(self):

        severityString = "Null"
        threshold = 250

        #returns from Processing node
        High = self.UGVDetections[0]*1.5
        Low = self.UGVDetections[1]
        Medium = self.UGVDetections[2]*2.5

        #now we determine which LED is on:
        lst = [["High",High],["Low",Low],["Medium",Medium]]
        lst.sort(key=lambda lst:lst[1])
        lst = lst[::-1]
        #print(lst)

        #use this sorted list to get correct returns:
        if threshold <= lst[0][1]:
            if lst[0][0] == "High":
                severityString = "High"
            if lst[0][0] == "Low":
                severityString = "Low"
            if lst[0][0] == "Medium":
                severityString = "Medium"
        else:
            severityString = "None"
            return severityString

        return severityString

    def StateMachine(self):

        #create local counter tUAV

        #outputs:
        state_topic = String()
        state_topic.data = self.state
        self.state_publisher.publish(state_topic)
        self.currentStateNumber = self.nextStateNumber
        print(self.stateDescription)

        process = psutil.Process()
        cpu_usage = psutil.cpu_percent(interval=1)
        ram_usage = psutil.virtual_memory().percent

        CPUmessage = Float32()
        CPUmessage.data = cpu_usage
        self.CPUPublisher.publish(CPUmessage)

        RAMmessage = Float32()
        RAMmessage.data = ram_usage
        self.RAMPublisher.publish(RAMmessage)

        #counters
        #if(self.UGVCount > 0):  
        #    self.UGVCount = self.UGVCount - 1
        #    self.UGV1to2Ack = 1
        #else:
        #    self.UGV1to2Ack = 0

        #00000
            #state = "Idle"
            #description = "Idle"
            #UGV1to2Ack = None
            #Transition to 00001 if:
                #LEDDetected = 1 or CommsTimeoutUAV = 1

        if (self.currentStateNumber == 0b00000):
            self.ReachedFirstZone = 0
            #debug: changing "GO"
            #self.Z1Intensity = 0 commented out due to no LED
            #self.Z2Intensity = 0
            self.Z1Intensity = 0
            self.Z2Intensity = 0
            self.state = "Idle"
            self.stateDescription = "Idle"
            #self.Pose_msg = self.z0
            self.publishMoveOrder.publish(self.Pose_msg)
            #if (((self.LEDLocationsisled2 == 0b1) or (self.CommsTimeoutUAV == 0b1)) and (self.GO == 0b1)):
            if (self.GO == 0b1):
                self.nextStateNumber = 0b01
            else:
                self.nextStateNumber = 0b0

        #00001
            #state = "Idle"
            #description = "Proposing Policy"
            #UGV1to2Ack = "Hey"
            #Transition to 01100 if:
                #CommsTimeoutUAV = 1
            #Transition to 00010 if:
                #LEDDetected = 1 and CommsTimeoutUAV = 0
            #Transition to 00000 if:
                #LEDDetected = 0 and CommsTimeoutUAV = 0

        elif (self.currentStateNumber == 0b00001):
            self.state = "Idle"
            self.stateDescription = "Proposing Policy"
            time.sleep(2)
            if ((self.LEDDetected == 1) and (self.CommsTimeoutUAV == 0)):
                self.Pose_msg = Pose()
                self.Pose_msg = self.z2pose
                float_msg = 1.0 #eta
                self.send_request(self.Pose_msg, float(float_msg))
                self.nextStateNumber = 0b0010

            if ((self.LEDDetected == 0) and (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b00000

            if (self.CommsTimeoutUAV == 0b1):
                self.nextStateNumber = 0b0
                
        
        #00010
            #State = "Idle"
            #Description = "Receiving Policy"
            #UGV1to2Ack = "Ack" 
            #Transition to 01100 if:
                #CommsTimeoutUAV= 1 or CommsTimeoutUGV = 1
            #Transition to 00011 if:
                #CommsTimeoutUAV = 0 and CommsTimeoutUGV = 0
        elif (self.currentStateNumber == 0b00010):
            self.state = "Idle"
            self.stateDescription = "Receiving Policy"

            if ((self.CommsTimeoutUGV == 1) and (self.CommsTimeoutUAV == 1)):
                self.nextStateNumber = 0b01100

            elif ((self.CommsTimeoutUGV == 0) or (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b00011

        #00011
            #State = "Waiting"
            #Description = "Waiting for answer back from UGV2 (seeing if UGV2 Approves)"
            #UGV1to2Ack = None 
            #Transition to 00100:
                #Policy Accepted by UGV1
            #Transition to 01011:
                #Policy Rejected by UGV1 and self.UGV1to2Ack = yes
            #Transition to 00000:
                #LEDDetected = 0
        elif (self.currentStateNumber == 0b00011):
            self.state = "Waiting"
            self.stateDescription = "Waiting for answer back from UGV1 (seeing if UGV2 Approves)"
            acceptPolicy = 1

            #keep sending policy
            self.Pose_msg = Pose()
            self.Pose_msg = self.z2pose 
            self.z2pose = self.Pose_msg #replace with detected LEDDetections.led2
            float_msg = 1.0 #eta
            self.send_request(self.Pose_msg, float(float_msg))

            #code block to determine if policy is approved
            if ((self.UGV1to2Ack == "Yes") and (self.LEDDetected == 1)):
                self.UGV1to2Ack == "Null"
                if(acceptPolicy == 1):
                    self.nextStateNumber = 0b00100
                if(acceptPolicy == 0):
                    self.nextStateNumber = 0b01011
            elif(self.LEDDetected == 0):
                self.nextStateNumber = self.currentStateNumber
            elif(self.UGV1to2Ack == "No"):
                self.UGV1to2Ack == "Null"
                self.nextStateNumber = 0b1
            else:
                self.nextStateNumber = self.currentStateNumber

        #00100
            #State = "Waiting"
            #Description = "Received policy and content"
            #UGV1to2Ack = "Yes" 
            #Transition to 00101:
                #self.UGV1to2Ack = Ack
            #Transition to 01110:
                #CommsTimeoutUGV=1

        elif (self.currentStateNumber == 0b00100):
            self.publishMoveOrder.publish(self.Pose_msg)
            self.state = "Waiting"
            self.stateDescription = "Received policy and content"
            self.Pose_msg = self.z2pose
            self.publishMoveOrder.publish(self.Pose_msg)
            UGV2to1Ack = "Yes"
            self.UGV1to2Ack = "Ack"
            if (self.UGV1to2Ack == "Ack"):
                self.UGV1to2Ack = "Null"
                self.nextStateNumber = 0b00101
            elif (self.CommsTimeoutUGV == 1):
                self.nextStateNumber = 0b01110

        #00101
            #State = "Transit"
            #Description = "Moving"
            #UGV1to2Ack = "Ack"
            #Transition to 00110:
                #UGV arrives at wayPose
            #Transition to 01111:
                #UGV1Jump = 1

        elif (self.currentStateNumber == 0b00101):
            self.state = "Transit"
            self.stateDescription = "Moving"
            UGV1to2Ack = "Ack"
            self.Pose_msg = self.z2pose
            self.publishMoveOrder.publish(self.Pose_msg)
            #stand in variable for transit
            if (self.atWayPose == 1):
                time.sleep(20)
                self.nextStateNumber = 0b00110
            if (self.UGV1Jump == 1):
                self.nextStateNumber = 0b01111

        #00110
            #State = "Attending"
            #Description = "Reporting LED Intensity"
            #UGV1to2Ack = None 
            #Transition to 0111:
                #100ms delay
        
        elif (self.currentStateNumber == 0b00110):
            self.state = "Attending"
            self.stateDescription = "Reporting LED Intensity"
            if ((self.Pose_msg == self.z2pose) and (self.ReachedFirstZone == 0)):
                Z2Sev = self.determineSeverity()
                print("====================================")
                print("Detected Severity as: " + str(Z2Sev))
                print("====================================")
                if (Z2Sev == "Low"):
                    self.Z2Intensity = 1
                elif (Z2Sev == "Medium"):
                    self.Z2Intensity = 2
                elif (Z2Sev == "High"):
                   self.Z2Intensity = 3
                else:
                   self.Z2Intensity = 0
            #if (self.Pose_msg == self.z2pose):
                self.FireSeverity.severity = Z2Sev
                self.publisher.publish(self.FireSeverity)  #commented out due to not having camera runnings

            self.ReachedFirstZone = 0
            self.nextStateNumber = 0b00111

            
        #00111
            #State = "Attending"
            #Description = "Receiving LED Intensity"
            #UGV1to2Ack = None
            #Transition to 01000:
                #Zone 1 Severity < Zone 2 Severity
            #Transition to 01001:
                #Zone 1 Severity > Zone 2 Severity
            #Transition to 01010:
                #GO = 0

        elif (self.currentStateNumber == 0b00111):
            self.state = "Attending"
            self.stateDescription = "Recieving LED Intensity"
            self.publishMoveOrder.publish(self.Pose_msg) #republishing pose
            #Determine the higher severity
            HighestSeverity = 1 #either 0,1,2
            print("====================================")
            print("Z2 Intensity is: " + str(self.Z2Intensity))
            print("Z1 Intensity is: " + str(self.Z1Intensity))
            print("====================================")
            if (self.Z1Intensity > self.Z2Intensity):
                self.nextStateNumber = 0b01000
                self.Pose_msg = self.z1pose
                self.publishMoveOrder.publish(self.Pose_msg)
            else:
                self.nextStateNumber = 0b01001
                self.Pose_msg = self.z2pose #replace with detected LEDDetections.led2
                self.publishMoveOrder.publish(self.Pose_msg)
            
            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            
        #01000
            #State = "Transit"
            #Description = "Going to the other fire"
            #UGV1to2Ack = None
            #Transition to 01010:
                #GO=0
            #Transition to 01001:
                #Fire is extinguished
        elif (self.currentStateNumber == 0b01000):
            self.state = "Transit"
            self.stateDescription = "Going to other fire"
            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            if (self.atWayPose == 1):
                self.nextStateNumber = 0b01001
        
        #01001
            #State = "Attending"
            #Description = "Waiting in zone"
            #UGV1to2Ack = None
            #Transition to 01010:
                #GO = 0
        elif (self.currentStateNumber == 0b01001):
            self.state = "Attending"
            self.stateDescription = "Waiting in zone"
            #wait


            #Randomly change GO testing (1 in 5 chance)
            #b = random.randint(1,10)
           # if (b==10):
            #    a = Int16()
            #    a.data = 0b0
           #     self.GO_publisher.publish(a)


            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            else:
                self.nextStateNumber = 0b00110


        #01010
            #State = "Transit"
            #Description = "Return to centre"
            #UGV1to2Ack = None
            #transition to 000000
        elif (self.currentStateNumber == 0b01010):
            self.state = "Transit"
            self.stateDescription = "Return to centre"
            self.Pose_msg = self.z0
            self.publishMoveOrder.publish(self.Pose_msg)
            #time.sleep(30)
            if (self.atWayPose == 1):
                self.nextStateNumber = 0b000000

        #01100
            #State = "Attending"
            #Description = "Attend to the other zone if not responsive"
            #UGV1to2Ack = None
            #Transition to 01101:
                #each clock cycle
        elif (self.currentStateNumber == 0b01100):
            self.state = "Attending"
            self.stateDescription = "Attend to other zone if not responsive"
            self.nextStateNumber = 0b01101

        #01101
            #State = "Transit"
            #Description = "Check every zone"
            #UGV1to2Ack = None
            #Transition to 01110:
                #next clock cycle
        elif (self.currentStateNumber == 0b01101):
            self.state = "Transit"
            self.stateDescription = "Check every zone"
            self.nextStateNumber = 0b01110

        #01110:
            #State = "Idle"
            #Description = "Create two zone policy"
            #UGV1to2Ack = None
            #Transition to 00101:
                #Next clock cycle
        elif (self.currentStateNumber == 0b01110):
            self.state = "Idle"
            self.stateDescription = "Create two zone policy"
            self.nextStateNumber = 0b00101
            
        #01111:
        #State = "Attending"
        #Description = "Receive Message Interrupt"
        #UGV1to2Ack = None
        elif (self.currentStateNumber == 0b01111):
            self.state = "Attending"
            self.stateDescription = "Recieve Message Interrupt"

        #10000:
            #State = "DND"
            #Description = "DND"
        elif (self.currentStateNumber == 0b01000):
            self.state = "DND"
            self.stateDescription = "DND"

def main (args=None):
    rclpy.init(args=args)
    
    UGV = UGV2Main()
    
    print('Node: UGV2Main has been created')

    rclpy.spin(UGV)

    UGV.destroy_node()

    rclpy.shutdown()
