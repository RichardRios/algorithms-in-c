#ifndef BASE_H
#define BASE_H

#include <stdbool.h>
#include "AlgorithmOptions.h"

typedef struct Base_s
{
	bool(*Execute)();
	int(*PrintInformation)(Algorithm selection);
} Base;

#endif
