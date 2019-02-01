//
// Created by syue on 19-2-1.
//

#include "key_visit.h"
#include "mode.h"
#include "robot.h"

void NormalCleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle -> normal clean");
    mode->getRobot()->setMode(Robot::NORMAL_CLEAN_MODE);
    mode->getRobot()->work();
}

void NormalCleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> idle");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
    mode->getRobot()->work();
}

void NormalCleanKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> idle");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
    mode->getRobot()->work();
}

void NormalCleanKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("follow wall clean -> idle");
    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
    mode->getRobot()->work();
}

void NormalCleanKeyVisit::visit(ExplorationMode *mode) {
    ROS_INFO("exploration clean -> idle");
    mode->getRobot()->setMode(Robot::EXPLORATION_MODE);
    mode->getRobot()->work();
}

void SpotCleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle -> spot clean");
    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
    mode->getRobot()->work();
}

void SpotCleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> tmp spot clean");
    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
    mode->getRobot()->work();
}

void SpotCleanKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> idle");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
    mode->getRobot()->work();
}
void SpotCleanKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("spot clean -> spot clean");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
    mode->getRobot()->work();
}

void SpotCleanKeyVisit::visit(ExplorationMode *mode) {
//    ROS_INFO("spot clean -> spot clean");
//    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
//    mode->getRobot()->work();
}

void FollowWallCleanKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle clean -> follow wall clean");
    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
    mode->getRobot()->work();
}

void FollowWallCleanKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> tmp follow wall clean");
    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
    mode->getRobot()->work();
}

void FollowWallCleanKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> spot clean");
    mode->getRobot()->setMode(Robot::SPOT_CLEAN_MODE);
    mode->getRobot()->work();
}

void FollowWallCleanKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("follow clean clean -> idle clean");
    mode->getRobot()->setMode(Robot::IDLE_MODE);
    mode->getRobot()->work();
}

void FollowWallCleanKeyVisit::visit(ExplorationMode *mode) {
//    ROS_INFO("follow clean clean -> follow wall clean");
//    mode->getRobot()->setMode(Robot::FOLLOW_WALL_CLEAN_MODE);
//    mode->getRobot()->work();

}

void ExplorationKeyVisit::visit(IdleMode *mode) {
    ROS_INFO("idle -> exploration");
    mode->getRobot()->setMode(Robot::EXPLORATION_MODE);
    mode->getRobot()->work();
}

void ExplorationKeyVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("normal clean -> exploration");
    mode->getRobot()->setMode(Robot::EXPLORATION_MODE);
    mode->getRobot()->work();
}

void ExplorationKeyVisit::visit(SpotCleanMode *mode) {
    ROS_INFO("spot clean -> exploration");
    mode->getRobot()->setMode(Robot::EXPLORATION_MODE);
    mode->getRobot()->work();
}

void ExplorationKeyVisit::visit(FollowWallCleanMode *mode) {
    ROS_INFO("follow wall clean -> exploration");
    mode->getRobot()->setMode(Robot::EXPLORATION_MODE);
    mode->getRobot()->work();
}

void ExplorationKeyVisit::visit(ExplorationMode *mode) {
    ROS_INFO("exploration -> idle");
    mode->getRobot()->setMode(Robot::EXPLORATION_MODE);
    mode->getRobot()->work();
}
