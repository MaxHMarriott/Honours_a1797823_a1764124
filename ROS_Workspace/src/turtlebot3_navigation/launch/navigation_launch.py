from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

""" def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlebot3_navigation',
            executable='move_robot',
            output='screen',
            parameters=[
                {'x': LaunchConfiguration('x')},
                {'y': LaunchConfiguration('y')},
                {'angle': LaunchConfiguration('angle')}
            ],
        ), 
    ]) """

def generate_launch_description():
    return LaunchDescription([
        # Declare launch arguments
        DeclareLaunchArgument('x', description='X coordinate of the goal position'),
        DeclareLaunchArgument('y', description='Y coordinate of the goal position'),
        DeclareLaunchArgument('angle', description='Angle for the robot to turn'),

        # Launch the navigation node
        Node(
            package='turtlebot3_navigation',
            executable='move_robot',
            output='screen',
        )
    ])

