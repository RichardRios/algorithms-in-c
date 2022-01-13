#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Headers/BinarySearch.h"
#include "Headers/Internal/PrintHelpers.h"

BinarySearch InitBinarySearch()
{
	BinarySearch binarySearch =
	{
		.Run = RunBinarySearch,
		.PrintInformation = PrintBinarySearchInformation
	};

	binarySearch.Information = GetNewAlgorithmInfo();
	strcpy(binarySearch.Information.Name, "Binary Search");
	strcpy(binarySearch.Information.Runtime, "O(log N)");
	strcpy(binarySearch.Information.Caveats, "Array must be sorted prior to running search.");

	return binarySearch;
}

bool RunBinarySearch(int* integerArray, int toFind, int arraySize)
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

void PrintBinarySearchInformation(AlgorithmInformation* information)
{
	PrintAlgorithmInformation(information);
}

void DisposeBinarySearch(BinarySearch* search)
{
	DisposeAlgorithmInformation(&search->Information);
}