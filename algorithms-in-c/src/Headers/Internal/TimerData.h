#ifndef TIMER_DATA_H
#define TIMER_DATA_H

#include <time.h>

typedef struct TimerData
{
	char* StartTime;
	char* EndTime;
	clock_t ClockStart;
	clock_t ClockEnd;
	double EllapsedTime;
} TimerData;

#endif