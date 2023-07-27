from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='UAVMain',
            namespace='UAVMain',
            executable='UAVMain',
            name='UAVMain'
        ),
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
