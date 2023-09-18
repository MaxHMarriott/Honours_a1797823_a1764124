# Copyright (c) 2018 Intel Corporation
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

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml


def generate_launch_description():
    # Get the launch directory
    bringup_dir = get_package_share_directory('path_planner_server')

    namespace = LaunchConfiguration('namespace')
    use_sim_time = LaunchConfiguration('use_sim_time')
    autostart = LaunchConfiguration('autostart')
    tb3_0_params_file = os.path.join(get_package_share_directory('path_planner_server'),'config','tb3_0_nav2_params.yaml')
    default_bt_xml_filename = LaunchConfiguration('default_bt_xml_filename')
    map_subscribe_transient_local = LaunchConfiguration('map_subscribe_transient_local')

    lifecycle_nodes_tb3_0 = ['tb3_0/controller_server',
                       'tb3_0/planner_server',
                       'tb3_0/recoveries_server',
                       'tb3_0/bt_navigator',
                       'tb3_0/waypoint_follower']
    
    # Map fully qualified names to relative ones so the node's namespace can be prepended.
    # In case of the transforms (tf), currently, there doesn't seem to be a better alternative
    # https://github.com/ros/geometry2/issues/32
    # https://github.com/ros/robot_state_publisher/pull/30
    # TODO(orduno) Substitute with `PushNodeRemapping`
    #              https://github.com/ros2/launch_ros/issues/56


    # Create our own temporary YAML files that include substitutions
    param_substitutions = {
        'use_sim_time': use_sim_time,
        'default_bt_xml_filename': default_bt_xml_filename,
        'autostart': autostart,
        'map_subscribe_transient_local': map_subscribe_transient_local}

    configured_params_tb3_0 = RewrittenYaml(
            source_file=tb3_0_params_file,
            root_key=namespace,
            param_rewrites=param_substitutions,
            convert_types=True)
    
    remappings = [('/tf', 'tf'),
                  ('/tf_static', 'tf_static')]

    return LaunchDescription([

        # Nodes for tb3_0
        
        Node(
            namespace = 'tb3_0',
            package='nav2_controller',
            executable='controller_server',
            output='screen',
            parameters=[tb3_0_params_file]
            remappings=remappings),

        Node(
            namespace = 'tb3_0',
            package='nav2_planner',
            executable='planner_server',
            name='planner_server',
            output='screen',
            parameters=[tb3_0_params_file]
            remappings=remappings),

        Node(
            namespace = 'tb3_0',
            package='nav2_recoveries',
            executable='recoveries_server',
            name='recoveries_server',
            output='screen',
            parameters=[tb3_0_params_file]
            remappings=remappings),

        Node(
            namespace = 'tb3_0',
            package='nav2_bt_navigator',
            executable='bt_navigator',
            name='bt_navigator',
            output='screen',
            parameters=[tb3_0_params_file]
            remappings=remappings),

        Node(
            namespace = 'tb3_0',
            package='nav2_waypoint_follower',
            executable='waypoint_follower',
            name='waypoint_follower',
            output='screen',
            parameters=[tb3_0_params_file]
            remappings=remappings),

        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='tb3_0_lifecycle_manager_navigation',
            output='screen',
            parameters=[{'use_sim_time': False},
                        {'autostart': True},
                        {'bond_timeout': 0.0},
                        {'node_names': lifecycle_nodes_tb3_0}]),

    ])
