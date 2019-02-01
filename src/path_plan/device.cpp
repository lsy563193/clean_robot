//
// Created by syue on 19-2-1.
//

#include "device.h"
#include "boost/assign.hpp"
#include "mode.h"

void Device::normalClean() {
    ROS_INFO("Open");
}

void Device::idle() {
    ROS_INFO("Close");
}

void Vaccum::normalClean() {
    ROS_INFO("Vaccum Open");
}

void Vaccum::idle() {
    ROS_INFO("Vaccum idle");
}

void Vaccum::spotClean() {
    ROS_INFO("Vaccum spotClean");
}

void Brush::normalClean() {
    ROS_INFO("Brush normalClean");
}
void Brush::idle() {
    ROS_INFO("Brush idle");
}

void Brush::spotClean() {
    ROS_INFO("Brush spotClean");
}

void WaterTank::normalClean() {
    ROS_INFO("WaterTank normalClean");
}

void WaterTank::idle() {
    ROS_INFO("WaterTank idle");
}

void WaterTank::spotClean() {
    ROS_INFO("WaterTank spotClean");
}

void Speaker::normalClean() {
    ROS_INFO("Speaker normalClean");
}

void Speaker::idle() {
    ROS_INFO("Speaker idle");
}

void Speaker::spotClean() {
    ROS_INFO("Speaker spotClean");
}

Devices::Devices() {
    using namespace boost::assign;
    devices_ += new WaterTank,new Brush, new Vaccum, new Speaker;
}

void Devices::action()const {

}

void Devices::idle() {
    for(auto&& dev:devices_)
    {
        dev->idle();
    }
}

void Devices::normalClean() {
    for(auto&& dev:devices_)
    {
        dev->normalClean();
    }
}
void Devices::spotClean() {
    for(auto&& dev:devices_)
    {
        dev->normalClean();
    }
}
void Devices::followWallClean() {
    for(auto&& dev:devices_)
    {
        dev->normalClean();
    }
}
