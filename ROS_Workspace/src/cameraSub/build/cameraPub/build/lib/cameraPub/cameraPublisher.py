import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import cv2


class CameraPublisher(Node):

     def __init__(self):
        super().__init__("camera_topic")
        print('This has run')
        topic_name = 'camera_topic'
        #self.publisher = self.create_publisher(String,topic_name,10)
        self.publisher = self.create_publisher(Image,topic_name,10)
        print('Topic: ' + topic_name)
        self.timer_period = 0.1
        self.i = 0
        self.timer = self.create_timer(self.timer_period,self.timer_callback)
        self.cap = cv2.VideoCapture(0)
        self.br = CvBridge()
        
     def timer_callback(self):
          #ret, frame = self.cap.read()
          while True:
               print("This has run")
               ret, frame = self.cap.read(cv2.CAP_V4L2)
               print("This has run 2")
               #frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
               frame = cv2.resize(frame, (120, 80))
               #framecount = framecount + 1
               #opencv code goes here
               #frame = visionProcessing(frame)
               #cv2.imshow('Input', frame)
               #print("Frame Displayed")
               #c = cv2.waitKey(1)
               self.publisher.publish(self.br.cv2_to_imgmsg(frame))
               self.get_logger().info('Publishing video frame')
  		
  	#hello world example:      
        #msg = String()
        #msg.data = 'Hello World: %d' % self.i        
        #self.publisher.publish(msg)
        #self.get_logger().info('Publishing: "%s"' % msg.data)
        #self.i = self.i + 1

def main (args=None):
    rclpy.init(args=args)

    #camera_publisher = rclpy.create_node('CameraPublisher')
    
    camera_publisher = CameraPublisher() #maybe rename to cam1 (camera_publisher maybe bad name)
    
    print('Node: cameraPublisher has been created')

    rclpy.spin(camera_publisher)

    camera_publisher.destroy_node()

    rclpy.shutdown()
