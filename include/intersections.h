#pragma once
#include <vector>
#include <point.h>
#include <optional>


struct Edge;
struct Triangle;

struct TrigTrigInterResults {
    std::vector<Point> results;
};

std::optional<Point> intersectionWithinEdge(const Edge &e1, const Edge &e2);
std::optional<Point> intersection(const Edge &e1, const Edge &e2);

std::vector<Point> intersections(const Triangle &t1, const Triangle &t2);

bool intersect(const Triangle &t1, const Triangle &t2);

std::optional<Point> intersectionWithinEdgeDirection(const Edge &e1, const Edge &e2);
