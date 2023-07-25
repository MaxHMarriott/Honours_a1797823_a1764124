import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import numpy
import math
from enum import Enum
import cv2


class UAVMain(Node):

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
        frame = cv2.resize(frame, (480, 360))
        self.publisher.publish(self.br.cv2_to_imgmsg(frame))
        self.get_logger().info('Publishing video frame')

def main (args=None):
    rclpy.init(args=args)
    
    UAV = UAVMain()
    
    print('Node: cameraPublisher has been created')

    rclpy.spin(UAV)

    camera_publisher.destroy_node()

    rclpy.shutdown()