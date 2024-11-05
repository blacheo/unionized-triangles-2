#pragma once
#include <constants.h>
#include <point.h>
#include <vector>

struct PointNode {
    int prevIndex;
    int nextIndex;
    Point p;
    int next() const;
};

class PointList {
    int size;
    public:
    PointNode points[MAX_TRIANGLE_INTERSECTION_POINTS];
    PointList(const std::vector<Point> &points);
    bool empty() const;
    int getSize() const;
    int prev(const PointNode &p) const;
    int next(const PointNode &p) const;
    void remove(int index);
};