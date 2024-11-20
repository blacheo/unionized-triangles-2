#pragma once
#include <vector>
#include <point.h>

struct Triangle;
struct Edge;

std::vector<std::vector<Point>> splitTriangle(const Triangle &t, const Edge &line);