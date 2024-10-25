#pragma once
#include <vector>

struct Triangle;
struct Point;

std::vector<Triangle> monotoneTriangulate(std::vector<Point> &points);