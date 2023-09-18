import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from std_msgs.msg import Int16MultiArray
import numpy
import math
from enum import Enum
import cv2


class CameraSubscriber(Node):	

        def __init__(self):
                super().__init__("UGV1Vision")
                print('This has run')
                topic_name = '/UGV1Frame'
                self.subscription = self.create_subscription(Image, topic_name,self.subscribe_message, qos_profile_sensor_data)
                self.publisher = self.create_publisher(Int16MultiArray,"/UGV1Detections",10)
                self.UGV1Returns= Int16MultiArray()
                self.UGV1Returns.data= [0,0,0]
                self.br = CvBridge()
                print("Creating vision pipeline")
                self.LED_detect = VisionDetect() #creating a pipeline for finding LEDs
                print("Vision pipeline completed")
                print('Topic: ' + topic_name)

        def subscribe_message(self,data):
                print('displaying image')
                current_frame = self.br.imgmsg_to_cv2(data)
        #perform processing on captured frame
                image = self.imageProcess(current_frame)
                #displaying image
                cv2.imshow("Camera",image)

                cv2.waitKey(1)

                return

        #function for performing image processing
        def imageProcess(self,image):
            self.LED_detect.process(image)
            RedCount = sum(sum(self.LED_detect.hsl_threshold_0_output))
            GreenCount = sum(sum(self.LED_detect.hsl_threshold_1_output))
            YellowCount = sum(sum(self.LED_detect.hsv_threshold_output))
            self.UGV1Returns.data = [int(RedCount), int(GreenCount), int(YellowCount)]
            self.publisher.publish(self.UGV1Returns)
            return image


class VisionDetect:
    
    def __init__(self):
        """initializes all values to presets or None if need to be set
        """

        #self.__hsl_threshold_0_input = source0
        self.__hsl_threshold_0_hue = [0.0, 50] #was [0, 20]
        self.__hsl_threshold_0_saturation = [120, 360] #was [96,255]
        self.__hsl_threshold_0_luminance = [90, 225] #was [0, 124]

        self.hsl_threshold_0_output = None

        #self.__hsl_threshold_1_input = self.blur_output
        self.__hsl_threshold_1_hue = [40.46762589928058, 98.60068259385666]
        self.__hsl_threshold_1_saturation = [90, 180]
        self.__hsl_threshold_1_luminance = [50, 180]

        self.hsl_threshold_1_output = None

        #self.__hsv_threshold_input = self.blur_output
        self.__hsv_threshold_hue = [24, 49]
        self.__hsv_threshold_saturation = [41, 150] #was 25,70
        self.__hsv_threshold_value = [133, 255.0] #was 208

        self.hsv_threshold_output = None


    def process(self, source0):
        """
        Runs the pipeline and sets all outputs to new values.
        """


        # Step HSL_Threshold0: Find red LED
        self.__hsl_threshold_0_input = source0
        (self.hsl_threshold_0_output) = self.__hsl_threshold(self.__hsl_threshold_0_input, self.__hsl_threshold_0_hue, self.__hsl_threshold_0_saturation, self.__hsl_threshold_0_luminance)
        #cv2.imshow("Red LED find",self.hsl_threshold_0_output)

        # Step HSL_Threshold1: Find green LED
        self.__hsl_threshold_1_input = source0
        (self.hsl_threshold_1_output) = self.__hsl_threshold(self.__hsl_threshold_1_input, self.__hsl_threshold_1_hue, self.__hsl_threshold_1_saturation, self.__hsl_threshold_1_luminance)
        #cv2.imshow("Green LED find",self.hsl_threshold_1_output)

        # Step HSV_Threshold0: Find yellow LED
        self.__hsv_threshold_input = source0
        (self.hsv_threshold_output) = self.__hsv_threshold(self.__hsv_threshold_input, self.__hsv_threshold_hue, self.__hsv_threshold_saturation, self.__hsv_threshold_value)
        #cv2.imshow("Yellow LED find",self.hsv_threshold_output)

    @staticmethod
    def __hsl_threshold(input, hue, sat, lum):
        """Segment an image based on hue, saturation, and luminance ranges.
        Args:
            input: A BGR numpy.ndarray.
            hue: A list of two numbers the are the min and max hue.
            sat: A list of two numbers the are the min and max saturation.
            lum: A list of two numbers the are the min and max luminance.
        Returns:
            A black and white numpy.ndarray.
        """
        out = cv2.cvtColor(input, cv2.COLOR_BGR2HLS)
        return cv2.inRange(out, (hue[0], lum[0], sat[0]),  (hue[1], lum[1], sat[1]))

    @staticmethod
    def __hsv_threshold(input, hue, sat, val):
        """Segment an image based on hue, saturation, and value ranges.
        Args:
            input: A BGR numpy.ndarray.
            hue: A list of two numbers the are the min and max hue.
            sat: A list of two numbers the are the min and max saturation.
            lum: A list of two numbers the are the min and max value.
        Returns:
            A black and white numpy.ndarray.
        """
        out = cv2.cvtColor(input, cv2.COLOR_BGR2HSV)
        return cv2.inRange(out, (hue[0], sat[0], val[0]),  (hue[1], sat[1], val[1]))


#BlurType = Enum('BlurType', 'Box_Blur Gaussian_Blur Median_Filter Bilateral_Filter')



def main (args=None):
    rclpy.init(args=args)

    #camera_subscriber = rclpy.create_node('Camerasubscriber')
    
    camera_subscriber = CameraSubscriber() #maybe rename to cam1 (camera_subscriber maybe bad name)
    
    print('Node: camerasubscriber has been created')

    rclpy.spin(camera_subscriber)

    camera_subscriber.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
        main()