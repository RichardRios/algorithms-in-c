#ifndef CLOSEST_POINT_H
#define CLOSEST_POINT_H

#include <stdbool.h>
#include "Internal/Point.h"
#include "Internal/AlgorithmInformation.h"

/*
 *				Closest Point Computation
 * 
 * Algorithm that counts the number of points whose distance
 * is less than the supplied maximum distance. 
 * 
 */

typedef struct _ClosestPoint
{
	int(*Run)(Point*, int, int);
	void(*PrintInformation)(AlgorithmInformation*);
	AlgorithmInformation Information;
} ClosestPoint;

ClosestPoint InitClosestPoint();
int RunClosestPoint(Point*, int, int);
void PrintClosestPointInformation(AlgorithmInformation*);
void DisposeClosestPoint(ClosestPoint*);

#endif