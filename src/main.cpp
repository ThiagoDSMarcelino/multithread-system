#include <iostream>
#include "tcb-queue.h"

int main()
{
    TCBQueue *queue = new TCBQueue(10);

    TaskControlBlock *tcb = queue->dequeue();

    if (tcb == NULL)
    {
        std::cout << "not dequeued\n";
    }

    for (int i = 0; i < 11; i++)
    {
        tcb = new TaskControlBlock(i, 2);

        bool success = queue->enqueue(tcb);

        if (!success)
        {
            std::cout << "not queued\n";
        }
    }

    queue->dequeue();
    queue->enqueue(new TaskControlBlock(11, 2));

    tcb = queue->dequeue();

    if (tcb == NULL)
    {
        std::cout << "empty\n";
    }

    while (tcb != NULL)
    {
        std::cout << tcb->get_id() << "\n";
        delete tcb;
        tcb = queue->dequeue();
    }

    delete queue;

    return 0;
}