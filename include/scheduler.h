#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "tcb-queue.h"

class Scheduler
{
public:
    virtual int scale(TCBQueue *queue) = 0;
};

#endif
