#include <iostream>
#include "Start.h"

int main()
{
    Start start;
    do
    {
        start.Running();

    } while (start.choice2 == 1);

    return 0;
}