#pragma once
#include "point.h"
#include <vector>

struct Edge {
	Point p1, p2;

    bool positiveSide(const Point &p) const;

};

std::vector<Edge> makeEdges(const std::vector<Point> &points);