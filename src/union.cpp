#include "triangle.h"
#include <vector>
#include <optional>

std::optional<Point> intersection(Edge e1, Edge e2) {

}

std::vector<Point> intersections(Triangle t1, Triangle t2) {

}

std::vector<Triangle> triangulate() {
}

std::vector<Triangle> unionize(Triangle t1, Triangle t2) {

	// at most 3? if infinite -> consider no intersections
	std::vector<Point> newIntersections = intersections(t1, t2);

	if (newIntersections.empty()) {
		// either completely envelops each other, no intersections	
	}

	return triangulate();
}
