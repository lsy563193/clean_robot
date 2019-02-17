//
// Created by syue on 19-2-18.
//

#ifndef PATH_PLAN_COMMAND_H
#define PATH_PLAN_COMMAND_H


class Command {
    virtual void idle()=0;
    virtual void normalClean()=0;
    virtual void spotClean()=0;
    virtual void exploration() =0;
    virtual void followWallClean() =0;
};


#endif //PATH_PLAN_COMMAND_H
