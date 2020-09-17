#include <string>
#include <fstream>
#include <streambuf>
#include <stdlib.h>  
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>

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
bool is_cmd_sent = false;

int main(int argc, char** argv)
{

    std::string robot_model_str;
    ros::param::param<std::string>("/rsp_robot_model", robot_model_str, "burger"); // Defaulte robot model from urdf
    std::string robot_pose_str;
    geometry_msgs::Pose robot_pose;

    int robot_id = 1; 
    float robot_pos_x = 0.5;
    float robot_pos_y = 3.0;
    float robot_pos_z = 0.0;
    float robot_quat_x = 0.0;
    float robot_quat_y = 0.0;
    float robot_quat_z = 0.0;
    float robot_quat_w = 0.0;

    ros::init(argc, argv, "rsp_command_node");
    ros::NodeHandle nh("~");

    std::string robot_name = robot_model_str + "_" + std::to_string(robot_id);
    std::string postion_str = "x: " + std::to_string(robot_pos_x) + ", y: " + std::to_string(robot_pos_y) 
                            + ", z: " + std::to_string(robot_pos_z);  
    std::string orientation_str = "x: " + std::to_string(robot_quat_x) + ", y: " + std::to_string(robot_quat_y) 
                            + ", z: " + std::to_string(robot_quat_z) + ", w: " + std::to_string(robot_quat_w);  

    if (nh.getParam("robot_name", robot_name)){
        ROS_INFO(("[rsp_command] robot_name set to: " + robot_name).c_str());
    }
    if (nh.getParam("robot_pose_str", robot_pose_str)){

        ros::param::get(robot_pose_str.c_str(), robot_pose);
        robot_pos_x = robot_pose.position.x;
        robot_pos_y = robot_pose.position.y;
        robot_pos_z = robot_pose.position.z;
        robot_quat_x = robot_pose.orientation.x;
        robot_quat_y = robot_pose.orientation.y;
        robot_quat_z = robot_pose.orientation.z;
        robot_quat_w = robot_pose.orientation.w;
        
        postion_str = "x: " + std::to_string(robot_pos_x) + ", y: " + std::to_string(robot_pos_y) 
                    + ", z: " + std::to_string(robot_pos_z);  
        orientation_str = "x: " + std::to_string(robot_quat_x) + ", y: " + std::to_string(robot_quat_y) 
                    + ", z: " + std::to_string(robot_quat_z) + ", w: " + std::to_string(robot_quat_w);  
        
        ROS_INFO(("[rsp_command] postion_str set to: " + postion_str).c_str());
        ROS_INFO(("[rsp_command] orientation_str set to: " + orientation_str).c_str());
    }



    // pid_t child = fork();
    // if (child == 0){
    //     system(("export ROS_NAMESPACE=" + robot_name).c_str());
    //     system(("rosrun --prefix '" + robot_name + "' gazebo_ros spawn_model -urdf -model " + robot_name + 
    //             " -x 0.5 -y 2.2 -z 0.0 -param robot_description").c_str());
    //     system(("rosrun robot_state_publisher robot_state_publisher -publish_frequency 50.0 -tf_prefix " + 
    //             robot_name).c_str());
    // }

    ros::spinOnce();

	return 0;
}