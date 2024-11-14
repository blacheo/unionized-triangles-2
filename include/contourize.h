#pragma once
#include <vector>

struct Triangle;
struct Point;


// creates a contour from a list of points 
std::vector<Point> contourize(const std::vector<Point> &points);