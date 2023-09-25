from setuptools import setup
import os
from glob import glob

package_name = 'turtlebot3_navigation'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', 'turtlebot3_navigation','launch'),glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='vboxuser',
    maintainer_email='vboxuser@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
            'console_scripts': [
        	        'move_robot = turtlebot3_navigation.move_robot:main',
        	        'move_two_robots = turtlebot3_navigation.move_two_robots:main',
        	        'set_initial_pose = turtlebot3_navigation.set_initial_pose:main',
        	        'zone_move = turtlebot3_navigation.zone_move:main',
        	        'coordinate_transform = turtlebot3_navigation.coordinate_transform:main',
        	        'PosePublisher = turtlebot3_navigation.PosePublisher:main',
            ],
    },
)
