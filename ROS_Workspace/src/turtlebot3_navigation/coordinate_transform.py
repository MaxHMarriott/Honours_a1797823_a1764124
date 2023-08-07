#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PointStamped
from geometry_msgs.msg import Point

class CoordinateTransform(Node):
    def __init__(self):
        super().__init__('coordinate_transform')

        #Create subscriber to source topic
        self.source_subscriber = self.create_subscription(
            PointStamped,
            'UAV_frame_coordinate_sub',
            self.source_callback,
            10
        )

        #Create publisher for target topic
        self.target_publisher = self.create_publisher(
            PointStamped,
            'UGV_frame_coordinate_pub',
            10
        )

    def source_callback(self,msg):
        # Perform coordinate transformation 
        transformed_point = PointStamped()
        transformed_point.header = msg.header
        transformed_point.point = Point()
        transformed_point.x = msg.point.x + 1.0
        transformed_point.y = msg.point.y + 0.5
        transformed_point.y = msg.point.z

        #Publish modified coordinate point 
        self.target_publisher.publish(transformed_point)

def main(args=None):
        rclpy.init(args=args)
        node = CoordinateTransform()
        rclpy.spin(node)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
        main()