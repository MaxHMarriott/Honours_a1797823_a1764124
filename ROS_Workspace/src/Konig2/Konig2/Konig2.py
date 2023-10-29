import rclpy
from time import time
from time import sleep
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int16MultiArray
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
from custom_msgs.msg import FireSeverity as FireSeverityMsg
import tkinter as tk
from tkinter import ttk
import numpy
import math
from enum import Enum
import cv2
import random
import tkinter as tk
import os
from PIL import ImageTk, Image  
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from std_msgs.msg import Float32
import cv2
from std_msgs.msg import Float32MultiArray
import numpy
import math
from enum import Enum
import csv
import os

display = tk.Tk()
display.title("Konig")

#Konig is a UI based monitoring app for the ROS vision communication network

class Konig(Node):

    def __init__(self):
      super().__init__("Konig")
      self.UGV1RAMSub= self.create_subscription(Float32,"/UGV1RAM",self.getUGV1RAM, qos_profile_sensor_data)
      self.UGV1CPUSub= self.create_subscription(Float32,"/UGV1CPU",self.getUGV1CPU, qos_profile_sensor_data)
      self.UGV2RAMSub= self.create_subscription(Float32,"/UGV2RAM",self.getUGV2RAM, qos_profile_sensor_data)
      self.UGV2CPUSub= self.create_subscription(Float32,"/UGV2CPU",self.getUGV2CPU, qos_profile_sensor_data)
      self.UAVRAMSub= self.create_subscription(Float32,"/UAVRAM",self.getUAVRAM, qos_profile_sensor_data)
      self.UAVCPUSub= self.create_subscription(Float32,"/UAVCPU",self.getUAVCPU, qos_profile_sensor_data)
      self.UGV1StateSub= self.create_subscription(Float32,"/UGV1State",self.getUGV1State, qos_profile_sensor_data)
      self.UGV2StateSub= self.create_subscription(Float32,"/UGV2State",self.getUGV2State, qos_profile_sensor_data)
      self.UGV1RAM = -1.0
      self.UGV1CPU = -1.0
      self.UGV2RAM = -1.0
      self.UGV2CPU = -1.0
      self.UAVRAM = -1.0
      self.UAVCPU = -1.0
      self.UGV1State = "idle"
      self.UGV2State = "idle"
      self.t0 = time()

      with open("trialrecord.csv", "w") as f:
        writer = csv.writer(f)
        writer.writerows([{"Trial Record"}])
        writer.writerows([{"Time, UGV1 CPU, UGV2 CPU,UGV1 CPU,UAV CPU,UGV1 RAM,UGV2 RAM,UAV RAM"}])
        pass
      self.timer_period = 0.25
      self.timer = self.create_timer(self.timer_period,self.timer_callback)
        
    def timer_callback(self):
      t = time()
      with open("trialrecord.csv", "a", newline="") as f:
        writer = csv.writer(f)
        line = [(t-self.t0),(self.UGV1CPU),(self.UGV2CPU),(self.UAVCPU),(self.UGV1RAM),(self.UGV2RAM),(self.UAVRAM),(self.UGV1State),(self.UGV2State)]

        writer.writerows([line])
    

       
        
    def getUGV1RAM(self,data):
      self.UGV1RAM = data.data
    def getUGV1CPU(self,data):
       self.UGV1CPU = data.data
    def getUGV2RAM(self,data):
       self.UGV2RAM = data.data
    def getUGV2CPU(self,data):
       self.UGV2CPU = data.data
    def getUAVRAM(self,data):
       self.UAVRAM = data.data
    def getUAVCPU(self,data):
       self.UAVCPU = data.data
    def getUGV1State(self,data):
       self.UGV1State = data.data
    def getUGV2State(self,data):
       self.UGV2State = data.data
       


 
def main (args=None):
    rclpy.init(args=args)
    
    KonigInstance = Konig()
    
    print('Konig has been created')

    rclpy.spin(KonigInstance)

    KonigInstance.destroy_node()

    rclpy.shutdown()
