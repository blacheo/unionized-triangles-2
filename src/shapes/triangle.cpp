#include "triangle.h"
#include "triangle_edges.h"
#include "edge.h"

bool Triangle::neighbours(const Triangle &other) const {
    return false;
}

Triangle::Triangle(Point p1, Point p2, Point p3, int depth) : points{p1,p2,p3}, depth{depth} {}

bool Triangle::pointInTriangle(const Point &p) const {
    // all tests must be positive
    auto edges = TriangleEdges(*this);

    return !edges.e1.positiveSide(p) &&
    !edges.e2.positiveSide(p) &&
    !edges.e3.positiveSide(p);
}