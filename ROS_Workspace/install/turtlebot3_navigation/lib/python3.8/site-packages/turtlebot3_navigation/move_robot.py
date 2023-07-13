#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

import rclpy
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped

def main(args=None):
    rclpy.init(args=args)

    print('check1')
    node = rclpy.create_node('move_robot')

    # Prompt the user to enter the goal coordinates
    x = float(input("Enter the x coordinate of the goal position: "))
    y = float(input("Enter the y coordinate of the goal position: "))

    # Create a PoseStamped message for the goal position
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.pose.position.x = x
    goal_pose.pose.position.y = y
    goal_pose.pose.position.z = 0.0
    goal_pose.pose.orientation.w = 1.0


    # Create an action client for the "navigate_to_pose" action
    action_client = ActionClient(node, NavigateToPose, 'navigate_to_pose')
    print('check2')
 
    if not action_client.wait_for_server(timeout_sec=10.0):
        node.get_logger().error('Action server not available')
        rclpy.shutdown()
        return

    # Create the goal message
    goal_msg = NavigateToPose.Goal()
    goal_msg.pose.header.stamp = node.get_clock().now().to_msg()
    goal_msg.pose.header.frame_id = ''
    # pose_msg = PoseStamped()
    # pose_msg.pose.position.x = 2.0
    # pose_msg.pose.position.y = 1.0
    # pose_msg.pose.position.z = 0.0
    # pose_msg.pose.orientation.w = 1.0
    goal_msg.pose = goal_pose

    print('check3')

    # Send the goal and wait for it to complete
    node.get_logger().info('Sending goal...')
    future = action_client.send_goal_async(goal_msg)

    rclpy.spin_until_future_complete(node, future)
    result = future.result()

    if result is not None:
        node.get_logger().info('Goal succeeded!')
    else:
        node.get_logger().info('Goal failed!')

    # Clean up
    # node.destroy_node()
    rclpy.shutdown()

    print('check4')
if __name__ == '__main__':
    main()
