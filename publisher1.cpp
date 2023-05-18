#include <ros/ros.h>
#include<std_msgs/String.h>
#include "package1/custom.h"
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(int argc,char **argv)
{
ros::init(argc,argv,"Publisher1");
ros::NodeHandle nh;
ros::Publisher pub =nh.advertise<package1::custom>("data1",1000);
ros::Rate loop_rate(10);cout<<"node has bee initialized\n";

while(ros::ok())
{
package1::custom msg;
string message;
cout<<"ready to take input\n";
getline(cin,message);
cout<<"\" "<<message<<" \""<<"will be sent to 2\n";
msg.name=message;
msg.num="NUMBER";
pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
}
return 0;
}