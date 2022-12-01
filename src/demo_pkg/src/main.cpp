#include <iostream>
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::cout << "Hello, ROS2!" << std::endl;

    rclcpp::shutdown();
    return 0;
}