#ifndef TCB_QUEUE_H
#define TCB_QUEUE_H

#include "task-control-block.h"

class TCBQueue
{
public:
    TCBQueue(int capacity);
    ~TCBQueue();
    bool enqueue(TaskControlBlock *descriptor);
    TaskControlBlock *dequeue();
    TaskControlBlock *get_first();
    bool is_full();
    bool is_empty();

private:
    int capacity;
    int head;
    int tail;
    int count;
    TaskControlBlock **data;
};

#endif