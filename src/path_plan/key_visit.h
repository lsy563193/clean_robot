//
// Created by syue on 19-2-1.
//

#ifndef PATH_PLAN_VISIT_H
#define PATH_PLAN_VISIT_H

#include "ros/ros.h"

class IdleMode;
class NormalCleanMode;
class SpotCleanMode;
class FollowWallCleanMode;
class ExplorationMode;


class KeyVisit {
public:
    virtual void visit(IdleMode *mode)=0;
    virtual void visit(NormalCleanMode *mode)=0;
    virtual void visit(SpotCleanMode *mode)=0;
    virtual void visit(FollowWallCleanMode *mode)=0;
    virtual void visit(ExplorationMode *mode)=0;
    virtual ~KeyVisit()= default;
};

class NormalCleanKeyVisit:public KeyVisit
{
public:
    void visit(IdleMode *mode) override;
    void visit(NormalCleanMode *mode) override;
    void visit(SpotCleanMode *mode) override;
    void visit(FollowWallCleanMode *mode) override;
    void visit(ExplorationMode *mode) override;
};

class SpotCleanKeyVisit:public KeyVisit
{
public:
    void visit(IdleMode *mode) override;
    void visit(NormalCleanMode *mode) override;
    void visit(SpotCleanMode *mode) override;
    void visit(FollowWallCleanMode *mode) override;
    void visit(ExplorationMode *mode) override;
};

class FollowWallCleanKeyVisit:public KeyVisit
{
public:
    void visit(IdleMode *mode) override;
    void visit(NormalCleanMode *mode) override;
    void visit(SpotCleanMode *mode) override;
    void visit(FollowWallCleanMode *mode) override;
    void visit(ExplorationMode *mode) override;
};

class ExplorationKeyVisit:public KeyVisit
{
public:
    void visit(IdleMode *mode) override;
    void visit(NormalCleanMode *mode) override;
    void visit(SpotCleanMode *mode) override;
    void visit(FollowWallCleanMode *mode) override;
    void visit(ExplorationMode *mode) override;
};

#endif //PATH_PLAN_VISIT_H
