#include <rviz/panel.h>
#include <ui_panel.h>   // generated from "panel.ui" using CMAKE_AUTOMOC
#include <ros/ros.h>
#include <atomic>
#include <math.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <stdlib.h>  
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/UInt8.h>
#include <gazebo_msgs/ModelState.h>
#include <std_msgs/String.h>

#include <rsp_msgs/Move.h>
#include <rsp_msgs/Reconfig.h>

namespace rsp_rviz {

class MultirobotControlPanel : public rviz::Panel {
    Q_OBJECT

public:
    MultirobotControlPanel(QWidget* parent = nullptr);

    int controlState = 2; // Start control state as OFF
    int ConfigID = 0;
    float robot_pos_x = 0.5;
    float robot_pos_y = 3.0;
    float robot_pos_z = 0.0;
    float robot_quat_x = 0.0;
    float robot_quat_y = 0.0;
    float robot_quat_z = 0.0;
    float robot_quat_w = 0.0;

    bool isRobotActive[4] = {true, true, true, true};

    char postion_chr[256];
    char orientation_chr[256];
    std::string robot_name;
    std::string robot_position_str;
    std::string robot_orientation_str;
    bool is_cmd_sent = false;

// slots
private slots:

    void on_button_on_clicked();
    void on_button_reset_clicked();
    void on_button_off_clicked();

    void on_button_separate_clicked();
    void on_button_align_clicked();
    void on_button_hlink_clicked();
    void on_button_vlink_clicked();

    void on_button_spawn_clicked();
    void on_button_destroy_clicked();
    void on_button_setgoal_clicked();

private: // methods

    void set_config(const uint8_t config);

    void rbt1_odom_status(const nav_msgs::Odometry &odom);
    void rbt2_odom_status(const nav_msgs::Odometry &odom);
    void rbt3_odom_status(const nav_msgs::Odometry &odom);
    void rbt4_odom_status(const nav_msgs::Odometry &odom);
    float get_odom_heading(const nav_msgs::Odometry &odom);
    void sendGazeboCmd();
    std::string convertToString(char* a, int size);
    void poseSend();

private: // members

    Ui::MultirobotControlForm ui;

    ros::NodeHandle nh;
    ros::Publisher pub_config_update;
    ros::Publisher pub_state_update;
    ros::Publisher ms_pub;
    ros::Subscriber sub_rbt1_odom;
    ros::Subscriber sub_rbt2_odom;
    ros::Subscriber sub_rbt3_odom;
    ros::Subscriber sub_rbt4_odom;
};


MultirobotControlPanel::MultirobotControlPanel(QWidget* parent) : rviz::Panel(parent) {
    
    // setup ROS
    pub_config_update = nh.advertise<std_msgs::UInt8>("rsp_config", 1);
    pub_state_update = nh.advertise<std_msgs::UInt8>("rsp_state", 1);
    ms_pub = nh.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1);

    sub_rbt1_odom = nh.subscribe("burger_1/odom", 1, &MultirobotControlPanel::rbt1_odom_status, this);
    sub_rbt2_odom = nh.subscribe("burger_2/odom", 1, &MultirobotControlPanel::rbt2_odom_status, this);
    sub_rbt3_odom = nh.subscribe("burger_3/odom", 1, &MultirobotControlPanel::rbt3_odom_status, this);
    sub_rbt4_odom = nh.subscribe("burger_4/odom", 1, &MultirobotControlPanel::rbt4_odom_status, this);

    // load ui form 
    ui.setupUi(this);
}

void MultirobotControlPanel::sendGazeboCmd(){

    ROS_INFO("[rsp_command] Sending command to Gazebo.");

    gazebo_msgs::ModelState ms;
    ms.model_name = robot_name;
    ms.pose.position.x = robot_pos_x;
    ms.pose.position.y = robot_pos_y;
    ms.pose.position.z = robot_pos_z;
    ms.pose.orientation.x = robot_quat_x;
    ms.pose.orientation.y = robot_quat_y;
    ms.pose.orientation.z = robot_quat_z;
    ms.pose.orientation.w = robot_quat_w;
    ms.reference_frame = "world";
    ms_pub.publish(ms);
    is_cmd_sent = true;
}

std::string MultirobotControlPanel::convertToString(char* a, int size) 
{ 
    std::string s(a); 
    return s; 
} 

