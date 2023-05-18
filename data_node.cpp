#include <ros/ros.h>
#include <std_msgs/String.h>
#include <thread>
#include <iostream>


std::string username;
bool isPublishing = false;


void publishCallback(const std::string& input,int a)
{
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("data", 10);
    ros::Rate loop_rate(10);  

    while (ros::ok()&&a==1)
    {
       
        std_msgs::String msg;
        msg.data = input;
        pub.publish(msg);

        isPublishing = false;

        loop_rate.sleep();
    }

    isPublishing = false;
}


void subscribeCallback(const std_msgs::String::ConstPtr& msg)
{
    if (!isPublishing && msg->data != username)
    {
        ROS_INFO("[%s] Received message: %s", username.c_str(), msg->data.c_str());
    }
}

void publishThread()
{std::string input;
    while (ros::ok())
    {
       
        std::cout << "Enter your message: ";
        std::getline(std::cin, input);

        publishCallback(input,1);
    }
    publishCallback(input,0);

}

void subscribeThread()
{
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("data", 10, subscribeCallback);

    ros::spin();
}

int main(int argc, char** argv)
{
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    ros::init(argc, argv, "data_node");

    std::string node_name = "data_node_" + username;
    ros::NodeHandle nh("~");
    nh.setParam("node_name", node_name);
    std::thread publish_thread(publishThread);
    std::thread subscribe_thread(subscribeThread);
    publish_thread.join();
    subscribe_thread.join();

    return 0;
}
