#include <assert.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/Timer.h"

Timer TimerCtor()
{
	Timer timer =
	{
		.Init = Initialize,
		.Start = StartTimer,
		.Stop = EndTimer,
		.Now = GetTimeNow,
		.GetTimeTaken = TimeTaken,
		.Dtor = Destructor
	};

	return timer;
}

TimerData Initialize()
{
	TimerData data = 
	{
		(char*)malloc(sizeof(char) * 80),
		(char*)malloc(sizeof(char) * 80)
	};

	return data;
}

void Destructor(TimerData* timer)
{
	free(timer->StartTime);
	free(timer->EndTime);
}

/// <summary>
/// Set the time that a method started and the current clock ticks
/// </summary>
/// <param name="execInfo">struct</param>
void StartTimer(TimerData* timer)
{
	timer->ClockStart = clock();
	timer->StartTime = GetTimeNow();
}

/// <summary>
/// Set the time a method ended and the current clock ticks
/// </summary>
/// <param name="execInfo">struct</param>
void EndTimer(TimerData* timer)
{
	timer->ClockEnd = clock();
	timer->EndTime = GetTimeNow();
}

/// <summary>
/// Calculate the total time taken
/// </summary>
/// <param name="execInfo">struct</param>
double TimeTaken(TimerData* timer)
{
	timer->EllapsedTime = ((double)(timer->ClockEnd - timer->ClockStart));
	return timer->EllapsedTime;
}

/// <summary>
/// Get the current time formatted as ddd MMM DD HH24:mm:ss YYYY (Thu Aug 23 14:55:02 2001)
/// Must call free on returned value if stored
/// </summary>
/// <returns>char* representing current time string without newline</returns>
char* GetTimeNow()
{
	time_t rawtime;
	struct tm* info;
	char* buffer = (char*)malloc(sizeof(char) * 80);

	time(&rawtime);
	info = localtime(&rawtime);
	if (buffer != NULL)
	{
		strftime(buffer, 80, "%c\0", info);
	}
	return buffer;
}