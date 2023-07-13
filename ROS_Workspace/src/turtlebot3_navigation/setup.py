from setuptools import setup

package_name = 'turtlebot3_navigation'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
        	        'set_initial_pose = turtlebot3_navigation.set_initial_pose:main',
        	        'zone_move = turtlebot3_navigation.zone_move:main',
            ],
    },
)
