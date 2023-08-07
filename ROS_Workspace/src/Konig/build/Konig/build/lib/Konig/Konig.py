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

display = tk.Tk()
display.title("Konig")

#Konig is a UI based monitoring app for the ROS vision communication network

class Konig(Node):

    def UAVDetections(self,data):
        self.UAVDetections_data = data.data
        self.UAVDetections_time = time()

    def __init__(self):
        super().__init__("Konig")
        self.br = CvBridge()
        #self.subscription = self.create_subscription(Float32MultiArray,"/UAVDetections",self.UAVDetections, qos_profile_sensor_data)
        #self.subscription = self.create_subscription(Float32MultiArray,"/UAVDetections",self.UAVDetections, qos_profile_sensor_data)
        self.root = tk.Tk()
        self.view = DisplayData(self.root)
        #img = Image.open("Feed1.png")
        #l0 = tk.Label(self.root, text="UGV1 Camera Feed", font=("Arial", 15))
        #l1 = tk.Label(self.root, text="UGV2 Camera Feed", font=("Arial", 15))
        #l2 = tk.Label(self.root, text="UAV Camera Feed", font=("Arial", 15))
        #img2 = Image.open("Feed2.png")
        #img3 = Image.open("Feed2.png")
        #img = img.resize([480,270])
        #img2 = img2.resize([480,270])
        #img3 = img2.resize([480,270])
        #img = ImageTk.PhotoImage(img)
        #img2 = ImageTk.PhotoImage(img2)
        #img3 = ImageTk.PhotoImage(img3)
        #view2 = tk.Label(root, image = img)
        #view3 = tk.Label(root, image = img2)
        #view4 = tk.Label(root, image = img3)
        self.view.pack(side="left", fill="both", expand=True)
        #l0.pack(side="top", fill="both", expand=True)
        #view2.pack(side="top", fill="both", expand=True)
        #l1.pack(side="top", fill="both", expand=True)
        #view3.pack(side="top", fill="both", expand=True)
        #l2.pack(side="top", fill="both", expand=True)
        #view4.pack(side="top", fill="both", expand=True)
        #view2.pack(side="right", fill="both", expand = True)
        self.update_display_period = 0.5
        self.timer = self.create_timer(self.update_display_period,self.update_Display)
        self.root.update()
        self.root.update_idletasks()
        #define subscriptions
        self.subscription = self.create_subscription(String, "/UGV1State",self.UGV1State_Update, qos_profile_sensor_data)
        self.subscription2 = self.create_subscription(LEDLocationsMsg, "/LEDLocations",self.LEDLocations_Update, qos_profile_sensor_data)
        self.subscription3 = self.create_subscription(String, "/UAVState",self.UAVState_Update, qos_profile_sensor_data)
        self.subscription4 = self.create_subscription(Float32MultiArray,"/UAVDetections",self.UAVDetections_Update, qos_profile_sensor_data)
        self.subscription5 = self.create_subscription(Image, "/UAVFrame",self.UAVFrame_Update, qos_profile_sensor_data)
        #defining times:
        self.UGV1State_time = time()
        self.LEDLocations_time = time()
        self.UAVState_time = time()
        self.UAVDetections_time = time()

        #root2.mainloop()        
        #creating widgets:

    def update_Display(self):
        self.current_time = time()
        self.update_Times()
        #self.view.pack(side="left", fill="both", expand=True)
        self.root.update_idletasks()
        #self.root.update()

    #updates:
    def UGV1State_Update(self,data):
        self.UGV1State_time = time()
        self.view.b21.config(text=data.data)

    def LEDLocations_Update(self,data):
        self.LEDLocations_time = time()
        a = 0
        if (data.isled1 == 1):
            msg1 = "[" + str(data.led1x) + "," + str(data.led1y) + "]"
            a = a+1
        else:
            msg1 = "Not detected"
        if (data.isled2 == 1):
            msg2 = "[" + str(data.led2x) + "," + str(data.led2y) + "]" 
            a = a+1
        else:
            msg2 = "Not detected"

        self.view.c11.config(text=msg1)
        self.view.c21.config(text=msg2)

    def UAVState_Update(self,data):
        self.UAVState_time = time()
        self.view.b41.config(text=data.data)

    def UAVDetections_Update(self,data):
        print("test")
        self.UAVDetections_time = time()
        self.view.c61.config(text=str(data.data))

    def update_Times(self):
        self.view.t4.config(text=str(round(self.current_time-self.UAVState_time,2)))
        self.view.t6.config(text=str(round(self.current_time-self.UGV1State_time,2)))
        self.view.t13.config(text=str(round(self.current_time-self.LEDLocations_time,2)))
        self.view.t14.config(text=str(round(self.current_time-self.LEDLocations_time,2)))
        self.view.t18.config(text=str(round(self.current_time-self.UAVDetections_time,2)))

    def UAVFrame_Update(self,data):
        self.UAVFrame_time = time()
        self.view.b17.config(text="Publishing")
        
