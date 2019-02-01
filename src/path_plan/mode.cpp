//
// Created by syue on 19-2-1.
//

#include "mode.h"

//void FollowWallCleanMode::clean() {
//    ROS_INFO("FollowWallCleanMode::clean()");
//}

IMode::~IMode() {
    ROS_INFO("~IMode");
}


//void IMode::accept(Visit *visit) {
//    visit->visit(this);
//}
void IdleMode::accept(Visit *visit) {
    visit->visit(this);
}

void IdleMode::exit() {
    ROS_INFO("IdleMode::exit()");
}

void NormalCleanMode::accept(Visit *visit) {
    visit->visit(this);
}

void NormalCleanMode::exit() {
    ROS_INFO("NormalCleanMode::exit()");
}
