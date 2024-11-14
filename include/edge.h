#pragma once
#include "point.h"

struct Edge {
	Point p1, p2;

    bool positiveSide(const Point &p) const;

};