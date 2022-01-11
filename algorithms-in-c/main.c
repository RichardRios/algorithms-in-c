#include <stdio.h>
#include <stdlib.h>
#include "src/Headers/Timer.h"
#include "src/Headers/LinearSearch.h"
#include "src/Headers/BinarySearch.h"
#include "src/Headers/Internal/PrintHelpers.h"

#define STR_LEN 256

// TODO: Refactor most, if not all, to Driver.c
int main(int argc, char** argv)
{
    int findCount = 0;
    Timer timer = GetNewTimer();
    TimerData timerData = timer.Init();

    srand((unsigned int)time(NULL));

    LinearSearch linear = InitLinearSearch();
    linear.PrintInformation(&linear.Information);
    int randomIntArray[20] = { 0 };
    for (int i = 0; i < 20; i++)
    {
        randomIntArray[i] = (int)(rand() % 1000);
    }

    // Basic sanity check
    if (linear.Run(randomIntArray, 100, 20))
    {
        printf("Found 100 in randomIntArray\n");
    }
    DisposeLinearSearch(&linear);

    BinarySearch binary = InitBinarySearch();
    binary.PrintInformation(&binary.Information);
    int sortedIntArray[20] = { 0 };
    for (int i = 0; i < 20; i++)
    {
        sortedIntArray[i] = i;
    }

    // Basic sanity check
    if (binary.Run(sortedIntArray, 12, 20))
    {
        printf("Found 12 in sortedIntArray\n");
    }
    DisposeBinarySearch(&binary);

    timer.Start(&timerData);

    // Do some work here

    timer.Stop(&timerData);
    timer.Dtor(&timerData);

    // TODO: Remove this stuff at some point
    printf("\n\n\nPress any key to exit...\n");
    char trash = getchar();
    return 0;
}
