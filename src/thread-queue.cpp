#include "thread-queue.h"
#include <cstdlib>

ThreadQueue::ThreadQueue(int capacity)
{
    this->head = 0;
    this->tail = 0;
    this->count = 0;
    this->capacity = capacity;
    this->data = (ThreadDescriptor **)malloc(sizeof(ThreadDescriptor) * capacity);
}

ThreadQueue::~ThreadQueue()
{
    free(this->data);
}

bool ThreadQueue::is_full()
{
    return this->count == this->capacity;
}

bool ThreadQueue::is_empty()
{
    return this->count == 0;
}

bool ThreadQueue::enqueue(ThreadDescriptor *descriptor)
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

ThreadDescriptor *ThreadQueue::dequeue()
{
    if (this->is_empty())
    {
        return NULL;
    }

    ThreadDescriptor *thread = this->data[this->head];
    this->head = (this->head + 1) % this->capacity;
    this->count--;

    return thread;
}

ThreadDescriptor *ThreadQueue::get_first()
{
    if (this->is_empty())
    {
        return NULL;
    }

    return this->data[this->head];
}