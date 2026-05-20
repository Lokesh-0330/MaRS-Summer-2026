#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class CppSubscriber : public rclcpp::Node {
public:
    CppSubscriber() : Node("cpp_subscriber_node") {
        // Listens to the exact same "shared_topic" channel pipeline
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "shared_topic", 10, std::bind(&CppSubscriber::topic_callback, this, std::placeholders::_1));
    }

private:
    // Triggers automatically the instant a text payload drops onto the topic
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const {
        RCLCPP_INFO(this->get_logger(), "C++ Node Heard: '%s'", msg->data.c_str());
    }
    
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CppSubscriber>());
    rclcpp::shutdown();
    return 0;
}