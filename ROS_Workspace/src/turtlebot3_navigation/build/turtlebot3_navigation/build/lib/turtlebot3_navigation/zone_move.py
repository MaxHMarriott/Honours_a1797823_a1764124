#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

import rclpy
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped

def calculate_center_point(start_x, start_y, end_x, end_y):
    center_x = (start_x + end_x) / 2.0
    center_y = (start_y + end_y) / 2.0
    return center_x, center_y

def main(args=None):
    rclpy.init(args=args)

    print('check1')
    node = rclpy.create_node('move_robot')

    # Prompt the user to enter the zone number
    zone_number = int(input("Enter the zone number (1 or 2): "))

    if zone_number == 1:
        # Zone 1 coordinates
        start_x, start_y = 1.8, 1 # Put the coordiates in AMCL
        end_x, end_y = 1, -1
    elif zone_number == 2:
        # Zone 2 coordinates
        start_x, start_y = 1.8, -1
        end_x, end_y = 1, -3
    else:
        print("Invalid zone number!")
        rclpy.shutdown()
        return

    # Calculate the center point of the selected zone
    center_x, center_y = calculate_center_point(start_x, start_y, end_x, end_y)

    # Create a PoseStamped message for the goal position
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.pose.position.x = center_x
    goal_pose.pose.position.y = center_y
    goal_pose.pose.position.z = 0.0
    goal_pose.pose.orientation.w = 1.0

    # Print the goal position
    print(f"Moving the robot to the goal position: ({center_x}, {center_y})")

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
    rclpy.shutdown()

    print('check4')

if __name__ == '__main__':
    main()