class DisplayData(tk.Frame):
    def __init__(self, root):

        #fake data:
        self.UGV1batteryPercentage = "Unknown"
        self.UGV1batteryPercentaget = "Unknown"
        self.UGV2batteryPercentage = "Unknown"
        self.UGV2batteryPercentaget = "Unknown"
        self.UGV1MainStatus = "Not Working"
        self.UGV2MainStatus = "Not Working"
        self.UAVMainStatus = "Not Working"
        self.UGV1VisionStatus = "Not Working"
        self.UGV2VisionStatus = "Not Working"
        self.UAVVisionStatus = "Not Working"
        self.UGV1ProcessingStatus = "Not Working"
        self.UGV2ProcessingStatus = "Not Working"
        self.UAVProcessingStatus = "Not Working"
        self.UGV1ProcessingStatus = "Not Working"
        self.UGV2ProcessingStatus = "Not Working"
        self.UAVProcessingStatus = "Not Working"
        self.LED1Locations = "[" + "Unknown"
        self.LED2Locations = "[" + "Unknown"
        self.UAVFrame = "Not Publishing"
        self.UGV1Frame = "Not Publishing"
        self.UGV2Frame = "Not Publishing"
        self.UAVDetections = "[" + "Unknown"
        self.UGV1DetectionStream = "Not Publishing"
        self.UGV2DetectionStream = "Not Publishing"
        self.UAVDetectionStream = "Not Publishing"


        self.x = 1.2
        self.y = 2.2

        tk.Frame.__init__(self, root)

        self.Display()
    
    def Display(self):

        #formatting
        tk.Frame.grid(self,row = 5, column = 3)
        self.columnconfigure([0,1,2], minsize=300)
        #Power
        self.a1 = tk.Label(self, text="Parameter:", font=("Arial", 20))
        self.a1.grid(row=0, column=0)
        self.a2 = tk.Label(self, text="Status or value:", font=("Arial", 20))
        self.a2.grid(row=0, column=1)
        self.t1 = tk.Label(self, text="Last Update:", font=("Arial", 20))
        self.t1.grid(row=0, column=2)

        self.a3 = tk.Label(self, text="Battery Percentages:", font=("Arial", 15))
        self.a3.grid(row=1, column=0)

        self.a4 = tk.Label(self, text="UGV1 Battery Percentage:", font=("Arial", 13))
        self.a4.grid(row=2, column=0)
        self.a5 = tk.Label(self,text = (self.UGV1batteryPercentage) + "%", font=("Arial", 13))
        self.a5.grid(row=2, column=1)
        self.t2 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t2.grid(row=2, column=2)
        self.a8 = tk.Label(self, text="UGV2 Battery Percentage:", font=("Arial", 13))
        self.a8.grid(row=3, column=0)
        self.t3 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t3.grid(row=3, column=2)
        self.a9 = tk.Label(self,text = (self.UGV2batteryPercentage) + "%", font=("Arial", 13))
        self.a9.grid(row=3, column=1)

        self.b1 = tk.Label(self, text="Nodes:", font=("Arial", 13))
        self.b1.grid(row=4, column=0)

        self.b2 = tk.Label(self, text="UGV1MainStatus:" , font=("Arial", 13))
        self.b21 = tk.Label(self,text=str(self.UGV1MainStatus), font=("Arial", 13))
        self.b2.grid(row=5, column=0)
        self.b21.grid(row=5, column=1)
        self.t4 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t4.grid(row=5, column=2)


        self.b3 = tk.Label(self, text="UGV2MainStatus:", font=("Arial", 13))
        self.b31 = tk.Label(self,text=str(self.UGV2MainStatus), font=("Arial", 13))
        self.b3.grid(row=6, column=0)
        self.b31.grid(row=6, column=1)
        self.t5 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t5.grid(row=6, column=2)

        self.b4 = tk.Label(self, text="UAVMainStatus:", font=("Arial", 13))
        self.b41 = tk.Label(self,text=str(self.UAVMainStatus), font=("Arial", 13))
        self.b4.grid(row=7, column=0)
        self.b41.grid(row=7, column=1)
        self.t6 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t6.grid(row=7, column=2)

        self.b5 = tk.Label(self, text="UGV1VisionStatus: ", font=("Arial", 13))
        self.b51 = tk.Label(self,text=str(self.UGV1VisionStatus), font=("Arial", 13))
        self.b5.grid(row=8, column=0)
        self.b51.grid(row=8, column=1)
        self.t7 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t7.grid(row=8, column=2)

        self.b6 = tk.Label(self, text="UGV2VisionStatus:", font=("Arial", 13))
        self.b61 = tk.Label(self,text=str(self.UGV2VisionStatus), font=("Arial", 13))
        self.b6.grid(row=9, column=0)
        self.b61.grid(row=9, column=1)
        self.t8 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t8.grid(row=9, column=2)

        self.b7 = tk.Label(self, text="UAVVisionStatus:", font=("Arial", 13))
        self.b71 = tk.Label(self, text=str(self.UAVVisionStatus), font=("Arial", 13))
        self.b7.grid(row=10, column=0)
        self.b71.grid(row=10, column=1)
        self.t9 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t9.grid(row=10, column=2)

        self.b8 = tk.Label(self, text="UGV1ProcessingStatus:", font=("Arial", 13))
        self.b81 = tk.Label(self,text=str(self.UGV1ProcessingStatus), font=("Arial", 13))
        self.b8.grid(row=11, column=0)
        self.b81.grid(row=11, column=1)
        self.t10 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t10.grid(row=11, column=2)

        self.b9 = tk.Label(self, text="UGV2ProcessingStatus:", font=("Arial", 13))
        self.b91 = tk.Label(self,text=str(self.UGV2ProcessingStatus), font=("Arial", 13))
        self.b9.grid(row=12, column=0)
        self.b91.grid(row=12, column=1)
        self.t11 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t11.grid(row=12, column=2)

        self.b10 = tk.Label(self, text="UAVProcessingStatus:", font=("Arial", 13))
        self.b101 = tk.Label(self,text=str(self.UAVProcessingStatus), font=("Arial", 13))
        self.b10.grid(row=13, column=0)
        self.b101.grid(row=13, column=1)
        self.t12 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t12.grid(row=13, column=2)

        self.c1 = tk.Label(self, text="Topics:", font=("Arial", 15))
        self.c1.grid(row=14, column=0)

        self.c1 = tk.Label(self, text="LED1Locations:", font=("Arial", 13))
        self.c11 = tk.Label(self, text=self.LED1Locations, font=("Arial", 13))
        self.c1.grid(row=15, column=0)
        self.c11.grid(row=15, column=1)
        self.t13 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t13.grid(row=15, column=2)

        self.c2 = tk.Label(self, text="LED2Locations:", font=("Arial", 13))
        self.c21 = tk.Label(self, text=self.LED2Locations, font=("Arial", 13))
        self.c2.grid(row=16, column=0)
        self.c21.grid(row=16, column=1)
        self.t14 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t14.grid(row=16, column=2)


        self.c3 = tk.Label(self, text="UAVFrame:", font=("Arial", 13))
        self.c31 = tk.Label(self, text=self.UAVFrame, font=("Arial", 13))
        self.c3.grid(row=17, column=0)
        self.c31.grid(row=17, column=1)
        self.t15 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t15.grid(row=17, column=2)

        self.c4 = tk.Label(self, text="UGV1Frame:", font=("Arial", 13))
        self.c41 = tk.Label(self, text=self.UGV1Frame, font=("Arial", 13))
        self.c4.grid(row=18, column=0)
        self.c41.grid(row=18, column=1)
        self.t16 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t16.grid(row=18, column=2)

        self.c5 = tk.Label(self, text="UGV2Frame:", font=("Arial", 13))
        self.c51 = tk.Label(self, text=self.UGV2Frame, font=("Arial", 13))
        self.c5.grid(row=19, column=0)
        self.c51.grid(row=19, column=1)
        self.t17 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t17.grid(row=19, column=2)

        self.c6 = tk.Label(self, text="UAVDetections:", font=("Arial", 13))
        self.c61 = tk.Label(self, text=self.UAVDetections, font=("Arial", 13))
        self.c6.grid(row=20, column=0)
        self.c61.grid(row=20, column=1)
        self.t18 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t18.grid(row=20, column=2)

        self.c7 = tk.Label(self, text="UGV1VideoStream:", font=("Arial", 13))
        self.c71 = tk.Label(self, text=self.UGV1DetectionStream, font=("Arial", 13))
        self.c7.grid(row=21, column=0)
        self.c71.grid(row=21, column=1)
        self.t19 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t19.grid(row=21, column=2)

        self.c8 = tk.Label(self, text="UGV2VideoStream:", font=("Arial", 13))
        self.c81 = tk.Label(self, text=self.UGV2DetectionStream, font=("Arial", 13))
        self.c8.grid(row=22, column=0)
        self.c81.grid(row=22, column=1)
        self.t20 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t20.grid(row=22, column=2)

        self.c8 = tk.Label(self, text="UAVVideoStream:", font=("Arial", 13))
        self.c81 = tk.Label(self, text=self.UAVDetectionStream, font=("Arial", 13))
        self.c8.grid(row=23, column=0)
        self.c81.grid(row=23, column=1)
        self.t21 = tk.Label(self, text="-1", font=("Arial", 13))
        self.t21.grid(row=23, column=2)

        #frame2 = tk.Frame2(self,width=50, height=50, bg="yellow")
        #frame2.pack(fill=tk.Y, side=tk.RIGHT)

class DisplayCameras(tk.Frame):
    def __init__(self, root):
        tk.Frame.__init__(self, root)
        img = ImageTk.PhotoImage(Image.open("Feed1.png"))
        img2 = ImageTk.PhotoImage(Image.open("Feed2.png"))
        img3 = ImageTk.PhotoImage(Image.open("Feed3.png"))
        #Power
        #a1 = tk.Label(self, text="Camera Feeds:", font=("Arial", 20))
        #a1.grid(row=0, column=0)
        #a2 = tk.Label(self, image = img)
        #a2.grid(row=1, column=0)

def main (args=None):
    rclpy.init(args=args)
    
    KonigInstance = Konig()
    
    print('Konig has been created')

    rclpy.spin(KonigInstance)

    KonigInstance.destroy_node()

    rclpy.shutdown()
