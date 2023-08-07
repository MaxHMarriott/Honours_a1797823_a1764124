#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

import rclpy
import math
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped
from rclpy.publisher import Publisher
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from tf2_ros import TransformListener
from tf2_ros import Buffer

def calculate_distance(pose1, pose2):
    dx = pose1.pose.position.x - pose2.pose.position.x
    dy = pose1.pose.position.y - pose2.pose.position.y
    return math.sqrt(dx * dx + dy * dy)

def main(args=None):
    rclpy.init(args=args)

    print('check1')
    node = rclpy.create_node('move_robot')

    node.declare_parameter('x')
    node.declare_parameter('y')
    node.declare_parameter('angle')

    # Prompt the user to enter the goal coordinates
    """ x = float(input("Enter the x coordinate of the goal position: "))
    y = float(input("Enter the y coordinate of the goal position: "))
    angle = float(input("Enter the angle for the robot to turn: ")) """

    x = node.get_parameter('x').get_parameter_value().double_value
    y = node.get_parameter('y').get_parameter_value().double_value
    angle = node.get_parameter('angle').get_parameter_value().double_value

    degrees = angle
    desired_angle = math.radians(degrees)


    # Create a PoseStamped message for the goal position
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.pose.position.x = x
    goal_pose.pose.position.y = y
    goal_pose.pose.position.z = 0.0
    goal_pose.pose.orientation.x = 0.0
    goal_pose.pose.orientation.y = 0.0
    goal_pose.pose.orientation.z = math.sin(desired_angle / 2.0)
    goal_pose.pose.orientation.w = math.cos(desired_angle / 2.0)
    

    # Create a publisher for robot's current location
    location_publisher = node.create_publisher(PoseStamped, 'robot_location',10)

    # Create a publisher for robot's ETA
    eta_publisher = node.create_publisher(Float64, 'robot_ETA',10)

    # Create an action client for the "navigate_to_pose" action
    action_client = ActionClient(node, NavigateToPose, 'navigate_to_pose')
    print('check2')
 
    if not action_client.wait_for_server(timeout_sec=10.0):
        node.get_logger().error('Action server not available')
        rclpy.shutdown()
        return

    # Create a subscriber to get the robot's odometry data
    odom_sub = node.create_subscription(Twist, '/odom', odom_callback, 10)

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
    # node.destroy_node()
    rclpy.shutdown()

def odom_callback(msg):
    # Calculate the distance to the goal
    distance_to_goal = calculate_distance(msg.pose, goal_pose)

    #Create a PoseStamped message for the robot's current location
    current_location = PoseStamped()
    current_location.header.frame_id = 'map'
    current_location.pose.position.x = msg.pose.position.x
    current_location.pose.position.y = msg.pose.position.y
    current_location.pose.position.z = msg.pose.position.z
    current_location.pose.orientation = msg.pose.orientation

    #Publish current location
    location_publisher.publish(current_location)

    # Calculate the magnitude of the linear velocity (speed)
    linear_speed = math.sqrt(msg.linear.x**2 + msg.linear.y**2 + msg.linear.z**2)

    # Calculate estimated time of arrival (ETA) in seconds
    if linear_speed != 0:
        eta = distance_to_goal / linear_speed
    else:
        eta = float('inf')

    #Publish the ETA
    eta_msg = Float64()

    # Print or use the estimated time of arrival (eta) as required
    print('Estimated Time of Arrival: {:.2f} seconds'.format(eta))

    print('check4')
if __name__ == '__main__':
    main()
