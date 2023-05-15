import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import numpy
import math
from enum import Enum
import cv2


class CameraPublisher(Node):

    def __init__(self):
        super().__init__("camera_topic")
        print('This has run')
        topic_name = 'camera_topic'
        #self.publisher = self.create_publisher(String,topic_name,10)
        self.publisher = self.create_publisher(Image,topic_name,10)
        print('Topic: ' + topic_name)
        self.timer_period = 0.2
        self.i = 0
        self.timer = self.create_timer(self.timer_period,self.timer_callback)
        self.cap = cv2.VideoCapture(0)
        self.br = CvBridge()
        self.vision_detect = VisionDetect() #creating a pipeline for finding LEDs

    #This function writes a frame to the camerapublisher topic every time it runs    
    def timer_callback(self):
        #ret, frame = self.cap.read()
        #while True:
               ret, frame = self.cap.read(cv2.CAP_V4L2)
               frame = cv2.resize(frame, (480, 360))
               self.publisher.publish(self.br.cv2_to_imgmsg(frame))
               self.get_logger().info('Publishing video frame')
               self.LED_search(frame)

    def LED_search(self,frame):
        #ret, frame = self.cap.read()
        #while True:
            self.vision_detect.process(frame)
            print("Detecting LEDS:")

            RedCount = sum(sum(self.vision_detect.hsl_threshold_0_output))
            GreenCount = sum(sum(self.vision_detect.hsl_threshold_1_output))
            YellowCount = sum(sum(self.vision_detect.hsv_threshold_output))
            
            Threshold = 10000

            if RedCount >= Threshold:
                print('Red LED Detected')
            
            
            if GreenCount >= Threshold:
                print('Green LED Detected')
            

            if YellowCount >= Threshold:
                print('Yellow LED Detected')
            


class VisionDetect:
    
    def __init__(self):
        """initializes all values to presets or None if need to be set
        """

        self.__blur_type = BlurType.Box_Blur
        self.__blur_radius = 7.2072072072072055

        self.blur_output = None

        self.__hsl_threshold_0_input = self.blur_output
        self.__hsl_threshold_0_hue = [0.0, 20.273037542662117]
        self.__hsl_threshold_0_saturation = [96.31294964028777, 255.0]
        self.__hsl_threshold_0_luminance = [0.0, 124.07818809753846]

        self.hsl_threshold_0_output = None

        self.__hsl_threshold_1_input = self.blur_output
        self.__hsl_threshold_1_hue = [40.46762589928058, 98.60068259385666]
        self.__hsl_threshold_1_saturation = [68.79496402877697, 235.41808873720137]
        self.__hsl_threshold_1_luminance = [0.0, 207.13310580204777]

        self.hsl_threshold_1_output = None

        self.__hsv_threshold_input = self.blur_output
        self.__hsv_threshold_hue = [24.280575539568343, 49.45392491467577]
        self.__hsv_threshold_saturation = [25.22482014388489, 70.05972696245733]
        self.__hsv_threshold_value = [208.67805755395685, 255.0]

        self.hsv_threshold_output = None


    def process(self, source0):
        """
        Runs the pipeline and sets all outputs to new values.
        """
        # Step add Blur:
        self.__blur_input = source0
        (self.blur_output) = self.__blur(self.__blur_input, self.__blur_type, self.__blur_radius)

        # Step HSL_Threshold0: Find red LED
        self.__hsl_threshold_0_input = self.blur_output
        (self.hsl_threshold_0_output) = self.__hsl_threshold(self.__hsl_threshold_0_input, self.__hsl_threshold_0_hue, self.__hsl_threshold_0_saturation, self.__hsl_threshold_0_luminance)
        #cv2.imshow("Red LED find",self.hsl_threshold_0_output)

        # Step HSL_Threshold1: Find green LED
        self.__hsl_threshold_1_input = self.blur_output
        (self.hsl_threshold_1_output) = self.__hsl_threshold(self.__hsl_threshold_1_input, self.__hsl_threshold_1_hue, self.__hsl_threshold_1_saturation, self.__hsl_threshold_1_luminance)
        #cv2.imshow("Green LED find",self.hsl_threshold_1_output)

        # Step HSV_Threshold0: Find yellow LED
        self.__hsv_threshold_input = self.blur_output
        (self.hsv_threshold_output) = self.__hsv_threshold(self.__hsv_threshold_input, self.__hsv_threshold_hue, self.__hsv_threshold_saturation, self.__hsv_threshold_value)
        #cv2.imshow("Yellow LED find",self.hsv_threshold_output)

    @staticmethod
    def __blur(src, type, radius):
        """Softens an image using one of several filters.
        Args:
            src: The source mat (numpy.ndarray).
            type: The blurType to perform represented as an int.
            radius: The radius for the blur as a float.
        Returns:
            A numpy.ndarray that has been blurred.
        """
        if(type is BlurType.Box_Blur):
            ksize = int(2 * round(radius) + 1)
            return cv2.blur(src, (ksize, ksize))
        elif(type is BlurType.Gaussian_Blur):
            ksize = int(6 * round(radius) + 1)
            return cv2.GaussianBlur(src, (ksize, ksize), round(radius))
        elif(type is BlurType.Median_Filter):
            ksize = int(2 * round(radius) + 1)
            return cv2.medianBlur(src, ksize)
        else:
            return cv2.bilateralFilter(src, -1, round(radius), round(radius))

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


BlurType = Enum('BlurType', 'Box_Blur Gaussian_Blur Median_Filter Bilateral_Filter')




def main (args=None):
    rclpy.init(args=args)

    #camera_publisher = rclpy.create_node('CameraPublisher')
    
    camera_publisher = CameraPublisher() #maybe rename to cam1 (camera_publisher maybe bad name)
    
    print('Node: cameraPublisher has been created')

    rclpy.spin(camera_publisher)

    camera_publisher.destroy_node()

    rclpy.shutdown()
