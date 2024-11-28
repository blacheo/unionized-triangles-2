#include <convex_triangulation.h>
#include <orientation.h>

// filters out degenerate triangles
void appendResults(std::vector<Triangle> &results, const Triangle &t) {
	if (orientation(t) == Collinear) {
		return;
	}
	results.push_back(t);
}

std::vector<Triangle> convexTriangulation(const std::vector<Point> &points, int triangleId) {
	const int size = points.size();
	if (size < 3) {
		return std::vector<Triangle>{};
	}

	const Triangle t1 = Triangle(points[0], points[1], points[2], triangleId);
	std::vector<Triangle> results;

	appendResults(results, t1);

	
	Point first = points[0];
	for (int i = size - 1; i >= 3; i--) {
		const Triangle t = Triangle(first, points[2], points[i], triangleId);
		appendResults(results, t);
		
		first = points[i];
	}
	return results;

}

