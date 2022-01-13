#ifndef POINT_H
#define POINT_H

typedef struct _Point
{
	float x;
	float y;
} Point;

typedef struct _Polar
{
	float r;
	float theta;
} Polar;

float GetDistance(Point* pointA, Point* pointB);
void ConvertToPolar(Point*, Polar*);

#endif