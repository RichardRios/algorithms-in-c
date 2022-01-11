#include <assert.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/Timer.h"

Timer GetNewTimer()
{
	Timer timer =
	{
		.Init = InitializeTimerData,
		.Start = StartTimer,
		.Stop = EndTimer,
		.Now = GetTimeNow,
		.GetTimeTaken = TimeTaken,
		.Dtor = Destructor
	};

	return timer;
}

/*
 *					InitializeTimerData
 * 
 * Get a TimerData struct with Start and Stop properties
 * initialized to an 80-length character buffer.
 * 
 * Parameters:
 * 
 * Returns:
 *		TimerData struct
 */
TimerData InitializeTimerData()
{
	const int TIME_LENGTH = 256;
	TimerData data = 
	{
		(char*)calloc(TIME_LENGTH, sizeof(char)),
		(char*)calloc(TIME_LENGTH, sizeof(char))
	};

	return data;
}

/*
 *					Destructor
 * 
 * Frees memory allocated to the TimerData struct properties.
 * 
 * Parameters:
 *		timer: Pointer to TimerData struct
 * 
 * Returns:
 * 
 */
void Destructor(TimerData* timer)
{
	free(timer->StartTime);
	free(timer->EndTime);
}

/* 
 *					StartTimer
 * 
 * Set the time that a method started and the current clock ticks
 * 
 * Parameters:
 *		timer: Pointer to TimerData struct
 * 
 * Returns:
 * 
 */
void StartTimer(TimerData* timer)
{
	timer->ClockStart = clock();
	timer->StartTime = GetTimeNow();
}

/* 
 *					EndTimer
 *
 * Set the time a method ended and the current clock ticks
 * 
 * Parameters:
 *		timer: Pointer to TimerData struct
 * 
 * Returns:
 * 
 */
void EndTimer(TimerData* timer)
{
	timer->ClockEnd = clock();
	timer->EndTime = GetTimeNow();
}

/* 
 *					TimeTaken
 * 
 * Calculate the total time taken
 * 
 * Parameters:
 *		timer: Pointer to TimerData struct
 * 
 * Returns:
 *		double representing ellapsed time in ms since timer started
 */
double TimeTaken(TimerData* timer)
{
	timer->EllapsedTime = ((double)(timer->ClockEnd - timer->ClockStart))/((clock_t)1000);
	return timer->EllapsedTime;
}

/* 
 *					GetTimeNow
 * 
 * Get the current time formatted as ddd MMM DD HH24:mm:ss YYYY (Thu Aug 23 14:55:02 2001)
 * Must call free on returned value.
 * 
 * Parameters:
 *		
 * Returns:
 *		char* representing formatted date/time string
 */
char* GetTimeNow()
{
	time_t rawtime;
	struct tm* info;
	char* buffer = (char*)calloc(100, sizeof(char));

	time(&rawtime);
	info = localtime(&rawtime);
	if (buffer != NULL)
	{
		strftime(buffer, 100, "%c\0", info);
	}

	return buffer;
}