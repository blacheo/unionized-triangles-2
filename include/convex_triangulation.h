#pragma once

#include <triangle.h>
#include <point.h>
#include <vector>

// Requires a convex shape
std::vector<Triangle> convexTriangulation(const std::vector<Point> &points, int triangleId);
