import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
import cv2
from std_msgs.msg import Float32MultiArray
import numpy
import math
from enum import Enum
import cv2


class CameraSubscriber(Node):	

    def __init__(self):
        super().__init__("UAVProcessing")
        print('This has run')
        topic_name = '/UAVFrame'
        self.subscription = self.create_subscription(Image, topic_name,self.subscribe_message, qos_profile_sensor_data)
        self.UAVReturns= Float32MultiArray()
        self.UAVReturns.data= [0.0,0.0,0.0,0.0]
        self.publisher = self.create_publisher(Float32MultiArray,"/UAVDetections",10)
        self.br = CvBridge()
        print("Creating vision pipeline")
        #perform processing on captured frame
        self.UAVPipeline=UAVVisionDetect()
        print("Vision pipeline completed")
        print('Topic: ' + topic_name)

    def subscribe_message(self,data):
        print('displaying image')
        self.frame = self.br.imgmsg_to_cv2(data)
        #displaying image
        cv2.imshow("Camera",self.frame)
        self.UAVPipeline.process(self.frame)
        frame2 = self.UAVPipeline.cv_threshold_output
        frame3 = visionCrop(frame2)
        processingOutput = visionProcessing(frame3)
        print("returns:")
        print(processingOutput)
        self.UAVReturns.data = processingOutput #in form Q1 count, Q2 count, Q3 count, Q4 count
        self.publisher.publish(self.UAVReturns)
        cv2.imshow('Detected image',frame2)
        cv2.waitKey(1)
        return

class UAVVisionDetect:
    """
    An OpenCV pipeline generated by GRIP.
    """
    
    def __init__(self):
        """initializes all values to presets or None if need to be set
        """


        self.desaturate_output = None

        self.__cv_threshold_src = self.desaturate_output
        self.__cv_threshold_thresh = 136.0
        self.__cv_threshold_maxval = 255.0
        self.__cv_threshold_type = cv2.THRESH_BINARY

        self.cv_threshold_output = None

        self.__find_lines_input = self.desaturate_output

        self.find_lines_output = None



    def process(self, source0):
        """
        Runs the pipeline and sets all outputs to new values.
        """
        # Step Desaturate0:
        self.__desaturate_input = source0
        (self.desaturate_output) = self.__desaturate(self.__desaturate_input)

        # Step CV_Threshold0:
        self.__cv_threshold_src = self.desaturate_output
        (self.cv_threshold_output) = self.__cv_threshold(self.__cv_threshold_src, self.__cv_threshold_thresh, self.__cv_threshold_maxval, self.__cv_threshold_type)

        # Step Find_Lines0:
       # self.__find_lines_input = self.desaturate_output
        #(self.find_lines_output) = self.__find_lines(self.__find_lines_input)


    @staticmethod
    def __desaturate(src):
        """Converts a color image into shades of gray.
        Args:
            src: A color numpy.ndarray.
        Returns:
            A gray scale numpy.ndarray.
        """
        (a, b, channels) = src.shape
        if(channels == 1):
            return numpy.copy(src)
        elif(channels == 3):
            return cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
        elif(channels == 4):
        	return cv2.cvtColor(src, cv2.COLOR_BGRA2GRAY)
        else:
            raise Exception("Input to desaturate must have 1, 3 or 4 channels") 

    @staticmethod
    def __cv_threshold(src, thresh, max_val, type):
        """Apply a fixed-level threshold to each array element in an image
        Args:
            src: A numpy.ndarray.
            thresh: Threshold value.
            max_val: Maximum value for THRES_BINARY and THRES_BINARY_INV.
            type: Opencv enum.
        Returns:
            A black and white numpy.ndarray.
        """
        return cv2.threshold(src, thresh, max_val, type)[1]

    class Line:

        def __init__(self, x1, y1, x2, y2):
            self.x1 = x1
            self.y1 = y1
            self.x2 = x2
            self.y2 = y2

        def length(self):
            return numpy.sqrt(pow(self.x2 - self.x1, 2) + pow(self.y2 - self.y1, 2))

        def angle(self):
            return math.degrees(math.atan2(self.y2 - self.y1, self.x2 - self.x1))
    @staticmethod
    def __find_lines(input):
        """Finds all line segments in an image.
        Args:
            input: A numpy.ndarray.
        Returns:
            A filtered list of Lines.
        """
        detector = cv2.createLineSegmentDetector()
        if (len(input.shape) == 2 or input.shape[2] == 1):
            lines = detector.detect(input)
        else:
            tmp = cv2.cvtColor(input, cv2.COLOR_BGR2GRAY)
            lines = detector.detect(tmp)
        output = []
        if len(lines) != 0:
            for i in range(1, len(lines[0])):
                tmp = UavVisionDetect.Line(lines[0][i, 0][0], lines[0][i, 0][1],
                                lines[0][i, 0][2], lines[0][i, 0][3])
                output.append(tmp)
        return output

def visionCrop(frame2):
#this function is a calibration function that only needs to be run once for each camera setup.
#all LEDS are to be detected, and a corresponding crop is achieved.
    m = frame2.shape[0]
    n = frame2.shape[1]
    x1 = 0
    y1 = 0
    x2 = 0
    y2 = 0
    x1toggle = 0
    y1toggle = 0
    for x in range(m-1):
        for y in range(n-1):
            if (frame2[x,y] > 1):
                if (x2<x):
                    x2 = x
                if (y2<y):
                    y2 = y
                if (0==x1toggle):
                    x1 = x
                    x1toggle = 1
                if (0==y1toggle):
                    y1 = y
                    y1toggle = 1
                if (x1>x):
                    x1 = x
                if (y1>y):
                    y1 = y
    print("x1: ",x1," y1: ",y1)
    print("resizing from:",m,n,"to:",x2-x1,y2-y1)
    frame2 = frame2[x1:x2, y1:y2]
    return frame2
    	
def visionProcessing(frame2):
    #determine quadrants
    m = frame2.shape[0]
    n = frame2.shape[1]

    Q1sum = 0
    Q2sum = 0
    Q3sum = 0
    Q4sum = 0

    print("shape returns:",frame2.shape)

    for a in range(0,int(m/2 - 1),1):
    	for b in range(int(n/2-1)):
            Q2sum = Q2sum + frame2[a,b]
            #print(frame2[a,b])
    Q2sum = Q2sum/255
    print("Q2 result is: ",Q2sum)
		
		
    for a in range(int(m/2 - 1),m,1):
    	for b in range(int(n/2-1)):
    		Q1sum = Q1sum + frame2[a,b]
    Q1sum = Q1sum/255
    print("Q1 result is: ",Q1sum)
    
    
    for a in range(int(m/2 - 1),m,1):
    	for b in range(int(n/2 - 1),n,1):
    		Q3sum = Q3sum + frame2[a,b]
    Q3sum = Q3sum/255
    print("Q3 result is: ",Q3sum)


    for a in range(0,int(m/2 - 1),1):
    	for b in range(int(n/2 - 1),n,1):
    		Q4sum = Q4sum + frame2[a,b]
    Q4sum = Q4sum/255
    print("Q4 result is: ",Q4sum)
    return [Q1sum,Q2sum,Q3sum,Q4sum]

def main (args=None):
    rclpy.init(args=args)

    #camera_subscriber = rclpy.create_node('Camerasubscriber')
    
    camera_subscriber = CameraSubscriber() #maybe rename to cam1 (camera_subscriber maybe bad name)
    
    print('Node: UGVProcessing has been created')

    rclpy.spin(camera_subscriber)

    camera_subscriber.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
        main()