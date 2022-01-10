#pragma once
#include "Internal/TimerData.h"


typedef struct Timer
{
	TimerData(*Init)();
	void(*Start)(TimerData*);
	void(*Stop)(TimerData*);
	double(*GetTimeTaken)(TimerData*);
	char*(*Now)();
	void(*SetSampleSize)(int);
	int(*GetSampleSize)();
	void(*Dtor)(TimerData*);
} Timer;

Timer TimerCtor();
TimerData Initialize();
void StartTimer(TimerData*);
void EndTimer(TimerData*);
double TimeTaken(TimerData*);
char* GetTimeNow();
void Destructor(TimerData*);