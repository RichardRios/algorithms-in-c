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
 * Parameters:
 *		integerArray : Array of sorted integers
 *		toFind		 : integer to find in sorted integer array
 *		arraySize	 : count of elements in integerArray
 * 
 * Returns:
 *		true if found, false otherwise
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
