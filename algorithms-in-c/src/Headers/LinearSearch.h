#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <stdbool.h>

/*
 *							Linear Search
 * 
 * Algorithm that searches each element of an array for a specified element. 
 * The algorithm runs in O(N) time under the assumption the compare condition 
 * is constant time.
 * 
 * The method performs a time analysis of each run and whether the element
 * being searched for is present in the array of randomly generated numbers.
 * If the element is found, the time taken is printed along with the location
 * in the array of the desired element.
 * 
 * Parameters:
 *		integerArray - integer array
 *		toFind		 - integer to find in integerArray
 *		arrayLength  - length of the array supplied
 * 
 * Returns:
 *		true if found, false otherwise
 * 
 */
bool LinearSearch(int* integerArray, int toFind, int arrayLength);

#endif