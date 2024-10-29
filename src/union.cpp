#include <vector>
#include <optional>
#include <union.h>
#include <contourize.h>
#include <intersections.h>
#include <triangulation.h>

std::vector<Triangle> unionize(const Triangle &t1, const Triangle &t2) {

	// if neighbours, do nothing
	if (t1.neighbours(t2)) {
		return std::vector{t1, t2};
	}

	// at most 3? if infinite -> consider no intersections
	std::vector<Point> newIntersections = intersections(t1, t2);

	if (newIntersections.empty()) {
		// either completely envelops each other, no intersections	
		return std::vector{t1, t2};
	}

	std::vector<Point> contour = contourize(t1, t2, newIntersections);

	return triangulate(contour);
}
