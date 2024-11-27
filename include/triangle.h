#pragma once
#include "point.h"
#include "print_triangle.h"
#include <vector>

// points specified in counterclockwise or collinear (line / point) order
struct Triangle
{
    Point points[3];
    int id;
    std::vector<int> neighbours;


    Triangle(const Point &p1, const Point &p2, const Point &p3, int id = 0, const std::vector<int> neighbours = {});
    bool pointInTriangle(const Point &p) const;
    Point nextPoint(int pointIndex) const;
    bool operator==(const Triangle &other) const;
};
