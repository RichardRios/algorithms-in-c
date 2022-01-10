#pragma once
#include <stdbool.h>

/// <summary>
/// Algorithm that searches each element of an array for a specified element. 
/// The algorithm runs in O(N) time under the assumption the compare condition 
/// is constant time.
/// 
/// The method performs a time analysis of each run and whether the element
/// being searched for is present in the array of randomly generated numbers.
/// If the element is found, the time taken is printed along with the location
/// in the array of the desired element.
/// 
/// </summary>
/// <param name="integerArray">array of integers</param>
/// <param name="toFind">element to find</param>
/// <param name="arrayLength">length of the array</param>
/// <returns>true if found, false otherwise</returns>
bool LinearSearch(int* integerArray, int toFind, int arrayLength);