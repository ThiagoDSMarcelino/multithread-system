#include "task-control-block.h"

#include <stdexcept>

TaskControlBlock::TaskControlBlock(int id, int priority)
{
    if (id < 0)
    {
        throw std::invalid_argument("thread id cannot be less than 0");
    }

    this->id = id;
    this->priority = priority;
}

int TaskControlBlock::get_id()
{
    return this->id;
}

int TaskControlBlock::get_priority()
{
    return this->priority;
}