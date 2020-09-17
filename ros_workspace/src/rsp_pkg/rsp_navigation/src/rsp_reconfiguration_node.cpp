#include <ros/ros.h>
#include <rsp_msgs/Reconfig.h>
#include <rsp_msgs/Move.h>
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo_plugins/gazebo_ros_utils.h>
#include <gazebo_msgs/ModelStates.h>
#include <gazebo_ros_link_attacher/Attach.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <future>
#include <stdlib.h>


//Initialzie nodehandleptr
ros::NodeHandle* nh;
//create server and client objects
ros::Publisher ps1_pub;
ros::Publisher ps2_pub;
ros::Publisher ps3_pub;
ros::Publisher ps4_pub;
ros::Publisher pcs1_pub;
ros::Publisher pcs2_pub;
ros::Publisher pcs3_pub;
ros::Publisher pcs4_pub;
ros::Subscriber sub_rbt1_odom;
ros::Subscriber sub_rbt2_odom;
ros::Subscriber sub_rbt3_odom;
ros::Subscriber sub_rbt4_odom;
ros::ServiceServer srv;
ros::ServiceClient cli;
ros::ServiceClient attach_cli;
ros::ServiceClient detach_cli;

//Initialize parameters
int robot_count;
double robot_gap;
int robot_configuration;

int robot_move_id;
float Robot_pos_x[4] = {0, 0, 0, 0};
float Robot_pos_y[4] = {0, 0, 0, 0};
float Robot_quat_z[4] = {0, 0, 0, 0};


float get_odom_heading(const nav_msgs::Odometry &odom){

    float orientationW = odom.pose.pose.orientation.w;
    float orientationX = odom.pose.pose.orientation.x;
    float orientationY = odom.pose.pose.orientation.y;
    float orientationZ = odom.pose.pose.orientation.z;
    float psi_rad = atan2(2 * orientationW * orientationZ, 1 - 2 * orientationZ * orientationZ);
    float psi_deg = psi_rad * 180/M_PI ;

    return psi_deg;
}

void rbt1_odom_status(const nav_msgs::Odometry &odom){

    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);

    Robot_pos_x[0] = pos_x;
    Robot_pos_y[0] = pos_y;
    Robot_quat_z[0] = heading;

}
void rbt2_odom_status(const nav_msgs::Odometry &odom){

    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);

    Robot_pos_x[1] = pos_x;
    Robot_pos_y[1] = pos_y;
    Robot_quat_z[1] = heading;

}
void rbt3_odom_status(const nav_msgs::Odometry &odom){
    
    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);

    Robot_pos_x[2] = pos_x;
    Robot_pos_y[2] = pos_y;
    Robot_quat_z[2] = heading;

}
void rbt4_odom_status(const nav_msgs::Odometry &odom){
    
    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);

    Robot_pos_x[3] = pos_x;
    Robot_pos_y[3] = pos_y;
    Robot_quat_z[3] = heading;

}




bool move_robot(rsp_msgs::Move move_msg){

    geometry_msgs::PoseWithCovarianceStamped pcs;
    pcs.header.frame_id = "/map";
    pcs.header.stamp = ros::Time::now();
    pcs.pose.pose.position.x =  Robot_pos_x[robot_move_id]; 
    pcs.pose.pose.position.y =  Robot_pos_y[robot_move_id]; 
    pcs.pose.pose.orientation.z =  Robot_quat_z[robot_move_id]; 
    pcs.pose.pose.orientation.w =  1; 
    pcs.pose.covariance[0] = 0.25;
    pcs.pose.covariance[35] = 0.0685389194;

    geometry_msgs::PoseStamped ps;
    ps.header.frame_id = "/map";
    ps.header.stamp = ros::Time::now();
    ps.pose.position.x = move_msg.request.x;
    ps.pose.position.y = move_msg.request.y;
    ps.pose.orientation.w = move_msg.request.theta; 
    if (robot_move_id == 0){
        pcs1_pub.publish(pcs);
        ps1_pub.publish(ps);
    }else if(robot_move_id == 1){
        pcs2_pub.publish(pcs);
        ps2_pub.publish(ps);
    }else if(robot_move_id == 2){
        pcs3_pub.publish(pcs);
        ps3_pub.publish(ps);
    }else if(robot_move_id == 3){
        pcs4_pub.publish(pcs);
        ps4_pub.publish(ps);
    }

    for(int i = 0; i < robot_count; i++){
        while(fabs(move_msg.request.x - Robot_pos_x[robot_move_id]) < 0.05 && fabs(move_msg.request.y - Robot_pos_y[robot_move_id]) < 0.05 && fabs(move_msg.request.theta - Robot_quat_z[robot_move_id]) < 0.08){
            sleep(1000);
        }
    }

    return true;
}

