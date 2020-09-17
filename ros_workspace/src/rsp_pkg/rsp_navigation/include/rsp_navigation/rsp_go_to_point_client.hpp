#include <ros/ros.h>
#include <rsp_msgs/Move.h>

class move_to_point_client {
private:
	ros::NodeHandle nh;
	ros::ServiceClient clt;

public:
	move_to_point_client(ros::NodeHandle& nh);
	~move_to_point_client();
	bool call(rsp_msgs::Move srv);
};