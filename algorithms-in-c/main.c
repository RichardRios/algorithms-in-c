#include <stdio.h>
#include <stdlib.h>

#include "src/Headers/Timer.h"
#include "src/Headers/Algo/LinearSearch/LinearSearch.h"

#define N       100000000
#define ITER    10

int main(int argc, char** argv)
{
    int findCount = 0;
    Timer timer = TimerCtor();
    TimerData timerData = timer.Init();
    printf("Current time is: %s\n", timer.Now());

    srand((unsigned int)time(NULL));
    
    int* arrayValues = (int*)malloc(sizeof(int) * N);
    double totalTimeTaken = 0;

    if (arrayValues == NULL) 
    { 
        exit(3); 
    }

    for (int o = 0; o < ITER; o++)
    {
        for (int i = 0; i < N; i++)
        {
            arrayValues[i] = rand();
        }

        int randomSelection = rand() % N;
        timer.Start(&timerData);
        bool isFound = LinearSearch(arrayValues, arrayValues[randomSelection], N);
        timer.Stop(&timerData);

        if (isFound)
        {
            ++findCount;
            printf("Found element %i in %.9f\n", randomSelection, timer.GetTimeTaken(&timerData));
        }
    }
    timer.Dtor(&timerData);
    free(arrayValues);
    printf("\n\n\nPress any key to exit...\n");
    char trash = getchar();
    return 0;
}
