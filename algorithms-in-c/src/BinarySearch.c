#include "Headers/BinarySearch.h"

bool BinarySearch(int* integerArray, int toFind, int arraySize)
{
	int rhsBoundary = arraySize - 1;
	int lhsBoundary = 0;

	while (lhsBoundary <= rhsBoundary)
	{
		int midpoint = ((rhsBoundary + lhsBoundary) / 2);

		if (integerArray[midpoint] < toFind)
		{
			lhsBoundary = midpoint + 1;
		}
		else if(integerArray[midpoint] > toFind)
		{
			rhsBoundary = midpoint - 1;
		}
		else
		{
			return true;
		}
	}

	return false;
}