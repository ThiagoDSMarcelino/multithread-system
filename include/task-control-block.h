#ifndef TASK_CONTROL_BLOCK_H
#define TASK_CONTROL_BLOCK_H

#include <string>

class TaskControlBlock
{
public:
    TaskControlBlock(int id, std::string color, int start_time, int duration, int priority, int *events);
    int get_id();
    int get_priority();

private:
    int id;
    std::string color;
    int start_time;
    int duration;
    int priority;
    int *events;
};

#endif