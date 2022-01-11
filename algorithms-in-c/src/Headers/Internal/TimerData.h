#ifndef TIMERDATA_H
#define TIMERDATA_H

#include <time.h>

/// <summary>
/// Struct representing basic timer information
/// </summary>
typedef struct TimerData
{
	char* StartTime;
	char* EndTime;
	clock_t ClockStart;
	clock_t ClockEnd;
	double EllapsedTime;
} TimerData;

#endif