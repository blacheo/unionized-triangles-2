#include <convex_triangulation.h>

std::vector<Triangle> convexTriangulation(const std::vector<Point> &points, int depth, int triangleId) {
	const int size = points.size();
	if (size < 3) {
		return std::vector<Triangle>{};
	}

	const Triangle t1 = Triangle(points[0], points[1], points[2], depth, triangleId);
	std::vector<Triangle> results = {t1};

	
	Point first = points[0];
	for (int i = size - 1; i >= 3; i--) {
		results.push_back(Triangle(first, points[2], points[i], depth, triangleId));
		first = points[i];
	}
	return results;

}
