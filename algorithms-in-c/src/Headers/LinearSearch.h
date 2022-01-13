#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <stdbool.h>
#include "Internal/AlgorithmInformation.h"

/*
 *							Linear Search
 * 
 * Algorithm that searches each element of an array for a specified element. 
 * The algorithm runs in O(N) time.
 * 
 */

typedef struct _LinearSearch
{
	bool(*Run)(int*, int, int);
	void(*PrintInformation)(AlgorithmInformation*);
	AlgorithmInformation Information;
} LinearSearch;

LinearSearch InitLinearSearch();
bool RunLinearSearch(int* integerArray, int toFind, int arrayLength);
void PrintLinearSearchInformation(AlgorithmInformation*);
void DisposeLinearSearch(LinearSearch*);

#endif