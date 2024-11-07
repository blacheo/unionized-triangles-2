#include "triangle.h"
#include "triangle_edges.h"
#include "edge.h"

bool Triangle::operator==(const Triangle &other) const {
	return points[0] == other.points[0] &&
		points[1] == other.points[1] &&
		points[2] == other.points[2] &&
		depth == other.depth &&
		id == other.id;
}

bool Triangle::neighbours(const Triangle &other) const {
    return false;
}

Triangle::Triangle(Point p1, Point p2, Point p3, int depth, int id) : points{p1,p2,p3}, depth{depth}, id{id} {}

bool Triangle::pointInTriangle(const Point &p) const {
    // all tests must be positive
    auto edges = TriangleEdges(*this);

    for (int i = 0; i < NB_TRIANGLE_SIDES; i++) {
        if (edges.edges[i].positiveSide(p)) {
            return false;
        }
    }
    return true;
}


int nextPoint(int pointIndex)  {
    return (pointIndex + 1) % 3;
}
