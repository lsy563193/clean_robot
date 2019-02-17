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
    virtual void exploration() =0;
    virtual void followWallClean() =0;
};

class Vaccum:public Device{
public:
   void normalClean() override;
   void spotClean() override;
   void idle() override;
   void exploration() override;
   void followWallClean() override;
};
class Brush:public Device{
public:
   void normalClean() override;
   void spotClean() override;
   void idle() override;
   void exploration() override;
   void followWallClean() override;
};
class WaterTank:public Device{
public:
   void normalClean() override;
   void spotClean() override;
   void idle() override;
   void exploration() override;
   void followWallClean() override;
};
class Speaker:public Device{
public:
   Speaker();
   void normalClean() override;
   void spotClean() override;
   void idle() override;
   void exploration() override;
   void followWallClean() override;

private:
    ros::Publisher speaker_pub_;
    bool is_power_up_{};
};

class Gyro:public Device{
public:
   Gyro() = default;
   void normalClean() override;
   void spotClean() override;
   void idle() override;
   void exploration() override;
   void followWallClean() override;

private:
    ros::Publisher speaker_pub_;
    bool is_power_up_{};
};

using SpDevide = std::shared_ptr<Device>;
class Devices{
public:
    void idle();
    void normalClean();
    void spotClean();
    void followWallClean();
    void exploration();
    Devices();
    void action()const;

private:

    std::vector<SpDevide> devices_;
};
using SpDevides = std::shared_ptr<Devices>;
#endif //PATH_PLAN_DEVICE_H
