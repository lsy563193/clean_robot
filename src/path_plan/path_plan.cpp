//
// Created by syue on 19-2-1.
//

#include "path_plan.h"

namespace path_plan {

    void PathPlan::NormalCleanCb(const std_msgs::String::ConstPtr &msg) {
        if(msg->data == "normal_clean")
        {
            ROS_INFO("I heard: [%s]", msg->data.c_str());
            p_mode_->accept(clean_visit_);
        } else
        {

            ROS_INFO("I not heard: [%s]", msg->data.c_str());
        }
    }

    IMode *PathPlan::getMode() const {
        return p_mode_;
    }

    void PathPlan::setMode(IMode *p_mode_) {
        PathPlan::p_mode_ = p_mode_;
    }

    PathPlan::PathPlan() {
        ROS_INFO("init");
        ros::NodeHandle n("");
        key_sub_ = n.subscribe<std_msgs::String>("key", 1, &PathPlan::NormalCleanCb, this);
        ROS_INFO("~init");
    }
}

