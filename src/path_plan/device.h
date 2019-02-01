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
   void normalClean() override;
   void spotClean() override;
   void idle() override;
};
class Brush:public Device{
public:
   void normalClean() override;
   void spotClean() override;
   void idle() override;
};
class WaterTank:public Device{
public:
   void normalClean() override;
   void spotClean() override;
   void idle() override;
};
class Speaker:public Device{
public:
   Speaker();
   void normalClean() override;
   void spotClean() override;
   void idle() override;

private:
    ros::Publisher speaker_pub_;
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
