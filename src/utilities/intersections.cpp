#include "intersections.h"
#include <optional>
#include <triangle_edges.h>
#include <triangle.h>
#include <constants.h>
#include <edge.h>
#include <interpolate_z.h>

std::optional<float> getB(std::optional<float> slope, Point p)
{
    if (!slope.has_value())
    {
        return {};
    }

    return p.y - slope.value() * p.x;
}

std::optional<float> getSlope(Edge e)
{
    if (e.p2.x - e.p1.x == 0)
    {
        return {};
    }
    return (e.p2.y - e.p1.y) / (e.p2.x - e.p1.x);
}

bool withinEdge(Edge e, Point p)
{
    float minX = std::min(e.p1.x, e.p2.x) - EPSILON;
    float maxX = std::max(e.p1.x, e.p2.x) + EPSILON;

    float minY = std::min(e.p1.y, e.p2.y) - EPSILON;
    float maxY = std::max(e.p1.y, e.p2.y) + EPSILON;

    return minX <= p.x && p.x <= maxX && minY <= p.y && p.y <= maxY;
}

void intersection(Edge e1, Edge e2, std::vector<Point> &results)
{
    auto point = intersectionWithinEdge(e1, e2);
    if (point.has_value())
    {
        results.push_back(point.value());
    }
}

std::optional<Point> intersectionWithinEdge(const Edge &e1, const Edge &e2)
{
    std::optional<Point> candPoint = intersection(e1, e2);
    if (candPoint.has_value() &&
        withinEdge(e1, candPoint.value()) &&
        withinEdge(e2, candPoint.value()))
    {
        return candPoint;
    }
    return {};
}

// intersection with first edge being considered infinite in length
std::optional<Point> intersectionFirstSide(const Edge &e1, const Edge &e2) {
    auto candPoint = intersection(e1, e2);

    if (candPoint.has_value() && withinEdge(e2, candPoint.value())) {
        return candPoint;
    }
    return {};
}

// returns intersection with e1 being extended infinitly in its direction
std::optional<Point> intersectionWithinEdgeDirection(const Edge &e1, const Edge &e2)
{
    auto candPoint = intersection(e1, e2);

    if (candPoint.has_value() && withinEdge(e2, candPoint.value()))
    {

        // check if in direction e1 is pointing at
        // case where e1 is pointing towards positive x axis
        if (e1.p1.x < e1.p2.x && candPoint.value().x >= e1.p1.x)
        {
            return candPoint;
        }

        // case where e1 is pointing towards negative x axis
        if (e1.p1.x > e1.p2.x && candPoint.value().x <= e1.p1.x)
        {
            return candPoint;
        }

        // edge case where p1 and p2 form a vertical line
        // case where e1 is pointing towards positive y axis
        if (e1.p1.y < e1.p2.y && candPoint.value().y >= e1.p1.y)
        {
            return candPoint;
        }

        // case where e1 is pointing towards negative axis
        if (e1.p1.y > e1.p2.y && candPoint.value().y <= e1.p1.y)
        {
            return candPoint;
        }
    }
    return {};
}

std::optional<Point> intersection(const Edge &e1, const Edge &e2)
{
    auto slope1 = getSlope(e1);
    auto slope2 = getSlope(e2);

    auto b1 = getB(slope1, e1.p1);
    auto b2 = getB(slope2, e2.p1);

    // ignore overlapping case
    if (!slope1.has_value() && !slope2.has_value())
    {
        return {};
    }

    if (!slope1.has_value())
    {
        return Point{e1.p1.x, slope2.value() * e1.p1.x + b2.value()};
    }

    if (!slope2.has_value())
    {
        return Point{e2.p1.x, slope1.value() * e2.p1.x + b1.value()};
    }
    float candX = (b2.value() - b1.value()) / (slope1.value() - slope2.value());
    auto candPoint = Point{candX, slope1.value() * candX + b1.value()};

    // ignore case where intersection is at an endpoint
    /*
    if (candPoint == e1.p1 || candPoint == e1.p2 || candPoint == e2.p1 || candPoint == e2.p2) {
        return {};
    }*/
    if (candPoint.x > MAX_POINT || candPoint.y > MAX_POINT || candPoint.x < MIN_POINT || candPoint.y < MIN_POINT)
    {
        return {};
    }
    return candPoint;
}
void intersections(const Edge &e1, const TriangleEdges &te, std::vector<Point> &results)
{
    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        intersection(e1, te.edges[i], results);
    }
}
std::vector<Point> intersections(const Triangle &t1, const Triangle &t2)
{
    TriangleEdges t1Edges = TriangleEdges(t1);

    TriangleEdges t2Edges = TriangleEdges(t2);
    std::vector<Point> results;

    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        intersections(t1Edges.edges[i], t2Edges, results);
    }

    return results;
}

std::vector<Point> intersections(const std::vector<Point> &points, const Edge &line)
{
    std::vector<Point> result;
    std::vector<Edge> es = makeEdges(points);
    for (int i = 0; i < es.size(); i++)
    {
        auto cand = intersectionFirstSide(line, es[i]);
        if (cand.has_value())
        {
            // add depth information
            float z = interpolateZ(es[i], cand.value());
            cand.value().z = z;
            result.push_back(cand.value());
        }
    }
    return result;
}
