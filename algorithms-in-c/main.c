#include <stdio.h>
#include <stdlib.h>

#include "src/Headers/Timer.h"
#include "src/Headers/LinearSearch.h"
#include "src/Helpers/Headers/PrintHelpers.h"

int main(int argc, char** argv)
{
    int findCount = 0;
    Timer timer = GetNewTimer();
    TimerData timerData = timer.Init();
    char* test;
    sprintf(&test, "The current time is: %s\n", timer.Now());
    PrintInformation(&test);
    free(test);

    srand((unsigned int)time(NULL));
    
    timer.Start(&timerData);

    // Do some work here

    timer.Stop(&timerData);

    timer.Dtor(&timerData);

    // TODO: Remove this stuff at some point
    printf("\n\n\nPress any key to exit...\n");
    char trash = getchar();
    return 0;
}
