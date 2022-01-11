#ifndef DRIVER_H
#define DRIVER_H

#include <stdbool.h>
#include "Internal/AlgorithmOptions.h"

typedef struct Driver_s
{
	void(*Run)();
	void(*PrintHelp)();
	void(*RunTypeSelection)(Algorithm);
	void(*GetInformation)(Algorithm);
} Driver;

Driver Initialize();
void _Run();
void _PrintHelp();
void _RunTypeSelection(Algorithm);
void _GetInformation(Algorithm);

#endif
