#pragma once
#include "point.h"

// points specified counterclockwise
struct Triangle
{
    Point points[3];
    int depth;
    int id;
    bool neighbours(const Triangle &other) const;
    Triangle(Point p1, Point p2, Point p3, int depth, int id=0);
    bool pointInTriangle(const Point &p) const;
    Point nextPoint(int pointIndex) const;
};
