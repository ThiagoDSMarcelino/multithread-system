#include "tcb-queue.h"
#include <cstdlib>

TCBQueue::TCBQueue(int capacity)
{
    this->head = 0;
    this->tail = 0;
    this->count = 0;
    this->capacity = capacity;
    this->data = (TaskControlBlock **)malloc(sizeof(TaskControlBlock) * capacity);
}

TCBQueue::~TCBQueue()
{
    free(this->data);
}

bool TCBQueue::is_full()
{
    return this->count == this->capacity;
}

bool TCBQueue::is_empty()
{
    return this->count == 0;
}

bool TCBQueue::enqueue(TaskControlBlock *descriptor)
{
    if (this->is_full())
    {
        return false;
    }

    this->data[this->tail] = descriptor;
    this->tail = (this->tail + 1) % this->capacity;
    this->count++;

    return true;
}

TaskControlBlock *TCBQueue::dequeue()
{
    if (this->is_empty())
    {
        return NULL;
    }

    TaskControlBlock *thread = this->data[this->head];
    this->head = (this->head + 1) % this->capacity;
    this->count--;

    return thread;
}

TaskControlBlock *TCBQueue::get_first()
{
    if (this->is_empty())
    {
        return NULL;
    }

    return this->data[this->head];
}