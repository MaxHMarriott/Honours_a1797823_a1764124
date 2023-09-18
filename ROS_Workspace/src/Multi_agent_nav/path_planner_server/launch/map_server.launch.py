# Copyright (c) 2020 Samsung Research Russia
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
from sys import executable

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml


def generate_launch_description():
    map_file = os.path.join(get_package_share_directory('path_planner_server'),'config','map_test.yaml')
    rviz_config_dir = os.path.join(
        get_package_share_directory('nav2_bringup'),
        'rviz',
        'nav2_default_view.rviz')
    
    return LaunchDescription([
        
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'use_sim_time':False},
            		 {'yaml_filename':map_file},
                     {'topic_name':"map"},
                     {'frame_id':"map"}
            		]),
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_mapper',
            output='screen',
            parameters=[{'use_sim_time': False},
                        {'autostart': True},
                        {'node_names': ['map_server']}]),

        Node(
            package = 'tf2_ros',
            executable = 'static_transform_publisher',
            name = 'link1_broadcaster',
            arguments=['0','0','0','0','0','0','0','map','tb3_0/odom'],
            output='screen',
        ),
        
        # Node(
        #     package = 'tf2_ros',
        #     executable = 'static_transform_publisher',
        #     name = 'link1_broadcaster',
        #     arguments=['0','0','0','0','0','0','1','map','frame'],
        #     output='screen',
        # )
    #      Node(
    #     #    namespace = 'tb3_0',
    #        package='rviz2',
    #        executable='rviz2',
    #        name='rviz2',
    #        arguments=['-d', rviz_config_dir],
    #        parameters=[{'use_sim_time': False}],
    #        output='screen'),

    # ld.add_action(static_transform_publisher_node)
    ])

