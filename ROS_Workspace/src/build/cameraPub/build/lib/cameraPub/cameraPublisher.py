import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class CameraPublisher:

    def __init__(self):
        super().__init__('camera_publisher')
        self.publisher = self.create_publisher(String,'topic')
        timer_period = 0.5
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.i = 0


    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i = 1

def main (args=None):
    rclpy.init(args=args)

    #camera_publisher = CameraPublisher()

    camera_publisher = rclpy.create_node('CameraPublisher')

    rclpy.spin(camera_publisher)

    camera_publisher.destroy_node()

    rclpy.shutdown()