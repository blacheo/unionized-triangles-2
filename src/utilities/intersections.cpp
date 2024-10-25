#include "intersections.h"
#include <optional>
#include <edge.h>
#include <triangle_edges.h>



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
    auto slope1 = getSlope(e1);
    auto slope2 = getSlope(e2);

    auto b1 = getB(slope1, e1.p1);
    auto b2 = getB(slope2, e2.p1);


    // ignore overlapping case
    if (!slope1.has_value() && !slope2.has_value()) {
        return;
    }

    if (!slope1.has_value()) {
        results.push_back(Point{e1.p1.x, slope2.value() * e1.p1.x + b2.value()});
        return;
    }

    if (!slope2.has_value()) {
        results.push_back(Point{e2.p1.x, slope1.value() * e2.p1.x + b1.value()});
        return;
    }
    float candX = (b2.value() - b1.value()) / (slope1.value() - slope2.value());
    auto candPoint = Point{ candX, slope1.value() * candX + b1.value()};

    if (withinEdge(e1, candPoint) && withinEdge(e2, candPoint)) {
        results.push_back(candPoint);
    }
}
void intersections(Edge e1, TriangleEdges te, std::vector<Point> &results) {
   intersection(e1, te.e1, results);
   intersection(e1, te.e2, results);
   intersection(e1, te.e3, results); 
}
std::vector<Point> intersections(Triangle t1, Triangle t2) {
    TriangleEdges t1Edges = TriangleEdges(t1);

    TriangleEdges t2Edges = TriangleEdges(t2);
    std::vector<Point> results;

    intersections(t1Edges.e1, t2Edges, results);
    intersections(t1Edges.e2, t2Edges, results);
    intersections(t1Edges.e3, t2Edges, results);

    return results;
}

