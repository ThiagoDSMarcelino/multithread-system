#include <iostream>
#include "thread-descriptor.h"
#include "thread-queue.h"

int main()
{
    ThreadQueue *queue = new ThreadQueue(10);

    ThreadDescriptor *t = queue->dequeue();

    if (t == NULL)
    {
        std::cout << "not dequeued\n";
    }

    for (int i = 0; i < 11; i++)
    {
        ThreadDescriptor *thread = new ThreadDescriptor(i, 2);

        bool success = queue->enqueue(thread);

        if (!success)
        {
            std::cout << "not queued\n";
        }
    }

    queue->dequeue();
    queue->enqueue(new ThreadDescriptor(11, 2));

    t = queue->dequeue();

    if (t == NULL)
    {
        std::cout << "empty\n";
    }

    while (t != NULL)
    {
        std::cout << t->get_id() << "\n";
        delete t;
        t = queue->dequeue();
    }

    delete queue;

    return 0;
}