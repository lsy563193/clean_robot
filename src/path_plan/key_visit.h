//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_VISIT_H
#define PATH_PLAN_VISIT_H

#include "ros/ros.h"

class IdleMode;
class NormalCleanMode;


class KeyVisit {
public:
    virtual void visit(IdleMode *mode)=0;
    virtual void visit(NormalCleanMode *mode)=0;
    virtual ~KeyVisit()= default;
};

class CleanKeyVisit:public KeyVisit
{
public:
    void visit(IdleMode *mode);
    void visit(NormalCleanMode *mode);
};

#endif //PATH_PLAN_VISIT_H
