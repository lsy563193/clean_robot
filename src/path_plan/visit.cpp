//
// Created by syue on 19-2-1.
//

#include "visit.h"

void CleanVisit::visit(IdleMode *mode) {
    ROS_INFO("start clean");
}

void CleanVisit::visit(NormalCleanMode *mode) {
    ROS_INFO("stop clean");
}
