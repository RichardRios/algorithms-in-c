#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/LinearSearch.h"
#include "Headers/Internal/PrintHelpers.h"

LinearSearch InitLinearSearch()
{
	LinearSearch retVal =
	{
		.Run = RunLinearSearch,
		.PrintInformation = PrintLinearSearchInformation
	};

	retVal.Information = GetNewAlgorithmInfo();

	strcpy(retVal.Information.Name, "Linear Search");
	strcpy(retVal.Information.Runtime, "O(N)");
	strcpy(retVal.Information.Caveats, "None");

	return retVal;
}

bool RunLinearSearch(int* integerArray, int toFind, int arrayLength)
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

void PrintLinearSearchInformation(AlgorithmInformation* information)
{
	PrintAlgorithmInformation(information);
}

void DisposeLinearSearch(LinearSearch* linearSearch)
{
	free(linearSearch->Information.Name);
	free(linearSearch->Information.Runtime);
	free(linearSearch->Information.Caveats);
}