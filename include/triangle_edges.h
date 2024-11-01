#pragma once
#include <constants.h>
#include <utility>
#include "edge.h"


struct Triangle;
struct TriangleEdges {
    Edge edges[NB_TRIANGLE_SIDES];
    TriangleEdges(const Triangle &t);
    static std::pair<int, int> otherPoint(int index);
};
