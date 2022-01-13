#include <stdio.h>
#include <stdlib.h>
#include "src/Headers/Timer.h"
#include "src/Headers/LinearSearch.h"
#include "src/Headers/BinarySearch.h"
#include "src/Headers/ClosestPoint.h"
#include "src/Headers/Sieve.h"
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
        printf("Found 100 in randomIntArray");
    }
    else
    {
        PrintWarning("100 not found in randomIntArray");
    }
    DisposeLinearSearch(&linear);
    printf("\n");

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
        PrintInformation("Found 12 in sortedIntArray");
    }
    DisposeBinarySearch(&binary);
    printf("\n");

    Sieve sieve = InitSieve();
    int sieveUpperLimit = 10000;
    sieve.PrintInformation(&sieve.Information);
    char* msg = (char*)calloc(1000, sizeof(char));
    sprintf(msg, "Primes in range [0, %i]", sieveUpperLimit);
    PrintInformation(msg);
    sieve.Run(sieveUpperLimit);
    DisposeSieve(&sieve);
    printf("\n");

    ClosestPoint closestPoint = InitClosestPoint();
    Point* points = (Point*)calloc(100, sizeof(Point));
    if (points != NULL)
    {
        for (int i = 0; i < 100; i++)
        {
            points[i].x = 1.0f * (rand() % 500);
            points[i].y = 1.0f * (rand() % 500);
        }
        closestPoint.PrintInformation(&closestPoint.Information);
        PrintInformation("Find number of points whose distance is < 200. N = 100, xMax = 500, yMax = 500");
        int pointCount = closestPoint.Run(points, 100, 200);
        sprintf(msg, "%i point pairs whose distance < 200", pointCount);
        PrintInformation(msg);
        DisposeClosestPoint(&closestPoint);
        free(points);
    }

    timer.Start(&timerData);

    // Do some work here

    timer.Stop(&timerData);
    timer.Dtor(&timerData);

    free(msg);

    // TODO: Remove this stuff at some point
    printf("\n\n\nPress any key to exit...\n");
    char trash = getchar();
    return 0;
}
