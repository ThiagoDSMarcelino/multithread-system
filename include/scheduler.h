#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "thread-queue.h"

class Scheduler
{
public:
    virtual int scale(ThreadQueue *queue) = 0;
};

#endif
