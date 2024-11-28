#include <print_triangle.h>
#include <triangle.h>
#include <point.h>

std::ostream &operator<<(std::ostream &os, const Triangle &t) {
	return os << "Triangle" << "(" << t.points[0] << ", " << t.points[1] << ", " << t.points[2] << ", " << t.id << ")";
}
/*
std::ostream &operator<<(std::ostream &os, const std::vector<Triangle> &triangles) {
	for (const auto &t : triangles) {

	}
	return os;
}*/
