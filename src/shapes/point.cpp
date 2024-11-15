#include "point.h"

bool mostlyEqual(float a, float b) {
	return abs(a - b) < 0.0001;
}

bool Point::operator==(const Point &other) const {
    return (x == other.x) && (y == other.y);
}

std::ostream &operator<<(std::ostream &os, Point const &p) { 
    return os << "(" << p.x << "," << p.y << ")";
}
