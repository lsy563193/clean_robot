//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_PATH_PLAN_H
#define PATH_PLAN_PATH_PLAN_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "mode.h"
#include "device.h"

using SpMode = std::shared_ptr<IMode>;
class Robot {
public:
    static SpMode IDLE_MODE;
    static SpMode NORMAL_CLEAN_MODE;
    static SpMode SPOT_CLEAN_MODE;
    static SpMode FOLLOW_WALL_CLEAN_MODE;
    static SpMode EXPLORATION_MODE;

    Robot();

    void KeyCb(const std_msgs::String::ConstPtr &msg);

private:
    ros::Subscriber key_sub_;
private:
    KeyVisit *normal_clean_key{new NormalCleanKeyVisit};
    KeyVisit *spot_clean_key{new SpotCleanKeyVisit};
    KeyVisit *follow_wall_clean_key{new FollowWallCleanKeyVisit};
    KeyVisit *exploration_key{new ExplorationKeyVisit};
    SpMode p_mode_{};
    SpDevides devices{new Devices};
public:
    SpDevides getDevices() const;

public:

public:
//    SpMode getMode() const;

    void setMode(SpMode p_mode_);

    void work();
};



#endif //PATH_PLAN_PATH_PLAN_H
