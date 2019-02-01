//
// Created by syue on 19-2-1.
//

#include "mode.h"

//void FollowWallCleanMode::clean() {
//    ROS_INFO("FollowWallCleanMode::clean()");
//}
Robot* IMode::robot{};

IMode::~IMode() {
    ROS_INFO("~IMode");
}

Robot *IMode::getRobot() const {
    return robot;
}

void IMode::setRobot(Robot *robot) {
    IMode::robot = robot;
}


//void IMode::accept(KeyVisit *visit) {
//    visit->visit(this);
//}
void IdleMode::accept(KeyVisit *key) {
    key->visit(this);
}

void IdleMode::exit() {
    ROS_INFO("IdleMode::exit()");
}

void NormalCleanMode::accept(KeyVisit *key) {
    key->visit(this);
}

void NormalCleanMode::exit() {
    ROS_INFO("NormalCleanMode::exit()");
}
