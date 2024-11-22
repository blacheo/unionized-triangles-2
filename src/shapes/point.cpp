#include "point.h"



bool Point::operator==(const Point &other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
}

std::ostream &operator<<(std::ostream &os, Point const &p) { 
    return os << "(" << p.x << "," << p.y << "," << p.z << ")";
}
