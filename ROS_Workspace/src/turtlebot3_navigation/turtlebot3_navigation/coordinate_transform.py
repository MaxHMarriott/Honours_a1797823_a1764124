#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

from turtle import position
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PointStamped
from geometry_msgs.msg import Pose
from geometry_msgs.msg import Point

class CoordinateTransform(Node):
    def __init__(self):
        super().__init__('coordinate_transform')

        #Create subscriber to source topic
        self.source_subscriber = self.create_subscription(
            Pose,
            'poseOrder',
            self.source_callback,
            10
        )

        self.timer = self.create_timer(10.0, self.timer_callback)

        #Create publisher for target topic
        self.target_publisher = self.create_publisher(
            PointStamped,
            'UGV_frame_coordinate_pub',
            10
        )

    def source_callback(self,msg):
        # # Perform coordinate transformation 
        # transformed_point = PointStamped()
        # transformed_point.header = msg.header
        # transformed_point.point = Point()
        # # transformed_point.point.x = msg.point.x + 1.0

        x = msg.position.x
        y = msg.position.y
        z = msg.position.z

        # transformed_point.x = msg.position.x + 1.0
        # transformed_point.y = msg.position.y + 0.5
        # transformed_point.y = msg.position.z

        self.get_logger().info(f'Received point: x={x}, y={y}, z={z}')

        # #Publish modified coordinate point 
        # self.target_publisher.publish(position)

    def timer_callback(self):
        self.get_logger().info('Timer callback: Listening for points...')

def main(args=None):
        rclpy.init(args=args)
        node = CoordinateTransform()
        rclpy.spin(node)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
        main()