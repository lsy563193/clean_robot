//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_DEVICE_H
#define PATH_PLAN_DEVICE_H

#include "ros/ros.h"
class Robot;

class Device {
public:
    virtual void open() =0 ;
    virtual void close() =0;
};

class Vaccum:public Device{
public:
   void open();
   void close();
};
class Brush:public Device{
public:
   void open();
   void close();
};
class WaterTank:public Device{
public:
   void open();
   void close();
};

class Devices{
public:
    void idle();
    void normalClean();
    void spotClean();
    void followWallClean();
    Devices();
    void action()const;

private:

    std::vector<Device*> devices_;
};
#endif //PATH_PLAN_DEVICE_H
