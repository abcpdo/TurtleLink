#include <string>
#include <fstream>
#include <streambuf>
#include <stdlib.h>  
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>

class rsp_command{

public:

    rsp_command(ros::NodeHandle& nh);
    ~rsp_command();
    void poseCallback(const geometry_msgs::Pose::ConstPtr& pose);

private:

    ros::Subscriber sub_pose;

}