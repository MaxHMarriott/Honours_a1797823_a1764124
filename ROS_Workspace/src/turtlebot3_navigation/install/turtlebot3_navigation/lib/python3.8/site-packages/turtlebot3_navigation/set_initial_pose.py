#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

# import rclpy
# from geometry_msgs.msg import PoseWithCovarianceStamped

# def main(args=None):
#     rclpy.init(args=args)

#     # Create a node called "set_initial_pose"
#     node = rclpy.create_node('set_initial_pose')

#     # Create a publisher for the "initialpose" topic
#     publisher = node.create_publisher(PoseWithCovarianceStamped, 'initialpose', 10)

#     # Create a message with the initial pose
#     initial_pose = PoseWithCovarianceStamped()
#     initial_pose.header.frame_id = 'map'
#     initial_pose.pose.pose.position.x = 0.0
#     initial_pose.pose.pose.position.y = 0.0
#     initial_pose.pose.pose.position.z = 0.0
#     initial_pose.pose.pose.orientation.x = 0.0
#     initial_pose.pose.pose.orientation.y = 0.0
#     initial_pose.pose.pose.orientation.z = 0.0
#     initial_pose.pose.pose.orientation.w = 1.0

#     # Publish the initial pose message
#     publisher.publish(initial_pose)

#     # Print a message to indicate that the initial pose has been set
#     node.get_logger().info('Initial pose set to (0, 0, 0)')

#     rclpy.spin(node)
#     rclpy.shutdown()

#     print('check4')
    
# if __name__ == '__main__':
#     main()

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped

class SetInitialPose(Node):
    def __init__(self):
        super().__init__('set_initial_pose')
        
        self.publisher = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)

    def set_initial_pose(self, x, y, theta):
        initial_pose = PoseWithCovarianceStamped()
        
        # Set the frame ID and timestamp
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        
        # Set the pose
        initial_pose.pose.pose.position.x = x
        initial_pose.pose.pose.position.y = y
        initial_pose.pose.pose.orientation.z = theta
        initial_pose.pose.pose.orientation.w = 1.0  # Assuming a valid quaternion
        
        # Publish the initial pose
        self.publisher.publish(initial_pose)
        self.get_logger().info('Initial pose set')

def main(args=None):
    rclpy.init(args=args)
    node = SetInitialPose()
    
    for _ in range(3):
        # Set your desired initial pose here
        x = 0.0
        y = 0.0
        theta = 0.0
        
        node.set_initial_pose(x, y, theta)
        
        rclpy.spin_once(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()