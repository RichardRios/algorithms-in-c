#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "Headers/Algo/LinearSearch.h"

bool LinearSearch(int* integerArray, int toFind, int arrayLength)
{
	bool found = false;

	for (int i = 0; i < arrayLength; i++)
	{
		if (integerArray[i] == toFind)
		{
			found = true;
			break;
		}
	}

	return found;
}