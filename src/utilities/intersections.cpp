#include "intersections.h"
#include <optional>
#include <edge.h>
#include <triangle_edges.h>
#include <triangle.h>



std::optional<float> getB(std::optional<float> slope, Point p) {
    if (!slope.has_value()) {
        return {};
    }

    return p.y - slope.value() * p.x;
}

std::optional<float> getSlope(Edge e) {
    if (e.p2.x - e.p1.x == 0) {
        return {};
    }
    return (e.p2.y - e.p1.y) / (e.p2.x - e.p1.x) ;
}

bool withinEdge(Edge e, Point p) {
    float minX = std::min(e.p1.x, e.p2.x);
    float maxX = std::max(e.p1.x, e.p2.x);

    float minY = std::min(e.p1.y, e.p2.y);
    float maxY = std::max(e.p1.y, e.p2.y);

    return minX <= p.x && p.x <= maxX && minY <= p.y && p.y <= maxY; 
}

void intersection(Edge e1, Edge e2, std::vector<Point> &results) {
    auto point = intersection(e1, e2);
    if (point.has_value()) {
        results.push_back(point.value());
    }
}

std::optional<Point> intersection(const Edge &e1, const Edge &e2) {
    auto slope1 = getSlope(e1);
    auto slope2 = getSlope(e2);

    auto b1 = getB(slope1, e1.p1);
    auto b2 = getB(slope2, e2.p1);


    // ignore overlapping case
    if (!slope1.has_value() && !slope2.has_value()) {
        return {};
    }

    if (!slope1.has_value()) {
        return Point{e1.p1.x, slope2.value() * e1.p1.x + b2.value()};
    }

    if (!slope2.has_value()) {
        return Point{e2.p1.x, slope1.value() * e2.p1.x + b1.value()};
    }
    float candX = (b2.value() - b1.value()) / (slope1.value() - slope2.value());
    auto candPoint = Point{ candX, slope1.value() * candX + b1.value()};

    if (withinEdge(e1, candPoint) && withinEdge(e2, candPoint)) {
        return candPoint;
    }
    return {};
}
void intersections(const Edge &e1, const TriangleEdges &te, std::vector<Point> &results) {
    for (int i = 0; i < NB_TRIANGLE_SIDES; i++) {
        intersection(e1, te.edges[i], results);
    }
}
std::vector<Point> intersections(const Triangle &t1, const Triangle &t2) {
    TriangleEdges t1Edges = TriangleEdges(t1);

    TriangleEdges t2Edges = TriangleEdges(t2);
    std::vector<Point> results;

    for (int i = 0; i < NB_TRIANGLE_SIDES; i++) {
    intersections(t1Edges.edges[i], t2Edges, results);
    }


    return results;
}

