#pragma once
#include "point.h"
#include "print_triangle.h"

// points specified counterclockwise
struct Triangle
{
    Point points[3];
    int depth;
    int id;
    bool neighbours(const Triangle &other) const;
    Triangle(const Point &p1, const Point &p2, const Point &p3, int depth = 0, int id = 0);
    bool pointInTriangle(const Point &p) const;
    Point nextPoint(int pointIndex) const;
    bool operator==(const Triangle &other) const;
};
