import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int16MultiArray
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from geometry_msgs.msg import Pose
from rclpy.qos import qos_profile_sensor_data
from custom_msgs.msg import FireSeverity as FireSeverityMsg
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
from custom_srvs.srv import Policy
from custom_srvs.srv import MoveOrder
import numpy
import math
from enum import Enum
import cv2


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
        Publisher_name = '/UGV2FireSeverity'
        
        self.x = 0.0; #this will be the x coodinate of the agent retrieved from the navigation node.
        self.y = 0.0; #this will be the y coodinate of the agent retrieved from the navigation node.
        self.publisher = self.create_publisher(FireSeverityMsg,Publisher_name,10)
        self.publishMoveOrder = self.create_publisher(Pose,"/poseOrder1",10) #publisher to test the navigation system (for testing purposes)
        self.state_publisher = self.create_publisher(String,"/UGV2State",10)
        self.LEDLocationsTopic = self.create_subscription(LEDLocationsMsg,'/LED2Locations',self.LED_message, qos_profile_sensor_data)
        self.subscription = self.create_subscription(Int16MultiArray,"/UGV2Detections",self.detections_message, qos_profile_sensor_data)
        self.FireSeverity= FireSeverityMsg()
        self.timer_period = 0.5
        self.orderCount = 0 #for testing purposes
        self.i = 0
        #EXTERNAL INPUTS FOR STATE MACHINE
        self.currentStateNumber = 0b00
        self.nextStateNumber = 0b00
        self.LEDLocationsisled1 = 0b01 #add back . between LEDLocationsisled1
        self.CommsTimeoutUAV = 0b0
        self.CommsTimeoutUGV = 0b0
        self.LEDDetected = 0b1
        self.FireSeverityIsDetected = 0b0
        self.UGV2to1Ack = 0b1
        self.UGV2Jump = 0b0
        self.GO = 0b1
        self.UGVCount = 0b0

        #Locations:

        self.z0=Pose()
        self.z0.position.x = -0.29
        self.z0.position.y = -0.135
        self.z0.position.z = 0.0

        self.z1=Pose()
        self.z1.position.x = -0.815
        self.z1.position.y = -0.43
        self.z1.position.z = 0.0

        self.z2=Pose()
        self.z2.position.x = -0.815
        self.z2.position.y = 0.22
        self.z2.position.z = 0.0

        self.z3=Pose()
        self.z3.position.x = 1.0
        self.z3.position.y = 2.0
        self.z3.position.z = 0.0

        self.z4=Pose()
        self.z4.position.x = 1.0
        self.z4.position.y = 2.0
        self.z4.position.z = 0.0

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
        self.UGVCount = self.UGVCount+1
        #rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    def UGVResponse(self, request, response):
        response.ack = "Yes"
        print(request)
        return response

    def LED_message(self,data):
        self.LEDLocations = data
        print("Recieved LED Detections are:")
        print(self.LEDLocations)

    def detections_message(self,data):
        self.UGVDetections = data.data
        print(data)
        print("Determining state of LED")
        self.FireSeverity.severity = self.determineSeverity()
        #self.LEDLocations.isled1 = self.LEDState[0]
        self.FireSeverity.fire_x = self.x
        self.FireSeverity.fire_y = self.y
    #This function writes a frame to the camerapublisher topic every time it runs, this will be absorbed by the state machine    
    def timer_callback(self):
        self.publisher.publish(self.FireSeverity)
        state_topic = String()
        state_topic.data = self.state
        self.state_publisher.publish(state_topic)
        self.get_logger().info('Publishing Severity locations, state and movement order')
        order = Pose()
        self.orderCount = self.orderCount + 1 #for testing purposes
        if (self.orderCount <= 80):
            self.state = "Return to centre"
            order = self.z0            
        elif (self.orderCount <= 160):
            self.state = "Transit"
            order = self.z1
        elif (self.orderCount <= 240):
            self.state = "Return to centre"
            order = self.z0
        elif (self.orderCount <= 320):
            self.state = "Transit"
            order = self.z2
        elif (self.orderCount <= 400):
            self.state = "Return to centre"
            order = self.z0
        elif(self.orderCount <= 480):
            self.orderCount = 0
            order = self.z0
        print(self.orderCount)

        #write to topic
        point_msg = Point()
        point_msg.x = 0.0
        point_msg.y = 0.0
        point_msg.z = 0.0

        float_msg = 1.1

        self.send_request(point_msg, float(float_msg))
        self.publishMoveOrder.publish(order)

        self.StateMachine()
     
    def determineSeverity(self):

        severityString = "Null"
        threshold = 2500

        #returns from Processing node
        High = self.UGVDetections[0]
        Low = self.UGVDetections[1]
        Medium = self.UGVDetections[2]

        #now we determine which LED is on:
        lst = [["High",High],["Low",Medium],["Medium",Medium]]
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
            return severityString

        return severityString

    def StateMachine(self):

        #create local counter tUAV

        #This state = next state

        self.currentStateNumber = self.nextStateNumber
        if(self.UGVCount > 0):  
            self.UGVCount = self.UGVCount - 1
            UGV1to2Ack = 1
        else:
            UGV1to2Ack = 0


        #00000
            #state = "Idle"
            #description = "Idle"
            #UGV2to2Ack = None
            #Transition to 00001 if:
                #LEDDetected = 1 or CommsTimeoutUAV = 1

        if (self.currentStateNumber == 0b00000):
            self.state = "Idle"
            self.stateDescription = "Idle"
            if ((self.LEDLocationsisled1 == 0b1) or (self.CommsTimeoutUAV == 0b1)):
                self.nextStateNumber = 0b01
            else:
                self.nextStateNumber = self.currentStateNumber

        #00001
            #state = "Idle"
            #description = "Proposing Policy"
            #UGV2to2Ack = "Hey"
            #Transition to 01100 if:
                #CommsTimeoutUAV = 1
            #Transition to 00010 if:
                #LEDDetected = 1 and CommsTimeoutUAV = 0
            #Transition to 00000 if:
                #LEDDetected = 0 and CommsTimeoutUAV = 0

        elif (self.currentStateNumber == 0b00001):
            self.state = "Idle"
            self.stateDescription = "Proposing Policy"
            if ((self.LEDDetected == 1) and (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b0010

            if ((self.LEDDetected == 0) and (self.CommsTimeoutUAV == 0)):
                self.nextStateNumber = 0b00000

            if (self.CommsTimeoutUAV == 0b1):
                self.nextStateNumber = 0b0
                
        
        #00010
            #State = "Idle"
            #Description = "Receiving Policy"
            #UGV2to2Ack = "Ack" 
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
            #UGV2to2Ack = None 
            #Transition to 00100:
                #Policy Accepted by UGV2
            #Transition to 01011:
                #Policy Rejected by UGV2 and self.UGV2to1Ack = yes
            #Transition to 00000:
                #LEDDetected = 0
        elif (self.currentStateNumber == 0b00011):
            self.state = "Waiting"
            self.stateDescription = "Waiting for answer back from UGV2 (seeing if UGV2 Approves)"
            acceptPolicy = 1

            #code block to determine if policy is approved
            if ((self.UGV2to1Ack == "Yes") and (self.LEDDetected == 1)):
                if(acceptPolicy == 1):
                    self.nextStateNumber = 0b00100
                if(acceptPolicy == 0):
                    self.nextStateNumber = 0b01011
            elif(self.LEDDetected == 0):
                self.nextStateNumber = self.currentStateNumber
            elif(self.UGV2to1Ack == "No"):
                self.nextStateNumber = 0b1
            else:
                self.nextStateNumber = self.currentStateNumber

        #00100
            #State = "Waiting"
            #Description = "Received policy and content"
            #UGV2to2Ack = "Yes" 
            #Transition to 00101:
                #self.UGV2to1Ack = Ack
            #Transition to 01110:
                #CommsTimeoutUGV=1

        elif (self.currentStateNumber == 0b00100):
            self.state = "Waiting"
            self.stateDescription = "Received policy and content"
            UGV2to2Ack = "Yes"
            if (self.UGV2to1Ack == "Ack"):
                self.nextStateNumber = 0b00101
            elif (self.CommsTimeoutUGV == 1):
                self.nextStateNumber = 0b01110

        #00101
            #State = "Transit"
            #Description = "Moving"
            #UGV2to2Ack = "Ack"
            #Transition to 00110:
                #UGV arrives at waypoint
            #Transition to 01111:
                #UGV2Jump = 1

        elif (self.currentStateNumber == 0b00101):
            self.state = "Transit"
            self.stateDescription = "Moving"
            UGV2to2Ack = "Ack"
            Atwaypoint = 1 #stand in variable for transit
            if (Atwaypoint == 1):
                self.nextStateNumber = 0b00110
            if (self.UGV2Jump == 1):
                self.nextStateNumber = 0b01111

        #00110
            #State = "Attending"
            #Description = "Reporting LED Intensity"
            #UGV2to2Ack = None 
            #Transition to 0111:
                #100ms delay
        
        elif (self.currentStateNumber == 0b00110):
            self.state = "Attending"
            self.stateDescription = "Reporting LED Intensity"
            sleep(0.1) # sleep for 100 ms
            self.nextStateNumber = 0b00111

            
        #00111
            #State = "Attending"
            #Description = "Receiving LED Intensity"
            #UGV2to2Ack = None
            #Transition to 01000:
                #Zone 1 Severity < Zone 2 Severity
            #Transition to 01001:
                #Zone 1 Severity > Zone 2 Severity
            #Transition to 01010:
                #GO = 0

        elif (self.currentStateNumber == 0b00111):
            self.state = "Attending"
            self.stateDescription = "Recieving LED Intensity"
            
            #Determine the higher severity
            HighestSeverity = 1 #either 0,1,2

            if (HighestSeverity == 2):
                self.nextStateNumber = 0b01000
            else:
                self.nextStateNumber = 0b01001
            
            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            
        #01000
            #State = "Transit"
            #Description = "Going to the other fire"
            #UGV2to2Ack = None
            #Transition to 01010:
                #GO=0
            #Transition to 01001:
                #Fire is extinguished
        elif (self.currentStateNumber == 0b01000):
            self.state = "Transit"
            self.stateDescription - "Going to other fire"
            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            if (self.FireSeverityIsDetected == 0):
                self.nextStateNumber = 0b01001
        
        #01001
            #State = "Attending"
            #Description = "Waiting in zone"
            #UGV2to2Ack = None
            #Transition to 01010:
                #GO = 0
        elif (self.currentStateNumber == 0b01001):
            self.state = "Attending"
            self.stateDescription = "Waiting in zone"
            #wait

            if (self.GO == 0):
                self.nextStateNumber = 0b01010
            else:
                self.nextStateNumber = 0b00110


        #01010
            #State = "Transit"
            #Description = "Return to centre"
            #UGV2to2Ack = None
            #transition to 000000
        elif (self.currentStateNumber == 0b01010):
            self.state = "Transit"
            self.stateDescription = "Return to centre"
            self.nextStateNumber = 0b0000

        #01100
            #State = "Attending"
            #Description = "Attend to the other zone if not responsive"
            #UGV2to2Ack = None
            #Transition to 01101:
                #each clock cycle
        elif (self.currentStateNumber == 0b01100):
            self.state = "Attending"
            self.stateDescription = "Attend to other zone if not responsive"
            self.nextStateNumber = 0b01101

        #01101
            #State = "Transit"
            #Description = "Check every zone"
            #UGV2to2Ack = None
            #Transition to 01110:
                #next clock cycle
        elif (self.currentStateNumber == 0b01101):
            self.state = "Transit"
            self.stateDescription = "Check every zone"
            self.nextStateNumber = 0b01110

        #01110:
            #State = "Idle"
            #Description = "Create two zone policy"
            #UGV2to2Ack = None
            #Transition to 00101:
                #Next clock cycle
        elif (self.currentStateNumber == 0b01110):
            self.state = "Idle"
            self.stateDescription = "Create two zone policy"
            self.nextStateNumber = 0b00101
            
        #01111:
        #State = "Attending"
        #Description = "Receive Message Interrupt"
        #UGV2to2Ack = None
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