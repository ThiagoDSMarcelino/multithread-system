#include <iostream>
#include "thread-descriptor.h"

int main()
{
    ThreadDescriptor *a = new ThreadDescriptor(1, 2);

    std::cout << a->get_id() << "\n";

    return 0;
}