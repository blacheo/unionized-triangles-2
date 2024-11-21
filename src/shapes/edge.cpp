#include "edge.h"

bool Edge::positiveSide(const Point &p) const {
    float h = p1.y - p2.y;
    float g = p1.x - p2.x; 
    return -h * (p.x - p1.x) + g * (p.y - p1.y) >= 0;
}

// Output: produces a list of edges in counterclockwise order
// Requirements: points are provided in counterclockwise order
std::vector<Edge> makeEdges(const std::vector<Point> &points) {
    std::vector<Edge> result;
    if (points.size() < 2) {
        return result;
    }

    for (int i = 0; i < points.size() - 1; i++) {
        result.push_back(Edge{points[i], points[i + 1]});
    }
    result.push_back(Edge{points[points.size() - 1], points[0]});
    return result;
}