#ifndef THREAD_QUEUE_H
#define THREAD_QUEUE_H

#include "thread-descriptor.h"

class ThreadQueue
{
public:
    void push(ThreadDescriptor *thread);
    ThreadDescriptor *pop();
    ThreadDescriptor *peek();
};

#endif