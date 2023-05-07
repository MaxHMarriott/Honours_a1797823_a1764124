import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
import cv2
import imutils

#training steps:

#1. Input image
#2. Constructing image pyramid
#3. Run sliding window at each scale of pyramid
#4. for each step in sliding window extract ROI
#5. Take ROI and pass it to CNN 
#6. if min probability test passes, record class label and bounding box location
#7. apply class-wise NMS
#8. return results

