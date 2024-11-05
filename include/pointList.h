#pragma once
#include <constants.h>
#include <point.h>
#include <vector>

struct PointNode {
    int prevIndex;
    int nextIndex;
    Point p;
    int next() const;
    int prev() const;
};

class PointList {
    int size;
    public:
    PointNode points[MAX_TRIANGLE_INTERSECTION_POINTS];
    PointList(const std::vector<Point> &points);
    bool empty() const;
    int getSize() const;
   
    void remove(int index);
};