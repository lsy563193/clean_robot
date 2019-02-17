//
// Created by syue on 19-2-1.
//

#include "robot.h"

#include <utility>

SpMode Robot::IDLE_MODE{new IdleMode};
SpMode Robot::NORMAL_CLEAN_MODE{new NormalCleanMode};
SpMode Robot::SPOT_CLEAN_MODE{new SpotCleanMode};
SpMode Robot::FOLLOW_WALL_CLEAN_MODE{new FollowWallCleanMode};
SpMode Robot::EXPLORATION_MODE{new ExplorationMode};

void Robot::KeyCb(const std_msgs::String::ConstPtr &msg) {
    if (msg->data == "idle") {
        p_mode_->accept(normal_clean_key);
    }
    if (msg->data == "normal_clean") {
        p_mode_->accept(normal_clean_key);
    }
    else if (msg->data == "spot_clean") {
        p_mode_->accept(spot_clean_key);
    } else if (msg->data == "follow_wall_clean") {
        p_mode_->accept(follow_wall_clean_key);
    } else if (msg->data == "exploration") {
        p_mode_->accept(exploration_key);
    } else {
        ROS_INFO("I not heard: [%s]", msg->data.c_str());
    }
}

//SpMode Robot::getMode() const {
//    return p_mode_;
//}

void Robot::setMode(SpMode p_mode_) {
    Robot::p_mode_ = std::move(p_mode_);
}

void Robot::work() {
    if(p_mode_ != nullptr)
    {
        p_mode_->updateDevice();
    }
}

SpDevides Robot::getDevices() const {
    return devices;
}

Robot::Robot() {
    ros::NodeHandle n("");

    p_mode_->setRobot(this);
    key_sub_ = n.subscribe<std_msgs::String>("key", 1, &Robot::KeyCb, this);
    setMode(Robot::IDLE_MODE);
    work();
}
