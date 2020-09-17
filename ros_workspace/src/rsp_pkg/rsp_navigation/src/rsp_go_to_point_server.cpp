#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <rsp_navigation/rsp_go_to_point_server.hpp>
#include <math.h> 

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_to_point_server::move_to_point_server(ros::NodeHandle& nh):
  nh(nh) {
  srv = nh.advertiseService("go_to_point", move_to_point);
  }

move_to_point_server::~move_to_point_server(){}

bool move_to_point(rsp_msgs::Move::Request &req,
         rsp_msgs::Move::Response &res)
{
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //send goal to robot
  goal.target_pose.header.frame_id = req.name;
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = req.x;
  goal.target_pose.pose.position.y = req.y;

  // euler_to_quaternion:
  double yaw, roll, pitch;
  yaw = req.theta; roll = 0; pitch = 0;
  goal.target_pose.pose.orientation.x = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2);
  goal.target_pose.pose.orientation.y = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2);
  goal.target_pose.pose.orientation.z = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2);
  goal.target_pose.pose.orientation.w = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("The base moved.");

  else
    ROS_INFO("The base failed to move.");
    res.success = false;
    return 0;

  res.success = true;
  return 1;
}