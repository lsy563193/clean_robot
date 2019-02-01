//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_MODE_H
#define PATH_PLAN_MODE_H

#include "ros/ros.h"
#include "key_visit.h"

class Robot;
class IMode {
public:
    virtual void exit()=0;
    virtual void accept(KeyVisit* key) = 0;
    virtual ~IMode();
    Robot *getRobot() const;

private:
    static Robot* robot;
public:
    static void setRobot(Robot *robot);
};

class IdleMode: public IMode{
public:
    void exit();
    void accept(KeyVisit* key);
};

//class ACleanMode:public IMode{
//    virtual void clean() = 0;
//};

class NormalCleanMode: public IMode{
public:
    void exit();
    void accept(KeyVisit* key);
};

class SpotCleanMode: public IMode{
public:
    void exit();
    void accept(KeyVisit* key);
};

class FollowWallCleanMode: public IMode{
public:
    void exit();
    void accept(KeyVisit* key);
};

//class FollowWallCleanMode: public ACleanMode{
//public:
//    void clean();
//};
#endif //PATH_PLAN_MODE_H
