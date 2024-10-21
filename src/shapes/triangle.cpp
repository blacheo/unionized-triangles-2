#include "triangle.h"

bool Triangle::neighbours(Triangle &other) {
    return false;
}

Triangle::Triangle(Point p1, Point p2, Point p3, int depth) : p1{p1}, p2{p2}, p3{p3}, depth{depth} {}