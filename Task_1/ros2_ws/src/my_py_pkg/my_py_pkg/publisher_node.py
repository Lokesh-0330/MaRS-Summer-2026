import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PyPublisher(Node):
    def __init__(self):
        super().__init__('py_publisher_node')
        # Pushes message string objects over the same "shared_topic" pipeline channel
        self.publisher_ = self.create_publisher(String, 'shared_topic', 10)
        self.timer = self.create_wall_timer(0.5, self.timer_callback)
        self.count = 0

    def timer_callback(self):
        msg = String()
        msg.data = f'Hello from Python! Count: {self.count}'
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.data}"')
        self.count += 1

def main(args=None):
    rclpy.init(args=args)
    node = PyPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()