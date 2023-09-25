from launch import LaunchDescription
from launch_ros.actions import Node

#mind the namespaces - will hopefully be fixed soon
#change UAVMain to UAV etc etc etc.
#accept arguements from terminal.

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='UGV1Vision',
            namespace='UGV1Vision',
            executable='UGV1Vision',
            name='UGV1Vision'
        ),
        Node(
            package='UGV1Processing',
            namespace='UGV1Processing',
            executable='UGV1Processing',
            name='UGV1Processing'
        ),
        Node(
            package='UGV1Main',
            namespace='UGV1Main',
            executable='UGV1Main',
            name='UGV1Main'
        ),
        
    ])
