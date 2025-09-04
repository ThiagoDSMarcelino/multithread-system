#ifndef THREAD_DESCRIPTOR_H
#define THREAD_DESCRIPTOR_H

class ThreadDescriptor
{
public:
    ThreadDescriptor(int id, int priority);
    int get_id();
    int get_priority();

private:
    int id;
    int priority;
};

#endif