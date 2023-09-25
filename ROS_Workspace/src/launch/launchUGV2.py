from launch import LaunchDescription
from launch_ros.actions import Node

#mind the namespaces - will hopefully be fixed soon
#change UAVMain to UAV etc etc etc.
#accept arguements from terminal.

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='UGV2Vision',
            namespace='UGV2Vision',
            executable='UGV2Vision',
            name='UGV2Vision'
        ),
        Node(
            package='UGV2Processing',
            namespace='UGV2Processing',
            executable='UGV2Processing',
            name='UGV2Processing'
        ),
        Node(
            package='UGV2Main',
            namespace='UGV2Main',
            executable='UGV2Main',
            name='UGV2Main'
        ),
        
    ])
