#pragma once
#include <vector>

struct Triangle;
struct Point;


std::vector<Point> contourize(const Triangle &leftmostTriangle, const Triangle &otherTriangle, int leftmostInd);

std::vector<Point> sortPoints(std::vector<Point> &points);