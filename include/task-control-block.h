#ifndef TASK_CONTROL_BLOCK_H
#define TASK_CONTROL_BLOCK_H

class TaskControlBlock
{
public:
    TaskControlBlock(int id, int priority);
    int get_id();
    int get_priority();

private:
    int id;
    int priority;
};

#endif