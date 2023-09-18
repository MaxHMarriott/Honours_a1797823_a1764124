from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'yaml_filename': '/path/to/map.yaml'}]
        ),
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[{
                'use_sim_time': True,
                'initial_pose': {
                    'x': 0.0,
                    'y': 0.0,
                    'z': 0.0,
                    'theta': 0.0
                }
            }]
        ),
        Node(
            package='nav2_controller',
            executable='controller_server',
            name='controller_server',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
        Node(
            package='nav2_planner',
            executable='planner_server',
            name='planner_server',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
        Node(
            package='nav2_recovery',
            executable='recoveries_server',
            name='recoveries_server',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
        Node(
            package='nav2_bt_navigator',
            executable='bt_navigator',
            name='bt_navigator',
            output='screen',
            parameters=[{'use_sim_time': True}]
        )
    ])

