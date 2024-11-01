#include "triangle_edges.h"
#include "triangle.h"

TriangleEdges::TriangleEdges(const Triangle &t) : edges{Edge{t.points[0], t.points[1]}, Edge{t.points[1], t.points[2]}, {Edge{t.points[2], t.points[0]}}}
{}

// returns the index of the point not in the edge
std::pair<int, int> TriangleEdges::otherPoint(int index) {
    if (index == 0) {
        return std::make_pair(0, 1);
    }

    if (index == 1) {
        return std::make_pair(1, 2);
    }

    return std::make_pair(2,0);
}