import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
import cv2



class CameraSubscriber(Node):
  		
  	#hello world example:      
        #msg = String()
        #msg.data = 'Hello World: %d' % self.i        
        #self.subscriber.publish(msg)
        #self.get_logger().info('Publishing: "%s"' % msg.data)
        #self.i = self.i + 1

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
                print(data)
                current_frame = self.br.imgmsg_to_cv2(data)

                #displaying image
                cv2.imshow("Camera",current_frame)

                cv2.waitKey(1)

                return


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