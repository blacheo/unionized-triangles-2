#include <stdlib.h>
#include <point.h>
#include <triangle.h>

#define DEBUG_EPSILON 0.0001

bool mostlyEqual(float a, float b)
{
    return abs(a - b) < DEBUG_EPSILON;
}

bool mostlyEqual(const Point &a, const Point &b)
{
    return mostlyEqual(a.x, b.x) && mostlyEqual(a.y, b.y) && mostlyEqual(a.z, b.z);
}

// mostly equal
bool Triangle::operator==(const Triangle &other) const {
	return mostlyEqual(points[0], other.points[0]) &&
		mostlyEqual(points[1], other.points[1]) &&
		mostlyEqual(points[2], other.points[2]) &&
		id == other.id;
}