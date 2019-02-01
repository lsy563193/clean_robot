//
// Created by syue on 19-2-1.
//

#include "mode.h"
#include "robot.h"

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

void IdleMode::updateDevice() {
    getRobot()->getDevices()->idle();
}

void NormalCleanMode::accept(KeyVisit *key) {
    key->visit(this);
}

void NormalCleanMode::exit() {
    ROS_INFO("NormalCleanMode::exit()");
}

void NormalCleanMode::updateDevice() {
    ROS_INFO("NormalCleanMode updateDevice");
    getRobot()->getDevices()->normalClean();
}

void SpotCleanMode::exit() {
    ROS_INFO("SpotCleanMode::exit()");
}

void SpotCleanMode::accept(KeyVisit *key) {
    key->visit(this);
}

void SpotCleanMode::updateDevice() {
    getRobot()->getDevices()->spotClean();
}

void FollowWallCleanMode::exit() {
    ROS_INFO("FollowWallCleanMode::exit()");
}

void FollowWallCleanMode::accept(KeyVisit *key) {
    key->visit(this);
}

void FollowWallCleanMode::updateDevice() {
    getRobot()->getDevices()->followWallClean();
}

//void IMode::updateDevice() {
//    devices.action();
//}