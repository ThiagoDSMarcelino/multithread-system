#ifndef THREAD_QUEUE_H
#define THREAD_QUEUE_H

#include "thread-descriptor.h"

class ThreadQueue
{
public:
    ThreadQueue(int capacity);
    ~ThreadQueue();
    bool enqueue(ThreadDescriptor *descriptor);
    ThreadDescriptor *dequeue();
    ThreadDescriptor *get_first();
    bool is_full();
    bool is_empty();

private:
    int capacity;
    int head;
    int tail;
    int count;
    ThreadDescriptor **data;
};

#endif