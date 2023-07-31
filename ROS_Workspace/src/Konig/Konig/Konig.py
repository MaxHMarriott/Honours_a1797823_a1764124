import rclpy
from time import time
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int16MultiArray
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
import tkinter as tk
from tkinter import ttk
import numpy
import math
from enum import Enum
import cv2

display = tk.Tk()
display.title("Konig")

#Konig is a UI based monitoring app for the ROS vision communication network

class Konig(Node):

    def UAVDetections(self,data):
        self.UAVDetections_data = data.data
        self.UAVDetections_time = time()

    def __init__(self):
        super().__init__("Konig")
        self.subscription = self.create_subscription(Float32MultiArray,"/UAVDetections",self.UAVDetections, qos_profile_sensor_data)
        self.current_time = time()
        self.UAVDetections_data = [-99.0,-99.0]
        self.UAVDetections_time = self.current_time
        
        self.update_time()
        #creating widgets:

    def update_time(self):
        self.current_time = time()




def main (args=None):
    rclpy.init(args=args)
    
    KonigInstance = Konig()
    
    print('Konig has been created')

    rclpy.spin(KonigInstance)

    KonigInstance.destroy_node()

    rclpy.shutdown()
