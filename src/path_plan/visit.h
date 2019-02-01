//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_VISIT_H
#define PATH_PLAN_VISIT_H

#include "ros/ros.h"

class IdleMode;
class NormalCleanMode;


class Visit {
public:
    virtual void visit(IdleMode *mode)=0;
    virtual void visit(NormalCleanMode *mode)=0;
    virtual ~Visit()= default;
};

class CleanVisit:public Visit
{
public:
    void visit(IdleMode *mode);
    void visit(NormalCleanMode *mode);
};

#endif //PATH_PLAN_VISIT_H
