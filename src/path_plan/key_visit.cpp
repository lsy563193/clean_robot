//
// Created by syue on 19-2-1.
//

#include "key_visit.h"
#include "mode.h"
#include "robot.h"

void NormalCleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle -> normal clean");
    mode->getRobot()->setMode(Robot::NORMAL_CLEAN_MODE);
}

void NormalCleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> idle");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
}

void NormalCleanKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> idle");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
}

void NormalCleanKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("follow wall clean -> idle");
    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
}

void SpotCleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle -> spot clean");
    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
}

void SpotCleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> tmp spot clean");
    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
}

void SpotCleanKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> idle");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
}
void SpotCleanKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("spot clean -> spot clean");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
}

void FollowWallCleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle clean -> follow wall clean");
    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
}

void FollowWallCleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> tmp follow wall clean");
    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
}

void FollowWallCleanKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> spot clean");
    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
}

void FollowWallCleanKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("follow clean clean -> idle clean");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
}
