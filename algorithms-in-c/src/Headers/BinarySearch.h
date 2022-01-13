#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdbool.h>
#include "Internal/AlgorithmInformation.h"

/*
 *					Binary Search
 *
 * Algorithm that runs in O(Log N). Searches for an element in an
 * array by splitting the problem set in half. Requires that
 * elements are sorted.
 * 
 */

typedef struct _BinarySearch
{
	bool(*Run)(int*, int, int);
	void(*PrintInformation)(AlgorithmInformation*);
	AlgorithmInformation Information;
} BinarySearch;

BinarySearch InitBinarySearch();
bool RunBinarySearch(int*, int, int);
void PrintBinarySearchInformation(AlgorithmInformation*);
void DisposeBinarySearch(BinarySearch*);
#endif
