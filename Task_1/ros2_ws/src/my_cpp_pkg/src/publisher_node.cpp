#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"          // Core ROS 2 C++ engine library
#include "std_msgs/msg/string.hpp"    // Standard message type for sending text string packages

using namespace std::chrono_literals;

class CppPublisher : public rclcpp::Node {
public:
    CppPublisher() : Node("cpp_publisher_node"), count_(0) {
        // Broadcasts std_msgs/msg/String messages over a pipeline called "shared_topic"
        publisher_ = this->create_publisher<std_msgs::msg::String>("shared_topic", 10);
        
        // Timer fires the callback function every 500 milliseconds (twice per second)
        timer_ = this->create_wall_timer(500ms, std::bind(&CppPublisher::timer_callback, this));
    }

private:
    void timer_callback() {
        auto message = std_msgs::msg::String();
        message.data = "Hello from C++! Count: " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CppPublisher>());
    rclcpp::shutdown();
    return 0;
}