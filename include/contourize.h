#pragma once
#include <vector>

struct Triangle;
struct Point;


std::vector<Point> contourize(const Triangle &t1, const Triangle &t2);

std::vector<Point> sortPoints(std::vector<Point> &points);