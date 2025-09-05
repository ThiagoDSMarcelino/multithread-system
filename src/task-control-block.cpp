#include "task-control-block.h"

#include <stdexcept>

TaskControlBlock::TaskControlBlock(int id, std::string color, int start_time, int duration, int priority, int *events)
{
    if (id < 0)
    {
        throw std::invalid_argument("thread id cannot be less than 0");
    }

    this->id = id;
    this->color = color;
    this->start_time = start_time;
    this->duration = duration;
    this->priority = priority;
    this->events = events;
}

int TaskControlBlock::get_id()
{
    return this->id;
}

int TaskControlBlock::get_priority()
{
    return this->priority;
}