bool attach(){
    ROS_INFO("Attaching");
    gazebo_ros_link_attacher::Attach attach_msg;
    for(int i = 0; i < robot_count -1;i++){
        std::stringstream s_0;
        s_0 << "burger_" << i+1;
        attach_msg.request.model_name_1 = s_0.str();

        std::stringstream s_1;
        s_1 << "burger_" << i+2;
        attach_msg.request.model_name_2 = s_1.str();

        attach_msg.request.link_name_1 = "base_footprint";
        attach_msg.request.link_name_2 = "base_footprint";

        attach_cli.call(attach_msg);
    }
}

bool detach(){
    ROS_INFO("Detaching");
    gazebo_ros_link_attacher::Attach detach_msg;
    for(int i = 0; i < robot_count -1;i++){
        std::stringstream s_0;
        s_0 << "burger_" << i+1;
        detach_msg.request.model_name_1 = s_0.str();

        std::stringstream s_1;
        s_1 << "burger_" << i+2;
        detach_msg.request.model_name_2 = s_1.str();

        detach_msg.request.link_name_1 = "base_footprint";
        detach_msg.request.link_name_2 = "base_footprint";
        

        detach_cli.call(detach_msg);
    }
}

bool reconfigure(rsp_msgs::Reconfig::Request &request, rsp_msgs::Reconfig::Response &response){
    
    ROS_INFO("RECONFIGURING!");

    gazebo_msgs::ModelStates states;
    boost::shared_ptr<gazebo_msgs::ModelStates const> states_ptr;
    states_ptr = ros::topic::waitForMessage<gazebo_msgs::ModelStates>("/gazebo/model_states",*nh);
    if(states_ptr != NULL){
        states = *states_ptr;
        ROS_INFO("STATES IS NOT EMPTY");
    }
    else{
        ROS_INFO("STATES IS EMPTY");
    }

    //Get number of robots
    ros::param::get("/robot_count",robot_count);
    ROS_INFO("number of turtles: [%d]",robot_count);

    //Get robot gap space
    ros::param::get("/robot_gap",robot_gap);
    ROS_INFO("gap space: [%f]",robot_gap);

    //Get current configuration
    ros::param::get("/robot_configuration",robot_configuration);
    ROS_INFO("existing configuration: [%d]",robot_configuration);
    
    ROS_INFO("desired configuration: [%d]",request.configuration);


        //detach hard links between robots first
    if(robot_configuration != 0) detach();


    //initialize pose stuff
    double theta_avg = 0;
    double x_avg = 0;
    double y_avg = 0;
    double x[robot_count];
    double y[robot_count];
    double theta[robot_count];
    double x_target[robot_count];
    double y_target[robot_count];
    double theta_target[robot_count];



    //get positions of each robot
    std::stringstream s;
    std::stringstream state_string;

    for(int i = 0; i < robot_count; i++){
        s.str("");
        s << "burger_" << i+1;
        std::string s_temp = s.str();

        // int n = sizeof(states.name)/sizeof(states.name[0]);
        int n = 6;
        ROS_INFO("size of state name: [%d]",n);
        int index = 0;

        for(int i = 0; i < n; i++){
            state_string.str("");
            state_string << states.name[i];
            std::string state_temp = state_string.str();
            ROS_INFO(state_temp.c_str());
            if(state_temp == s_temp){
                // ROS_INFO(s_temp.c_str());
                index = i;
                ROS_INFO("Found index");
            };
        }

        x[i] = states.pose[index].position.x;
        y[i] = states.pose[index].position.y;
        theta[i] = states.pose[index].orientation.z;
    }


    //calculate averages
    for(int i = 0; i < robot_count; i++){
                theta_avg = theta_avg + theta[i];
                x_avg = x_avg + x[i];
                y_avg = y_avg + y[i];
    }

    theta_avg = theta_avg/robot_count;
    x_avg = x_avg/robot_count;
    y_avg = y_avg/robot_count;
    

    

    //switch for each case
    switch(request.configuration){     //request.configuration    
        case 0: {
            for(int i = 0; i < robot_count; i++){
                x_target[i] = x[i];
                y_target[i] = y[i];
                theta_target[i] = theta[i];
            }    
        }


        case 1: {
            for(int i = 0; i < robot_count; i++){
                x_target[i] = x_avg + ((i+1)-(robot_count-1)/2)*robot_gap*cos(theta_avg);
                y_target[i] = y_avg + ((i+1)-(robot_count-1)/2)*robot_gap*sin(theta_avg);
                theta_target[i] = theta_avg;
            }    
        }


        default: {
            for(int i = 0; i < robot_count; i++){
                x_target[i] = x[i];
                y_target[i] = y[i];
                theta_target[i] = theta[i];
            }    
        }

    }


        //move all robots at the same time
    rsp_msgs::Move move_msg;
    // std::future<bool> successful[robot_count]; 
    for(int i = 0; i < robot_count; i++){
        move_msg.request.x = x_target[i];
        move_msg.request.y = y_target[i];
        move_msg.request.theta = theta_target[i];
        robot_move_id = i;
        // successful[i] = std::async(move_robot,move_msg);
        move_robot(move_msg);
    }


        // wait until all movement is done
    // for(int i = 0; i < robot_count; i++){
    //     successful[i].wait(); 
    // }

    bool success_flag = true;


    //wait check if every move succeded
    for(int i = 0; i < robot_count; i++){
        if(successful[i].get() == false) success_flag = false;
    }

    if(success_flag == true){
        response.success = true;
        ros::param::set("/robot_configuration",request.configuration);
        if(request.configuration != 0) attach();
    }
    else{
        response.success = false;
        ROS_INFO("FAILED TO RECONFIGURE");
    }

    return true;
}


