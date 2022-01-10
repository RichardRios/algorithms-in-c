#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "Headers/Algo/LinearSearch/LinearSearch.h"

bool LinearSearch(int* integerArray, int toFind, int arrayLength)
{
	bool found = false;
	int foundIndex = -1;

	for (int i = 0; i < arrayLength; i++)
	{
		if (integerArray[i] == toFind)
		{
			found = true;
			foundIndex = i;
			printf("print to break optimization\n");
			break;
		}
	}

	return found;
}