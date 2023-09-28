import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Float32MultiArray
from std_msgs.msg import Int16
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from rclpy.qos import qos_profile_sensor_data
from custom_msgs.msg import LEDLocations as LEDLocationsMsg
from custom_srvs.srv import Policy
import numpy
import math
from enum import Enum
import cv2
import serial
from random import random
import time


class UAVMain(Node):

    def __init__(self):
        super().__init__("UAVMain")
        #LED1_name = '/LED1Location'
        #LED2_name = '/LED2Location'
        LED_name = '/LEDLocations'
        self.state = String()
        self.state.data = "Idle"
        self.sOut = 0

        #self.publisher = self.create_publisher(String,topic_name,10)
        #self.publisher = self.create_publisher(Float32MultiArray,LED1_name,10)
        #self.publisher2 = self.create_publisher(Float32MultiArray,LED2_name,10)
        self.publisher = self.create_publisher(LEDLocationsMsg,LED_name,10)
        self.publisher2 = self.create_publisher(String,"/UAVState",10)
        self.subscription = self.create_subscription(Float32MultiArray,"/UAVDetections",self.subscribe_message_UAVDetections, qos_profile_sensor_data)
        self.UGV1StateSubscription = self.create_subscription(String,"/UGV1State",self.subscribe_message_UGV1State, qos_profile_sensor_data)

        self.LEDLocations = LEDLocationsMsg()
        #self.LED1Location = [0.0,0.0,0.0]
        #self.LED2Location = [0.0,0.0,0.0]
        #self.LED1 = Float32MultiArray()
        #self.LED1.data = self.LED1Location
        #self.LED2 = Float32MultiArray()
        #self.LED2.data = self.LED1Location
        self.timer_period = 0.5
        self.timer_period = 60
        self.i = 0
        self.timer = self.create_timer(self.timer_period,self.timer_callback)

        #serial_port = '/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0'
        #baud_rate = 9600
        #self.ser = serial.Serial(serial_port, baud_rate,timeout=1)
        #self.timer = self.create_timer(self.timer_period,self.set_scenario) #timer for determining scenario
        #try:
       #     self.ser.write(f'{self.sOut}\n'.encode('utf-8'))
        #    data = self.ser.readline().decode('utf-8').strip()
       #     time.sleep(0.2)
       # except:
       #     print("COMMS ERROR")

    def subscribe_message_UGV1State(self,data):
        print("State of UGV1 Rover is: ")
        self.UGV1State = data.data
        print(self.UGV1State)

    def subscribe_message_UAVDetections(self,data):
        self.UAVDetections = data.data
        print(data)
        print("Determining state of LED")
        self.LEDLocations.isled1 = bool(0)
        self.LEDLocations.isled2 = bool(0)
        self.LEDState = self.determineLEDs()
        #self.LEDLocations.isled1 = self.LEDState[0]
        self.LEDLocations.led1 = self.LEDState[1]
        #self.LEDLocations.isled2 = (self.LEDState[3])
        self.LEDLocations.led2 = self.LEDState[3]
        #self.LED1.data = self.LEDState[0:3]
        print("LEDs:")
        print(self.LEDState)
        #self.LED2.data = self.LEDState[3:6]   

    #This function writes a frame to the camerapublisher topic every time it runs    
    def timer_callback(self):
        #self.publisher.publish(self.LED1)
        #self.publisher2.publish(self.LED2)
        self.publisher.publish(self.LEDLocations)
        self.publisher2.publish(self.state)
        self.get_logger().info('Publishing LED locations')

    def set_scenario(self):  
        self.sOut = self.sOut + 1
 #       try:
        self.ser.write(f'{self.sOut}\n'.encode('utf-8'))
        data = self.ser.readline().decode('utf-8').strip()
        time.sleep(0.2)
#        except:
 #           print("COMMS ERROR") 
        if (self.sOut >= 5):
            self.sOut = 0
       
    def determineLEDs(self):

        #location legend:
        #===================
        #Q1 = [0.5,1]
        #Q2 = [-0.5,1]
        #Q3 = [-0.5,-1]
        #Q4 = [0.5,-1]

        determinedLEDS = [0.0,0.0,0.0,0.0,0.0,0.0]
        threshold = 6500

        #returns from Processing node
        Q1 = self.UAVDetections[0]
        Q2 = self.UAVDetections[1]
        Q3 = self.UAVDetections[2]
        Q4 = self.UAVDetections[3]

        #now we determine which LED is on:
        lst = [["Q1",Q1],["Q2",Q2],["Q3",Q3],["Q4",Q4]]
        lst.sort(key=lambda lst:lst[1])
        lst = lst[::-1]
        #print(lst)

        #use this sorted list to get correct returns:
        if threshold <= lst[0][1]:
            self.LEDLocations.isled1 = bool(1)
            if lst[0][0] == "Q1":
                determinedLEDS[0:1] = [1,1]
            if lst[0][0] == "Q2":
                determinedLEDS[0:1] = [1,2]
            if lst[0][0] == "Q3":
                determinedLEDS[0:1] = [1,3]
            if lst[0][0] == "Q4":
                determinedLEDS[0:1] = [1,4]
        else:
            return determinedLEDS


        if threshold <= lst[1][1]:
            self.LEDLocations.isled2 = bool(1)
            if lst[1][0] == "Q1":
                determinedLEDS[2:3] = [1,1]
            if lst[1][0] == "Q2":
                determinedLEDS[2:3] = [1,2]
            if lst[1][0] == "Q3":
                determinedLEDS[2:3] = [1,3]
            if lst[1][0] == "Q4":
                determinedLEDS[2:3] = [1,4]
        else:
            return determinedLEDS

        return determinedLEDS
       
def main (args=None):
    rclpy.init(args=args)
    
    UAV = UAVMain()
    
    print('Node: UAVMain has been created')

    rclpy.spin(UAV)

    UAV.destroy_node()

    rclpy.shutdown()
