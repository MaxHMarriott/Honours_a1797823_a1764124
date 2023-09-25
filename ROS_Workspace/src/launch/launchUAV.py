from launch import LaunchDescription
from launch_ros.actions import Node

#mind the namespaces - will hopefully be fixed soon
#change UAVMain to UAV etc etc etc.
#accept arguements from terminal.

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='UAVVision',
            namespace='UAVVision',
            executable='UAVVision',
            name='UAVVision'
        ),
        Node(
            package='UAVProcessing',
            namespace='UAVProcessing',
            executable='UAVProcessing',
            name='UAVProcessing'
        ),
        Node(
            package='UAVMain',
            namespace='UAVMain',
            executable='UAVMain',
            name='UAVMain'
        ),
        
    ])