void MultirobotControlPanel::poseSend(){

    ROS_INFO("[rsp_rviz] pose send");

    sprintf( postion_chr, "x: %s, y: %s, z: %s", std::to_string(robot_pos_x).c_str(),
                                            std::to_string(robot_pos_y).c_str(),
                                            std::to_string(robot_pos_z).c_str()); 
    robot_position_str = convertToString(postion_chr, 256);
    sprintf( orientation_chr, "x: %s, y: %s, z: %s, w: %s", std::to_string(robot_quat_x).c_str(),
                                            std::to_string(robot_quat_y).c_str(),
                                            std::to_string(robot_quat_z).c_str(),
                                            std::to_string(robot_quat_w).c_str());
    robot_orientation_str = convertToString(orientation_chr, 256);
    sendGazeboCmd();
}

void MultirobotControlPanel::on_button_on_clicked() {

    controlState = 0;
    ros::param::set("/rsp_multirobot_state", controlState);
    ROS_INFO("[rsp_rviz] MultirobotControlPanel set to state: ON");
    std_msgs::UInt8 state_out;
    state_out.data = controlState;
    pub_state_update.publish(state_out);
}

void MultirobotControlPanel::on_button_reset_clicked() {

    controlState = 1;
    ros::param::set("/rsp_multirobot_state", controlState);
    ROS_INFO("[rsp_rviz] MultirobotControlPanel set to state: RESET");
    std_msgs::UInt8 state_out;
    state_out.data = controlState;
    pub_state_update.publish(state_out);
}

void MultirobotControlPanel::on_button_off_clicked() {

    controlState = 2;
    ros::param::set("/rsp_multirobot_state", controlState);
    ROS_INFO("[rsp_rviz] MultirobotControlPanel set to state: OFF");
    std_msgs::UInt8 state_out;
    state_out.data = controlState;
    pub_state_update.publish(state_out);
}

void MultirobotControlPanel::on_button_separate_clicked() { set_config(0); }

void MultirobotControlPanel::on_button_align_clicked() { set_config(1); }

// void MultirobotControlPanel::on_button_hlink_clicked() { set_config(2); }

// void MultirobotControlPanel::on_button_vlink_clicked() { set_config(3); }


void MultirobotControlPanel::on_button_spawn_clicked(){
    QString id_qstr = ui.lineedit_spawn_id->text();
    QString pos_x_qstr = ui.lineedit_spawn_xpos->text();
    QString pos_y_qstr = ui.lineedit_spawn_ypos->text();
    std::string id_str = id_qstr.toStdString();
    std::string pos_x_str = pos_x_qstr.toStdString();
    std::string pos_y_str = pos_y_qstr.toStdString();

    if (id_str.empty()){
        ROS_ERROR("Robot ID must not be empty.");
        return;
    }
    if (pos_x_str.empty()){
        ROS_ERROR("pos_x must not be empty.");
        return;
    }
    if (pos_y_str.empty()){
        ROS_ERROR("pos_y must not be empty.");
        return;
    }

    int id = std::stoi(id_str);
    double spawn_pos_x = std::stod(pos_x_str);
    double spawn_pos_y = std::stod(pos_y_str);

    if (!(id <= 4 && id >= 1)){
        ROS_ERROR("Robot ID must be 1,2,3,or 4.");
        return;
    }
    if (!(spawn_pos_x <= 10 && spawn_pos_y <= 10 && spawn_pos_x >= -10 && spawn_pos_y >= -10)){
        ROS_ERROR("Spawn pos_x and pos_y cannot be larger than 10 or smaller than -10.");
        return;
    }

    ROS_INFO("[rsp_rviz] Spawning robot burger_%d at position = (%f, %f).", id, spawn_pos_x, spawn_pos_y);

    std::string robot_model_str;
    ros::param::param<std::string>("/rsp_robot_model", robot_model_str, "burger"); // Defaulte robot model from urdf
    robot_name = robot_model_str + "_" + std::to_string(id);

    robot_pos_x = spawn_pos_x;
    robot_pos_y = spawn_pos_y;
    robot_pos_z = 0.0;
    isRobotActive[id-1] = true;
    poseSend();
}

void MultirobotControlPanel::on_button_destroy_clicked(){
    QString id_qstr = ui.lineedit_destroy_id->text();
    std::string id_str = id_qstr.toStdString();

    if (id_str.empty()){
        ROS_ERROR("Robot ID must not be empty.");
        return;
    }

    int id = std::stoi(id_str);
    double destroy_pos_x = 0;
    double destroy_pos_y = -5-0.3*id;

    if (!(id <= 4 && id >= 1)){
        ROS_ERROR("Robot ID must be 1,2,3,or 4.");
        return;
    }

    ROS_INFO("[rsp_rviz] Destroying robot burger_%d ", id);

    std::string robot_model_str;
    ros::param::param<std::string>("/rsp_robot_model", robot_model_str, "burger"); // Defaulte robot model from urdf
    robot_name = robot_model_str + "_" + std::to_string(id);

    robot_pos_x = destroy_pos_x;
    robot_pos_y = destroy_pos_y;
    robot_pos_z = 0.0;
    isRobotActive[id-1] = false;

    poseSend();
}

