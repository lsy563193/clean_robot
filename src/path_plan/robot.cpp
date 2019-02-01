//
// Created by syue on 19-2-1.
//

#include "robot.h"

IMode *Robot::IDLE_MODE = new IdleMode;
IMode *Robot::NORMAL_CLEAN_MODE = new NormalCleanMode;

void Robot::KeyCb(const std_msgs::String::ConstPtr &msg) {
    if (msg->data == "normal_clean") {
        ROS_INFO("I heard: [%s]", msg->data.c_str());
        p_mode_->accept(normal_clean_key);
    } else {

        ROS_INFO("I not heard: [%s]", msg->data.c_str());
    }
}

IMode *Robot::getMode() const {
    return p_mode_;
}

void Robot::setMode(IMode *p_mode_) {
    Robot::p_mode_ = p_mode_;
}

Robot::Robot() {
    ROS_INFO("init");
    ros::NodeHandle n("");
    key_sub_ = n.subscribe<std_msgs::String>("key", 1, &Robot::KeyCb, this);
    p_mode_->setRobot(this);
    ROS_INFO("~init");
}
