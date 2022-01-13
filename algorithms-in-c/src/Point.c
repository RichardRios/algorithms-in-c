#include <math.h>
#include "Headers/Internal/Point.h"

float GetDistance(Point* pointA, Point* pointB)
{
	float dx = pointA->x - pointB->x;
	float dy = pointA->y - pointB->y;

	return sqrtf(powf(dx, 2) + powf(dy, 2));
}

void ConvertToPolar(Point* point, Polar* polar)
{
	polar->r = sqrtf(powf(point->x, 2) + powf(point->y, 2));
	polar->theta = atan2f(point->y, point->x);
}