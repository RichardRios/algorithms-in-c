#ifndef TIMER_H
#define TIMER_H

#include "Internal/TimerData.h"

typedef struct Timer
{
	TimerData(*Init)();
	void(*Start)(TimerData*);
	void(*Stop)(TimerData*);
	double(*GetTimeTaken)(TimerData*);
	char*(*Now)();
	void(*Dtor)(TimerData*);
} Timer;

Timer GetNewTimer();
TimerData InitializeTimerData();
void StartTimer(TimerData*);
void EndTimer(TimerData*);
double TimeTaken(TimerData*);
char* GetTimeNow();
void Destructor(TimerData*);

#endif