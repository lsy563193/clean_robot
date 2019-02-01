//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_DEVICE_H
#define PATH_PLAN_DEVICE_H

#include "ros/ros.h"
class Robot;

class Device {
public:
    virtual void normalClean() =0 ;
    virtual void spotClean() =0 ;
    virtual void idle() =0;
};

class Vaccum:public Device{
public:
   void normalClean();
   void spotClean();
   void idle();
};
class Brush:public Device{
public:
   void normalClean();
   void spotClean();
   void idle();
};
class WaterTank:public Device{
public:
   void normalClean();
   void spotClean();
   void idle();
};
class Speaker:public Device{
public:
   void normalClean();
   void spotClean();
   void idle();
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
