#include <ros/ros.h>
#include <rsp_navigation/rsp_go_to_point_server.hpp>

#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

#include "rsp_msgs/Move.h"

bool move_to_point(rsp_msgs::Move::Request &req,
         rsp_msgs::Move::Response &res)
{
  MoveBaseClient client("move_base", true);

  ROS_INFO("Waiting for the action server to start");
  client.waitForServer();

  ROS_INFO("Action server started, sending the goal");
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.stamp = ros::Time::now();

  // set frame
  goal.target_pose.header.frame_id = "map";

  // set position
  goal.target_pose.pose.position.x = req.x;
  goal.target_pose.pose.position.y = req.y;
  goal.target_pose.pose.position.z = 0.0;

  double yaw, roll, pitch;
  yaw = req.theta; roll = 0; pitch = 0;
  goal.target_pose.pose.orientation.x = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2);
  goal.target_pose.pose.orientation.y = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2);
  goal.target_pose.pose.orientation.z = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2);
  goal.target_pose.pose.orientation.w = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2);


  client.sendGoal(goal);

  ROS_INFO("Waiting for the result");
  client.waitForResult();

  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Succeeded");
    res.success = true;
  } else {
    ROS_INFO("Failed");
    res.success = false;
  }
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_to_point_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("move_to_point", move_to_point);
  ROS_INFO("Ready to move.");
  ros::spin();

  return 0;
}
