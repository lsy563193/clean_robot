//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_MODE_H
#define PATH_PLAN_MODE_H

#include "ros/ros.h"
#include "key_visit.h"
#include "device.h"

class Robot;
class IMode:public std::enable_shared_from_this<IMode> {
public:
    virtual void exit()=0;
    virtual void accept(KeyVisit* key) = 0;
    virtual ~IMode();

    IMode();

    Robot *getRobot() const;

    virtual void updateDevice()=0;

private:
    static Robot* robot;
public:
    static void setRobot(Robot *robot);
};

class IdleMode: public IMode{
public:
    IdleMode();

    void exit() override;
    void accept(KeyVisit* key);
    void updateDevice() override;

};

//class ACleanMode:public IMode{
//    virtual void clean() = 0;
//};

class NormalCleanMode: public IMode{
public:
    void exit() override;
    void accept(KeyVisit* key);
    void updateDevice();
};

class SpotCleanMode: public IMode{
public:
    void exit();
    void accept(KeyVisit* key);
    void updateDevice();
};

class FollowWallCleanMode: public IMode{
public:
    void exit();
    void accept(KeyVisit* key);
    void updateDevice();
};

class ExplorationMode: public IMode{
public:
    void exit() override;
    void accept(KeyVisit* key);
    void updateDevice() override;
};

//class FollowWallCleanMode: public ACleanMode{
//public:
//    void clean();
//};
#endif //PATH_PLAN_MODE_H
