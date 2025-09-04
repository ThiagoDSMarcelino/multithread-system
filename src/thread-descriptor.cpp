#include "thread-descriptor.h"

#include <stdexcept>

ThreadDescriptor::ThreadDescriptor(int id, int priority)
{
    if (id < 0)
    {
        throw std::invalid_argument("thread id cannot be less than 0");
    }

    this->id = id;
    this->priority = priority;
}

int ThreadDescriptor::get_id()
{
    return this->id;
}

int ThreadDescriptor::get_priority()
{
    return this->priority;
}