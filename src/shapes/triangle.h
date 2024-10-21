#pragma once
#include "point.h"

// points specified clockwise
struct Triangle {
	Point points[3];
	int depth;
	bool neighbours(Triangle &other);
	Triangle(Point p1, Point p2, Point p3, int depth);
};
