//
// Created by syue on 19-2-1.
//

#include "key_visit.h"
#include "mode.h"
#include "robot.h"

void CleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("start normal clean");
    mode->getRobot()->setMode(Robot::NORMAL_CLEAN_MODE);
    ROS_INFO("~start normal clean");
}

void CleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("stop clean");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
}
