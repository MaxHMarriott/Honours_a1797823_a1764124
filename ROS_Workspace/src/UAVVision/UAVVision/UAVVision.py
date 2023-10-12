import rclpy
import cv2
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import numpy
import math
from enum import Enum


class CameraPublisher(Node):

    def __init__(self):
        super().__init__("UAVVision")
        print('This has run')
        topic_name = '/UAVFrame'
        #self.publisher = self.create_publisher(String,topic_name,10)
        self.publisher = self.create_publisher(Image,topic_name,10)
        print('Topic: ' + topic_name)
        self.timer_period = 0.5
        self.i = 0
        self.timer = self.create_timer(self.timer_period,self.timer_callback)
        self.cap = cv2.VideoCapture(0)
        #self.cap.set(cv2.CV_CAP_PROP_FRAME_WIDTH, 320)
        #self.cap.set(cv2.CV_CAP_PROP_FRAME_HEIGHT, 240)
        self.cap.set(cv2.CAP_PROP_AUTO_EXPOSURE, 1)
        self.cap.set(cv2.CAP_PROP_EXPOSURE, 2) #debug was 10
        print("exposure is:")
        print(self.cap.get(cv2.CAP_PROP_EXPOSURE))
        self.br = CvBridge()


    #This function writes a frame to the camerapublisher topic every time it runs    
    def timer_callback(self):
        #ret, frame = self.cap.read()
        #while True:
        ret, frame = self.cap.read(cv2.CAP_V4L2)
        try:
        	frame = cv2.resize(frame, (360, 240))
            self.publisher.publish(self.br.cv2_to_imgmsg(frame))
            self.get_logger().info('Publishing video frame')
        except:
            print("Cannot print frame")

def main (args=None):
    rclpy.init(args=args)

    #camera_publisher = rclpy.create_node('CameraPublisher')
    
    camera_publisher = CameraPublisher() #maybe rename to cam1 (camera_publisher maybe bad name)
    
    print('Node: cameraPublisher has been created')

    rclpy.spin(camera_publisher)

    camera_publisher.destroy_node()

    rclpy.shutdown()