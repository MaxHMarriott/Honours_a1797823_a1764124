import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int16MultiArray
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from rclpy.qos import qos_profile_sensor_data
from custom_msgs.msg import FireSeverity as FireSeverityMsg
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
import numpy
import math
from enum import Enum
import cv2


class UGV1Main(Node):

    def __init__(self):
        super().__init__("UGV1Main")

        #define possible states of UGV:
        #self.State = Enum('State', ['Transit','Attending', 'Idle', 'Waiting','Do Not Disturb'])
        self.state = "Idle"
        #Transit = Heading to a specific location
        #Attending = Attending to a given fire
        #Idle = Is stationary and not completing a given task
        #Waiting = Waiting for action of other robots
        #DND = Will not respond to other robots.
        Publisher_name = '/UGV1FireSeverity'
        
        self.x = 0.0; #this will be the x coodinate of the agent retrieved from the navigation node.
        self.y = 0.0; #this will be the y coodinate of the agent retrieved from the navigation node.
        self.publisher = self.create_publisher(FireSeverityMsg,Publisher_name,10)
        self.publisher2 = self.create_publisher(Point,"/poseOrder",10) #publisher to test the navigation system (for testing purposes)
        self.state_publisher = self.create_publisher(String,"/UGV1State",10)
        self.LEDLocationsTopic = self.create_subscription(LEDLocationsMsg,'/LEDLocations',self.LED_message, qos_profile_sensor_data)
        self.subscription = self.create_subscription(Int16MultiArray,"/UGV1Detections",self.detections_message, qos_profile_sensor_data)
        self.FireSeverity= FireSeverityMsg()
        self.timer_period = 0.5
        self.orderCount = 0 #for testing purposes
        self.i = 0
        #state logic
        self.stateDescription = "Idle" #description of the state
        self.currentStateNumber = 0b00 #current state number
        self.nextStateNumber = 0b00 #next state number
        self.CommsTimeoutUAV = 0
        self.CommsTimeoutUGV = 0
        self.timer = self.create_timer(self.timer_period,self.timer_callback)

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

    #This function writes a frame to the camerapublisher topic every time it runs    
    def timer_callback(self):
        self.publisher.publish(self.FireSeverity)
        state_topic = String()
        state_topic.data = self.state
        self.state_publisher.publish(state_topic)
        self.get_logger().info('Publishing Severity locations, state and movement order')
        self.orderCount = self.orderCount + 1 #for testing purposes
        if (self.orderCount >= 60):
            self.state = "Transit"
            order = Point()
            order.x = 1.0
            order.y = 1.0
            order.z = 0.0
        else:
            self.state = "Transit"
            order = Point()
            order.x = -1.0
            order.y = 1.0
            order.z = 0.0
        if (self.orderCount >= 120):
            self.orderCount = 0
        self.publisher2.publish(order)
        print(order.x)
        #self.stateMachine()
     
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

    def stateMachine(self):

        #create local counter tUAV

        #This state = next state

        self.currentStateNumber = self.nextStateNumber

        #00000
            #state = "Idle"
            #description = "Idle"
            #UGV1to2Ack = None
            #Transition to 00001 if:
                #LEDDetected = 1 or CommsTimeoutUAV = 1

        if (self.currentStateNumber == bx00000):
            self.state = "Idle"
            self.stateDescription = "Idle"
            if ((self.LEDLocations.isled1 == true) or (self.CommsTimeoutUAV)):
                self.nextStateNumber = b0x01

            


        #00001
            #state = "Idle"
            #description = "Proposing Policy"
            #UGV1to2Ack = "Hey"
            #Transition to 01100 if:
                #CommsTimeoutUAV = 1
            #Transition to 00010 if:
                #LEDDetected = 1 and CommsTimeoutUAV = 1
            #Transition to 00000 if:
                #LEDDetected = 0 and CommsTimeoutUAV = 0
                
        
        #00010
            #State = "Idle"
            #Description = "Receiving Policy"
            #UGV1to2Ack = "Ack" 
            #Transition to 01100 if:
                #CommsTimeoutUAV= 1 or CommsTimeoutUGV = 1
            #Transition to 00011 if:
                #CommsTimeoutUAV = 0 and CommsTimeoutUGV = 0

        #00011
            #State = "Waiting"
            #Description = "Waiting for answer back from UGV2 (seeing if UGV2 Approves)"
            #UGV1to2Ack = None 
            #Transition to 00100:
                #Policy Accepted by UGV1
            #Transition to 01011:
                #Policy Rejected by UGV1 and UGV2To1Ack = yes
            #Transition to 00000:
                #LEDDetected = 0

        #00100
            #State = "Waiting"
            #Description = "Received policy and content"
            #UGV1to2Ack = "Yes" 
            #Transition to 00101:
                #UGV2to1Ack = Ack
            #Transition to 01110:
                #CommsTimeoutUGV=1

        #00101
            #State = "Transit"
            #Description = "Moving"
            #UGV1to2Ack = "Ack"
            #Transition to 00110:
                #UGV arrives at waypoint
            #Transition to 01111:
                #UGV1Jump = 1

        #00110
            #State = "Attending"
            #Description = "Reporting LED Intensity"
            #UGV1to2Ack = None 
            #Transition to 0111:
                #100ms delay
            
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

        #01000
            #State = "Transit"
            #Description = "Going to the other fire"
            #UGV1to2Ack = None
            #Transition to 01010:
                #GO=0
            #Transition to 01001:
                #Fire is extinguished
        
        #01001
            #State = "Attending"
            #Description = "Waiting in zone"
            #UGV1to2Ack = None
            #Transition to 01010:
                #GO = 0

        #01010
            #State = "Transit"
            #Description = "Return to centre"
            #UGV1to2Ack = None
            #transition to 000000

        #01100
            #State = "Attending"
            #Description = "Attend to the other zone if not responsive"
            #UGV1to2Ack = None
            #Transition to 01101:
                #each clock cycle

        #01101
            #State = "Transit"
            #Description = "Check every zone"
            #UGV1to2Ack = None
            #Transition to 01110:
                #next clock cycle

        #01110:
            #State = "Idle"
            #Description = "Create two zone policy"
            #UGV1to2Ack = None
            #Transition to 00101:
                #Next clock cycle
            
        #01111:
        #State = "Attending"
        #Description = "Receive Message Interrupt"
        #UGV1to2Ack = None

        #10000:
            #State = "DND"
            #Description = "DND"

def main (args=None):
    rclpy.init(args=args)
    
    UGV = UGV1Main()
    
    print('Node: UGV1Main has been created')

    rclpy.spin(UGV)

    UGV.destroy_node()

    rclpy.shutdown()
