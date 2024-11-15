#include <print_triangle.h>
#include <triangle.h>
#include <point.h>

std::ostream &operator<<(std::ostream &os, const Triangle &t) {
	return os << "Triangle: " << t.id
			<< ", " << "Depth: " << t.depth
			<< " {" << t.points[0] << ", " << t.points[1] << ", " << t.points[2] << "}";
}
/*
std::ostream &operator<<(std::ostream &os, const std::vector<Triangle> &triangles) {
	for (const auto &t : triangles) {

	}
	return os;
}*/
