#ros2 pkg create --build-type ament_python turtlebot3_navigation


import rclpy
from rclpy.node import Node
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String


class MoveRobot(Node):

    def __init__(self):
        print ('def _in print')
        super().__init__('move_robot')
        print ('def _in print 2')
        
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

        print ('def _in print 3')

        #self.navigation_client = self.create_client(NavigateToPose, '/navigate_to_pose')

        #while not self.navigation_client.wait_for_service(timeout_sec=1.0):
         #   self.get_logger().info('Navigation service not available, waiting...')

        #self.goal = PoseStamped()
        #self.goal.header.frame_id = 'map'
        #self.goal.pose.position.x = 1.0  # desired x-coordinate
        #self.goal.pose.position.y = 2.0  # desired y-coordinate
        #self.goal.pose.orientation.z = 0.0  # desired orientation

        #self.navigate_to_goal()
        
        
    def timer_callback(self):
        msg = String()
        msg.data = 'Hello world: %d' %self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' %msg.data)
        self.i += 1
        print ('time_Callback')

    #def navigate_to_goal(self):
     #   goal_msg = NavigateToPose.Goal()
      #  goal_msg.pose = self.goal
       # self.navigation_client.send_goal_async(goal_msg)
        #self.navigation_client.wait_for_result()
		
def main(args=None):
    rclpy.init(args=args)
    move_robot = MoveRobot()
    print ('Node created')
    rclpy.spin(move_robot)
    print ('main print2')
    move_robot.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
