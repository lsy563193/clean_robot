//
// Created by syue on 19-2-1.
//

#include "device.h"
#include "boost/assign.hpp"
#include "mode.h"

void Device::open() {
    ROS_INFO("Open");
}

void Device::close() {
    ROS_INFO("Close");
}

void Vaccum::open() {
    ROS_INFO("Vaccum Open");
}

void Vaccum::close() {
    ROS_INFO("Vaccum close");
}
void Brush::open() {
    ROS_INFO("Brush Open");
}
void Brush::close() {
    ROS_INFO("Brush close");
}

void WaterTank::open() {
    ROS_INFO("Brush Open");
}

void WaterTank::close() {
    ROS_INFO("Brush close");
}

Devices::Devices() {
    using namespace boost::assign;
    devices_ += new WaterTank,new Brush, new Vaccum;
}

void Devices::action()const {

}

void Devices::idle() {
    for(auto&& dev:devices_)
    {
        dev->close();
    }
}

void Devices::normalClean() {
    for(auto&& dev:devices_)
    {
        dev->open();
    }
}
void Devices::spotClean() {
    for(auto&& dev:devices_)
    {
        dev->open();
    }
}
void Devices::followWallClean() {
    for(auto&& dev:devices_)
    {
        dev->open();
    }
}