void MultirobotControlPanel::on_button_setgoal_clicked(){
    QString pos_x_qstr = ui.lineedit_goal_xpos->text();
    QString pos_y_qstr = ui.lineedit_goal_ypos->text();
    QString rbtID_qstr = ui.lineedit_goal_rbtID->text();
    std::string pos_x_str = pos_x_qstr.toStdString();
    std::string pos_y_str = pos_y_qstr.toStdString();
    std::string rbtID_str = rbtID_qstr.toStdString();
    double goal_pos_x = std::stod(pos_x_str);
    double goal_pos_y = std::stod(pos_y_str);
    ROS_INFO("[rsp_rviz] Seting destination of robot %s at position = (%f, %f).", rbtID_str.c_str(), goal_pos_x, goal_pos_y);

    rsp_msgs::Move m;
    m.request.name = robot_name;
    m.request.x = goal_pos_x;
    m.request.y = goal_pos_y;
    m.request.theta = 0;
    ros::ServiceClient reconfig_cli; 
    reconfig_cli = nh.serviceClient<rsp_msgs::Move>("/go_to_point"); 
    reconfig_cli.call(m);

}

// void MultirobotControlPanel::auto_send_check() { if(auto_send) { send(); } }

void MultirobotControlPanel::set_config(const uint8_t config) {
    ConfigID = config;
    ROS_INFO("[rsp_rviz] Setting configuration to Config = %d. ", ConfigID);
    std_msgs::UInt8 config_out;
    config_out.data = ConfigID;
    pub_config_update.publish(config_out);

    if (config == 1){
        if (!((isRobotActive[0] && isRobotActive[1] && !isRobotActive[2] && !isRobotActive[3]) ||
           (isRobotActive[0] && isRobotActive[1] && isRobotActive[2] && !isRobotActive[3]) || 
           (isRobotActive[0] && isRobotActive[1] && isRobotActive[2] && isRobotActive[3]))){
            ROS_ERROR("[rsp_rviz] Invalid active robots, set configuration aborted.");
            return;
        }
    }

    rsp_msgs::Reconfig r;
    r.request.configuration = ConfigID;
    ros::ServiceClient reconfig_cli; 
    reconfig_cli = nh.serviceClient<rsp_msgs::Reconfig>("/reconfig_service"); 
    reconfig_cli.call(r);

}


void MultirobotControlPanel::rbt1_odom_status(const nav_msgs::Odometry &odom){

    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);
    ui.rbt1_pos_x->setText(QString::number(pos_x, 'f', 3));
    ui.rbt1_pos_y->setText(QString::number(pos_y, 'f', 3));
    ui.rbt1_heading->setText(QString::number(heading, 'f', 3));

}
void MultirobotControlPanel::rbt2_odom_status(const nav_msgs::Odometry &odom){

    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);
    ui.rbt2_pos_x->setText(QString::number(pos_x, 'f', 3));
    ui.rbt2_pos_y->setText(QString::number(pos_y, 'f', 3));
    ui.rbt2_heading->setText(QString::number(heading, 'f', 3));

}
void MultirobotControlPanel::rbt3_odom_status(const nav_msgs::Odometry &odom){
    
    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);
    ui.rbt3_pos_x->setText(QString::number(pos_x, 'f', 3));
    ui.rbt3_pos_y->setText(QString::number(pos_y, 'f', 3));
    ui.rbt3_heading->setText(QString::number(heading, 'f', 3));

}
void MultirobotControlPanel::rbt4_odom_status(const nav_msgs::Odometry &odom){
    
    float pos_x = odom.pose.pose.position.x ;
    float pos_y = odom.pose.pose.position.y ;
    float heading = get_odom_heading(odom);
    ui.rbt4_pos_x->setText(QString::number(pos_x, 'f', 3));
    ui.rbt4_pos_y->setText(QString::number(pos_y, 'f', 3));
    ui.rbt4_heading->setText(QString::number(heading, 'f', 3));

}

float MultirobotControlPanel::get_odom_heading(const nav_msgs::Odometry &odom){

    float orientationW = odom.pose.pose.orientation.w;
    float orientationX = odom.pose.pose.orientation.x;
    float orientationY = odom.pose.pose.orientation.y;
    float orientationZ = odom.pose.pose.orientation.z;
    float psi_rad = atan2(2 * orientationW * orientationZ, 1 - 2 * orientationZ * orientationZ);
    float psi_deg = psi_rad * 180/M_PI ;

    return psi_deg;
}


} // rsp_rviz


#include "rsp_rviz.moc"

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rsp_rviz::MultirobotControlPanel,rviz::Panel )