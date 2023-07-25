import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int16MultiArray
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
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
        #LED1_name = '/LED1Location'
        #LED2_name = '/LED2Location'
        Publisher_name = '/UGV1FireSeverity'
        self.x = 0.0; #this will be the x coodinate of the agent retrieved from the navigation node.
        self.y = 0.0; #this will be the y coodinate of the agent retrieved from the navigation node.
        self.publisher = self.create_publisher(FireSeverityMsg,Publisher_name,10)
        self.LEDLocationsTopic = self.create_subscription(LEDLocationsMsg,'/LEDLocations',self.LED_message, qos_profile_sensor_data)
        self.subscription = self.create_subscription(Int16MultiArray,"/UGV1Detections",self.detections_message, qos_profile_sensor_data)
        self.FireSeverity= FireSeverityMsg()
        self.timer_period = 0.5
        self.i = 0
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
        #self.publisher.publish(self.LED1)
        #self.publisher2.publish(self.LED2)
        self.publisher.publish(self.FireSeverity)
        self.get_logger().info('Publishing Severity locations')
        
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

        
def main (args=None):
    rclpy.init(args=args)
    
    UGV = UGV1Main()
    
    print('Node: UGV1Main has been created')

    rclpy.spin(UGV)

    UGV.destroy_node()

    rclpy.shutdown()
