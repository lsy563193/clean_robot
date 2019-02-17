//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_DEVICE_H
#define PATH_PLAN_DEVICE_H

#include "ros/ros.h"
#include "command.h"

class Robot;

class Device: private Command {
public:
    Device();
    virtual void idle() =0;
    virtual void normalClean() =0 ;
    virtual void spotClean() =0 ;
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
class Devices:private Command{
public:
    void idle() override ;
    void normalClean()override;
    void spotClean()override;
    void followWallClean()override;
    void exploration()override;
    Devices();
    void action()const;

private:

    std::vector<SpDevide> devices_{};

    SpDevide pWaterTank{new WaterTank};
    SpDevide pBrush{new Brush};
    SpDevide pVaccum{new Vaccum};
    SpDevide pSpeaker{new Speaker};
    SpDevide pGyro{new Gyro};

};
using SpDevides = std::shared_ptr<Devices>;
#endif //PATH_PLAN_DEVICE_H
