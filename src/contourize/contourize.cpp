#include <shapes/triangle.h>
#include <shapes/edge.h>
#include <shapes/triangle_edges.h>
#include <vector>

bool positiveSide(Edge e, Point p) {
    float h = e.p1.y - e.p2.y;
    float g = e.p1.x - e.p2.x; 
    return -h * (p.x - e.p1.x) + g * (p.y - e.p1.y) >= 0;
}

bool pointInTriangle(Point p, Triangle t) {
    // all tests must be positive
    auto edges = TriangleEdges(t);

    return positiveSide(edges.e1, p) &&
    positiveSide(edges.e2, p) &&
    positiveSide(edges.e3, p);
}

void contourize(Triangle t1, Triangle t2, std::vector<Point> newIntersections) {

}