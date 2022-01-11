#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <stdbool.h>

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
bool BinarySearch(int*, int, int, int);
#endif
