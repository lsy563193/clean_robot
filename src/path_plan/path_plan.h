//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_PATH_PLAN_H
#define PATH_PLAN_PATH_PLAN_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "mode.h"

namespace path_plan{
    class PathPlan {

    public:

        PathPlan();

        void NormalCleanCb(const std_msgs::String::ConstPtr& msg);

    private:
//        ros::NodeHandle nh_;
        ros::Subscriber key_sub_;
    private:
        CleanVisit* clean_visit_{new CleanVisit};
        IMode* p_mode_{new IdleMode};
    public:
        IMode *getMode() const;

        void setMode(IMode *p_mode_);
    };
}


#endif //PATH_PLAN_PATH_PLAN_H
