import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
import cv2



class CameraSubscriber(Node):	

        def __init__(self):
                super().__init__("camera_sub_topic")
                print('This has run')
                topic_name = '/camera_topic'
                self.subscription = self.create_subscription(Image, topic_name,self.subscribe_message, qos_profile_sensor_data)
                self.subscription
                self.br = CvBridge()
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
                start_point = (5,5)
                end_point = (50,50)
                colour = (255,0,0)
                thickness = 1
                image = cv2.rectangle(image, start_point, end_point, colour, thickness)
                return image   

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
