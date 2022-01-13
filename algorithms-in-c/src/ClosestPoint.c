#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Headers/ClosestPoint.h"
#include "Headers/Internal/PrintHelpers.h"

ClosestPoint InitClosestPoint()
{
	ClosestPoint closestPoint =
	{
		.Run = RunClosestPoint,
		.PrintInformation = PrintClosestPointInformation
	};

	closestPoint.Information = GetNewAlgorithmInfo();
	strcpy(closestPoint.Information.Name, "Closest Point Computation");
	strcpy(closestPoint.Information.Runtime, "O(N^2)");
	strcpy(closestPoint.Information.Caveats, "Is not viable for large datasets.");

	return closestPoint;
}

int RunClosestPoint(Point* pointArray, int arrayLength, int maxDistance)
{
	if (arrayLength <= 0) { return false; }
	
	int count = 0;

	for (int i = 0; i < arrayLength; i++)
	{
		for (int j = i + 1; j < arrayLength; j++)
		{
			float distance = GetDistance(&pointArray[i], &pointArray[j]);
			if (distance < maxDistance)
			{
				++count;
			}
		}
	}

	return count;
}

void PrintClosestPointInformation(AlgorithmInformation* info)
{
	PrintAlgorithmInformation(info);
}

void DisposeClosestPoint(ClosestPoint* closestPoint)
{
	DisposeAlgorithmInformation(&closestPoint->Information);
}