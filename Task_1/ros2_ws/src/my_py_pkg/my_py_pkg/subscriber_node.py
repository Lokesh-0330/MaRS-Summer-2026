import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PySubscriber(Node):
    def __init__(self):
        super().__init__('py_subscriber_node')
        # Listens to the same "shared_topic" channel pipeline track
        self.subscription = self.create_subscription(
            String,
            'shared_topic',
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        self.get_logger().info(f'Python Node Heard: "{msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    node = PySubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()