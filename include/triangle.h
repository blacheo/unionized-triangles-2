#pragma once
#include "point.h"
#include "print_triangle.h"
#include <vector>

// points specified counterclockwise
struct Triangle
{
    Point points[3];
    int depth;
    int id;
    std::vector<int> neighbours;


    Triangle(const Point &p1, const Point &p2, const Point &p3, int depth = 0, int id = 0, const std::vector<int> neighbours = {});
    bool pointInTriangle(const Point &p) const;
    Point nextPoint(int pointIndex) const;
    bool operator==(const Triangle &other) const;
};
