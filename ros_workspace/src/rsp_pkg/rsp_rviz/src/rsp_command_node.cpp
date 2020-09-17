#include <string>
#include <fstream>
#include <streambuf>
#include <stdlib.h>  
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <gazebo_msgs/ModelState.h>

float robot_pos_x = 0.5;
float robot_pos_y = 3.0;
float robot_pos_z = 0.0;
float robot_quat_x = 0.0;
float robot_quat_y = 0.0;
float robot_quat_z = 0.0;
float robot_quat_w = 0.0;
char postion_chr[256];
char orientation_chr[256];
std::string robot_name;
std::string robot_position_str;
std::string robot_orientation_str;
int robot_id = 1; 
gazebo_msgs::ModelState ms;

void poseStampedCallback(const geometry_msgs::PoseStamped& poseStamped){

    ROS_INFO("[rsp_command] poseStamped callback");

    robot_name = poseStamped.header.frame_id;
    robot_id = robot_name.at (robot_name.length () - 1) - '0';

    robot_pos_x = poseStamped.pose.position.x;
    robot_pos_y = poseStamped.pose.position.y;
    robot_pos_z = poseStamped.pose.position.z;
    robot_quat_x = poseStamped.pose.orientation.x;
    robot_quat_y = poseStamped.pose.orientation.y;
    robot_quat_z = poseStamped.pose.orientation.z;
    robot_quat_w = poseStamped.pose.orientation.w;

    ms.model_name = robot_name;
    ms.pose.position.x = robot_pos_x;
    ms.pose.position.y = robot_pos_y;
    ms.pose.position.z = robot_pos_z;
    ms.pose.orientation.x = robot_quat_x;
    ms.pose.orientation.y = robot_quat_y;
    ms.pose.orientation.z = robot_quat_z;
    ms.pose.orientation.w = robot_quat_w;
    ms.reference_frame = "world";
}

void poseCallback(const geometry_msgs::Pose& pose){

    ROS_INFO("[rsp_command] pose callback");

    robot_pos_x = pose.position.x;
    robot_pos_y = pose.position.y;
    robot_pos_z = pose.position.z;
    robot_quat_x = pose.orientation.x;
    robot_quat_y = pose.orientation.y;
    robot_quat_z = pose.orientation.z;
    robot_quat_w = pose.orientation.w;

    
    ms.model_name = robot_name;
    ms.pose.position.x = robot_pos_x;
    ms.pose.position.y = robot_pos_y;
    ms.pose.position.z = robot_pos_z;
    ms.pose.orientation.x = robot_quat_x;
    ms.pose.orientation.y = robot_quat_y;
    ms.pose.orientation.z = robot_quat_z;
    ms.pose.orientation.w = robot_quat_w;
    ms.reference_frame = "world";
    
}



int main(int argc, char** argv)
{

    ros::init(argc, argv, "rsp_command_node");
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher ms_pub;

    std::string robot_model_str;
    ros::param::param<std::string>("/rsp_robot_model", robot_model_str, "burger"); // Defaulte robot model from urdf
    ms_pub = nh.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1);

    robot_name = robot_model_str + "_" + std::to_string(robot_id);

    if (nh.getParam("robot_name", robot_name)){
        robot_id = robot_name.at (robot_name.length () - 1) - '0';
        //ROS_INFO(("[rsp_command] robot_name set to: " + robot_name).c_str());
    }

    std::string robot_command_str;
    if (nh.getParam("command", robot_command_str)){

        if(robot_command_str.compare("set_pose") == 0)
        {
            ROS_INFO("[rsp_command] input: _command:=set_pose");
        }
        if(robot_command_str.compare("remove") == 0)
        {
            ROS_INFO("[rsp_command] input: _command:=remove.");
            robot_pos_x = 0.0;
            robot_pos_y = -5.0 - robot_id * 0.3;
            robot_pos_z = 0.0;
            robot_quat_x = 0.0;
            robot_quat_y = 0.0;
            robot_quat_z = 0.0;
            robot_quat_w = 0.0;
        }
    }

    // Accepting poseStamped input, where frame_id will be the robot_name
    std::string robot_poseStamped_str;
    // Accepting pose input, where robot_name should be specified
    std::string robot_pose_str;
    
    if (nh.getParam("poseStamped", robot_poseStamped_str)){
        ROS_INFO("[rsp_command] input: poseStamped received.");
        if ( ros::ok() ){
            boost::shared_ptr<geometry_msgs::PoseStamped const> ps;
            ps = ros::topic::waitForMessage<geometry_msgs::PoseStamped>(robot_poseStamped_str, ros::Duration(1000));
            if(ps != NULL){
                poseStampedCallback(*ps);
                ms_pub.publish(ms);
            }
        }
    }
    else if (nh.getParam("pose", robot_pose_str)){
        ROS_INFO("[rsp_command] input: pose received.");
        if ( ros::ok() ){
            boost::shared_ptr<geometry_msgs::Pose const> p;
            p = ros::topic::waitForMessage<geometry_msgs::Pose>(robot_pose_str, ros::Duration(1000));
            if (p != NULL){
                poseCallback(*p);
                ms_pub.publish(ms);
            }
        }
    }

	return 0;
}
