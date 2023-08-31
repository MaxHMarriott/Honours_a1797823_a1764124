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
from geometry_msgs.msg import PoseWithCovarianceStamped, Point

def main(args=None):
    rclpy.init(args=args)

    # Create a node called "set_initial_pose"
    node = rclpy.create_node('set_initial_pose')

    # Create a publisher for the "initialpose" topic
    initial_pose_publisher = node.create_publisher(PoseWithCovarianceStamped, 'initialpose', 10)

    # Create a publisher for the "pose_relocalization" topic
    reset_position_publisher = node.create_publisher(Point, 'pose_relocalization', 10)

    # Create a message with all zeros for resetting the position
    reset_position_msg = Point()

    # Publish the reset position message
    reset_position_publisher.publish(reset_position_msg)

    # Create a message with the initial pose
    initial_pose_msg = PoseWithCovarianceStamped()
    initial_pose_msg.header.frame_id = 'map'
    initial_pose_msg.pose.pose.position.x = 0.0
    initial_pose_msg.pose.pose.position.y = 0.0
    initial_pose_msg.pose.pose.position.z = 0.0
    initial_pose_msg.pose.pose.orientation.x = 0.0
    initial_pose_msg.pose.pose.orientation.y = 0.0
    initial_pose_msg.pose.pose.orientation.z = 0.0
    initial_pose_msg.pose.pose.orientation.w = 1.0

    # Publish the initial pose message
    initial_pose_publisher.publish(initial_pose_msg)

    # Print a message to indicate that the initial pose has been set
    node.get_logger().info('Initial pose set to (0, 0, 0)')

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
