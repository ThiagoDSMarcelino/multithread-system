#ifndef TASK_CONTROL_BLOCK_H
#define TASK_CONTROL_BLOCK_H

class TaskControlBlock
{
public:
    TaskControlBlock(int id, const char *color, int start_time, int duration, int priority, int *events);
    int get_id();
    int get_priority();

private:
    int id;
    const char *color;
    int start_time;
    int duration;
    int priority;
    int *events;
};

#endif