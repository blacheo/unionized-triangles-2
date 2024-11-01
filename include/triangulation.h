#pragma once
#include <vector>
#include <optional>
#include <triangle.h>

class PointList;
struct Point;

std::optional<Triangle> removeEar(int &index, PointList &pointList, const std::vector<Point> &allPoints);

std::vector<Triangle> triangulate(std::vector<Point> points);

std::vector<Triangle> triangulate(Triangle t1, Triangle t2);