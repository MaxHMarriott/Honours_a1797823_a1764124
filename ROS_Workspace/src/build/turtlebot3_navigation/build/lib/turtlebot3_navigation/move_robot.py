#ros2 pkg create --build-type ament_python turtlebot3_navigation

#!/usr/bin/env python3

from asyncio import wait_for
from os import wait
import rclpy
import math
from rclpy.node import Node
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Twist, Pose
from rclpy.publisher import Publisher
from std_msgs.msg import Float64
from tf2_ros import TransformListener, Buffer

class MoveRobot(Node):
    def __init__(self):
        super().__init__('move_robot')

        print ('Node created')
        angle = 90
        self.degrees = angle  # You need to define 'angle' before using it
        self.desired_angle = math.radians(self.degrees)

        # Initialize x_goal and y_goal
        self.x_goal = 0.0
        self.y_goal = 0.0

        self.goal_pose = PoseStamped()
        self.goal_pose.header.frame_id = 'map'
        self.goal_pose.pose.position.x = self.x_goal  # You need to define 'x_goal' before using it
        self.goal_pose.pose.position.y = self.y_goal  # You need to define 'y_goal' before using it
        self.goal_pose.pose.position.z = 0.0
        self.goal_pose.pose.orientation.x = 0.0
        self.goal_pose.pose.orientation.y = 0.0
        self.goal_pose.pose.orientation.z = math.sin(self.desired_angle / 2.0)
        self.goal_pose.pose.orientation.w = math.cos(self.desired_angle / 2.0)

        #Create subscriber to source topic
        self.source_subscriber = self.create_subscription(
            Pose,
            'poseOrder',
            self.source_callback,
            10
        )
        print ('Subscriber created')
        
        # Create a timer that triggers every 30 seconds
        self.timer = self.create_timer(20.0, self.timer_callback)

        self.action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        self.location_publisher = self.create_publisher(PoseStamped, 'robot_location', 10)
        self.eta_publisher = self.create_publisher(Float64, 'robot_ETA', 10)


        self.odom_sub = self.create_subscription(Twist, '/odom', self.odom_callback, 10)


    def source_callback(self,msg):

        # Update goal_pose with new x_goal and y_goal values
        print ('Receiving goal')
        self.x_goal = msg.position.x
        self.y_goal = msg.position.y
        z_goal = msg.position.z

        self.get_logger().info(f'Received point: x={self.x_goal}, y={self.y_goal}, z={z_goal}')

        # Update goal_pose with new x_goal and y_goal values
        self.goal_pose.pose.position.x = self.x_goal
        self.goal_pose.pose.position.y = self.y_goal

        if self.y_goal < 0:
            angle = 355
            
        else:
            angle = 90
        
        self.degrees = angle  # You need to define 'angle' before using it
        self.desired_angle = math.radians(self.degrees)

        self.goal_pose.pose.position.z = 0.0
        self.goal_pose.pose.orientation.x = 0.0
        self.goal_pose.pose.orientation.y = 0.0
        self.goal_pose.pose.orientation.z = math.sin(self.desired_angle / 2.0)
        self.goal_pose.pose.orientation.w = math.cos(self.desired_angle / 2.0)
        print('Angle:',angle,self.goal_pose.pose.orientation)


    def timer_callback(self):
        # Use the latest received pose as the goal pose
        self.get_logger().info('Timer triggered. Sending new goal...')

        # Prepare the goal message
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.pose = self.goal_pose.pose


        self.action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        print ('ActionClient pose passed')
        print('Sending goal:', goal_msg.pose.pose)  # print the goal
        
        # Send the goal
        if not self.action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error('Action server not available')
            return
        else:
            future = self.action_client.send_goal_async(goal_msg)
            self.get_logger().info('Goal sent')
            # rclpy.spin_until_future_complete(self, future)
            result = future.result()

            if result is not None:
                self.get_logger().info('Goal result:{}'.format(result.result.result))
                if result.result.result:
                    self.get_logger().info('Goal succeeded!')
                else:
                    self.get_logger().info('Goal failed!')
            else:
                self.get_logger().info('Goal execution returned None')

    def calculate_distance(pose1, pose2):
        dx = pose1.pose.position.x - pose2.pose.position.x
        dy = pose1.pose.position.y - pose2.pose.position.y
        return math.sqrt(dx * dx + dy * dy)
    
    def odom_callback(self, msg):
        # Calculate the distance to the goal
        distance_to_goal = calculate_distance(msg.pose, self.goal_pose)

        current_location = PoseStamped()
        current_location.header.frame_id = 'map'
        current_location.pose.position.x = msg.pose.position.x
        current_location.pose.position.y = msg.pose.position.y
        current_location.pose.position.z = msg.pose.position.z
        current_location.pose.orientation = msg.pose.orientation

        self.location_publisher.publish(current_location)

        linear_speed = math.sqrt(msg.linear.x**2 + msg.linear.y**2 + msg.linear.z**2)

        if linear_speed != 0:
            eta = distance_to_goal / linear_speed
        else:
            eta = float('inf')

        eta_msg = Float64()
        eta_msg.data = eta
        self.eta_publisher.publish(eta_msg)

        print('Estimated Time of Arrival: {:.2f} seconds'.format(eta))

def main(args=None):
        rclpy.init(args=args)
        node = MoveRobot()
        try:
            rclpy.spin(node)
        finally:
            node.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
        main()