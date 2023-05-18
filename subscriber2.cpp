#include <ros/ros.h>
#include<std_msgs/String.h>
#include "package1/custom.h"
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void cb(const package1::custom::ConstPtr& msg)
{
cout<<( msg->name.c_str())<<" "<<(msg->num.c_str())<<endl;
}
int main(int argc,char **argv)
{
    ros::init(argc,argv,"subscriber2");
    ros:: NodeHandle nr;
    ros:: Subscriber sub = nr.subscribe("data1",1000,cb);

    ros::spin();
    return 0;
}
