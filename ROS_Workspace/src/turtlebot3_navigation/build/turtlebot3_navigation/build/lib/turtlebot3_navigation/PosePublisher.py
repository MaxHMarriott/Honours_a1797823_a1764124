#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from std_msgs.msg import Int32  # Import Int32 message type for rate control
import time
import random
from std_msgs.msg import Bool

class PosePublisherNode(Node):
    def __init__(self):
        super().__init__('pose_publisher_node')
        self.pose_publisher = self.create_publisher(Pose, 'poseOrder', 10)
        self.rate = self.create_publisher(Int32, 'rate', 10)  # Create a rate control publisher
        self.getisLED = 1
    
        print ('Subscriber_created')
        self.source_subscriber = self.create_subscription(
            Bool,
            '/Go',
            self.source_callback,
            10
        )

        self.timer = self.create_timer(1, self.timer_callback)

    def publish_pose(self, x, y, z):
        pose_msg = Pose()
        pose_msg.position.x = x
        pose_msg.position.y = y
        pose_msg.position.z = z
        self.pose_publisher.publish(pose_msg)

    def timer_callback (self):
        if self.led_status == 1:
                # Publish the current pose
                time.sleep(10)
                # Publish the first pose
                x1 = -2.55
                y1 = -0.05
                z1 = 0.0
                self.publish_pose(x1, y1, z1)
                print('Published Pose: ',x1,y1,z1)
                time.sleep(20)  # Sleep for 2 minutes (120 seconds)

                # # Publish the initial pose
                # x2 = 0.0 #-2.55
                # y2 = 0.0 #-0.05
                # z2 = 0.0
                # self.publish_pose(x2, y2, z2)
                # print('Published Pose: ',x2, y2, z2)
                # time.sleep(30)  # Sleep for 60 seconds
        else:
                # time.sleep(10)
                # x1 = -2.55
                # y1 = -0.05
                # z1 = 0.0
                # self.publish_pose(x1, y1, z1)
                # print('Published Pose: ',x1,y1,z1)
                # time.sleep(45)  # Sleep for 2 minutes (120 seconds)
            time.sleep(10)
            # Publish the initial pose
            x2 = 0.0 #-2.55
            y2 = 0.0 #-0.05
            z2 = 0.0
            self.publish_pose(x2, y2, z2)
            print('Published Pose: ',x2, y2, z2)
            time.sleep(20)  # Sleep for 60 seconds

    def source_callback(self,msg):
        print ('Led status passed')
        self.getisLED = msg.data
        self.get_logger().info(f'Received bool: {self.getisLED}')

        self.led_status = self.getisLED
        print("LED is on:", self.led_status)
    


def main(args=None):
    rclpy.init(args=args)
    node = PosePublisherNode()

    # def is_LED_on():
    #     return random.choice([0, 1])

    

            # rclpy.spin(node)
    # node.destroy_node()
    # rclpy.shutdown()

    try:
            rclpy.spin(node)
    finally:
            node.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
    main()



    #sudo code
    # if is_LED_on == 1 
        # publish same point for next 2 minutes
    # else 
        # publish initial pose coordinate 
        
    # for _ in range (3):
    #     time.sleep(10)
    #     # Publish the first pose
    #     x1 = 1.0
    #     y1 = 1.0
    #     z1 = 0.0
        
    #     node.publish_pose(x1, y1, z1)
    #     print('Published Pose 1',x1,y1,z1)

    #     # Delay for 60 seconds
    #     time.sleep(60)

    #     # Publish the second pose
    #     x2 = 1.0
    #     y2 = 0.0
    #     z2 = 0.0
    #     node.publish_pose(x2, y2, z2)
    #     print('Published Pose 2',x2,y2,z2)

    #     # Delay for 60 seconds
    #     time.sleep(60)