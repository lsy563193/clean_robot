//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_PATH_PLAN_H
#define PATH_PLAN_PATH_PLAN_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "mode.h"

class Robot {

public:
    static IMode *IDLE_MODE;
    static IMode *NORMAL_CLEAN_MODE;
    static IMode *SPOT_CLEAN_MODE;
    static IMode *FOLLOW_WALL_CLEAN_MODE;

    Robot();

    void KeyCb(const std_msgs::String::ConstPtr &msg);

private:
    ros::Subscriber key_sub_;
private:
    KeyVisit *normal_clean_key{new NormalCleanKeyVisit};
    KeyVisit *spot_clean_key{new SpotCleanKeyVisit};
    KeyVisit *follow_wall_clean_key{new FollowWallCleanKeyVisit};
    IMode *p_mode_{IDLE_MODE};
public:
    IMode *getMode() const;

    void setMode(IMode *p_mode_);
};



#endif //PATH_PLAN_PATH_PLAN_H
