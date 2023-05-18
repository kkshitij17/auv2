#include <ros/ros.h>
#include <std_msgs/String.h>

// Global variable to store the user input
std::string user_input;

// Callback function to handle received messages
void messageCallback(const std_msgs::String::ConstPtr& msg) {
    // Display the received message, except if it matches the user input
    if (msg->data != user_input) {
        ROS_INFO("Received message: %s", msg->data.c_str());
    }
}

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "user_input");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Create a publisher object
    ros::Publisher pub = nh.advertise<std_msgs::String>("data", 10);

    // Create a subscriber object
    ros::Subscriber sub = nh.subscribe("data", 10, messageCallback);

    // Get user input
    std::cout << "Enter a message: ";
    std::getline(std::cin, user_input);

    // Publish the user input message
    std_msgs::String msg;
    msg.data = user_input;
    pub.publish(msg);

    // Spin and wait for callbacks
    ros::spin();

    return 0;
}
