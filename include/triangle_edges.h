#pragma once

#include "edge.h"
struct Triangle;
struct TriangleEdges {
    Edge e1, e2, e3;
    TriangleEdges(const Triangle &t);
};
