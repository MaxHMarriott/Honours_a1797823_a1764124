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
        self.pose_publisher0 = self.create_publisher(Pose, 'poseOrder0', 10)
        self.pose_publisher1 = self.create_publisher(Pose, 'poseOrder1', 10)
        self.rate = self.create_publisher(Int32, 'rate', 10)  # Create a rate control publisher
        self.getisLED = 1
    
        print ('Bool Subscriber_created')
        self.source_subscriber = self.create_subscription(
            Bool,
            '/Go',
            self.source_callback,
            10
        )

        self.timer = self.create_timer(1, self.timer_callback)

    def publish_pose0(self, x, y, z):
        tb3_0_pose_msg = Pose()
        tb3_0_pose_msg.position.x = x
        tb3_0_pose_msg.position.y = y
        tb3_0_pose_msg.position.z = z
        self.pose_publisher0.publish(tb3_0_pose_msg)

    def publish_pose1(self, x, y, z):
        tb3_1_pose_msg = Pose()
        tb3_1_pose_msg.position.x = x
        tb3_1_pose_msg.position.y = y
        tb3_1_pose_msg.position.z = z
        self.pose_publisher1.publish(tb3_1_pose_msg)

    def timer_callback (self):
        self.led_status = 1
        if self.led_status == 1:
                # Publish the current pose
                time.sleep(10)
                # Publish the first pose
                x_tb3_0 = -0.475
                y_tb3_0 = -0.12
                z_tb3_0 = 0.0
                self.publish_pose0(x_tb3_0, y_tb3_0, z_tb3_0)
                print('Published Pose0: ',x_tb3_0,y_tb3_0,z_tb3_0)

                x_tb3_1 = -2.55
                y_tb3_1 = -0.05
                z_tb3_1 = 0.0
                self.publish_pose1(x_tb3_1, y_tb3_1, z_tb3_1)
                print('Published Pose1: ',x_tb3_1, y_tb3_1, z_tb3_1)
    
                time.sleep(20)  # Sleep for 2 minutes (120 seconds)


        else:
            time.sleep(10)
            # Publish the first pose
            x_tb3_0 = 0.0
            y_tb3_0 = 0.0
            z_tb3_0 = 0.0
            self.publish_pose0(x_tb3_0, y_tb3_0, z_tb3_0)
            print('Published Pose0: ',x_tb3_0,y_tb3_0,z_tb3_0)

            x_tb3_1 = 0.0
            y_tb3_1 = 0.0
            z_tb3_1 = 0.0
            self.publish_pose1(x_tb3_1, y_tb3_1, z_tb3_1)
            print('Published Pose1: ',x_tb3_1, y_tb3_1, z_tb3_1)
            
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
