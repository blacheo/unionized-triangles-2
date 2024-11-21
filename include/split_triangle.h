#pragma once
#include <vector>
#include <point.h>

struct Triangle;
struct Edge;

std::vector<std::vector<Point>> splitShape(const std::vector<Point> &points, const Edge &line);