int main(int argc, char** argv){
    ros::init(argc, argv, "reconfiguration_node");
    nh = new ros::NodeHandle;
    srv = nh->advertiseService("/reconfig_service", &reconfigure);

    sub_rbt1_odom = nh->subscribe("burger_1/odom", 1, &rbt1_odom_status);
    sub_rbt2_odom = nh->subscribe("burger_2/odom", 1, &rbt2_odom_status);
    sub_rbt3_odom = nh->subscribe("burger_3/odom", 1, &rbt3_odom_status);
    sub_rbt4_odom = nh->subscribe("burger_4/odom", 1, &rbt4_odom_status);


    ps1_pub = nh->advertise<geometry_msgs::PoseStamped>("burger_1/move_base_simple/goal", 1);
    ps2_pub = nh->advertise<geometry_msgs::PoseStamped>("burger_2/move_base_simple/goal", 1);
    ps3_pub = nh->advertise<geometry_msgs::PoseStamped>("burger_3/move_base_simple/goal", 1);
    ps4_pub = nh->advertise<geometry_msgs::PoseStamped>("burger_4/move_base_simple/goal", 1);

    pcs1_pub = nh->advertise<geometry_msgs::PoseWithCovarianceStamped>("burger_1/initialpose", 1);
    pcs2_pub = nh->advertise<geometry_msgs::PoseWithCovarianceStamped>("burger_2/initialpose", 1);
    pcs3_pub = nh->advertise<geometry_msgs::PoseWithCovarianceStamped>("burger_3/initialpose", 1);
    pcs4_pub = nh->advertise<geometry_msgs::PoseWithCovarianceStamped>("burger_4/initialpose", 1);

    attach_cli = nh->serviceClient<gazebo_ros_link_attacher::Attach>("/link_attacher_node/attach");
    detach_cli = nh->serviceClient<gazebo_ros_link_attacher::Attach>("/link_attacher_node/detach");

    ros::spin();

    return 0;
}