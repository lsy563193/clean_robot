//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_MODE_H
#define PATH_PLAN_MODE_H

#include "ros/ros.h"
#include "visit.h"

class IMode {
public:
    virtual void exit()=0;
    virtual void accept(Visit* visit) = 0;
    virtual ~IMode();
};

class IdleMode: public IMode{
public:
    void exit();
    void accept(Visit* visit);
};

//class ACleanMode:public IMode{
//    virtual void clean() = 0;
//};

class NormalCleanMode: public IMode{
public:
    void exit();
    void accept(Visit* visit);
};

//class FollowWallCleanMode: public ACleanMode{
//public:
//    void clean();
//};
#endif //PATH_PLAN_MODE_H
