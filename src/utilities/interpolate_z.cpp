#include <interpolate_z.h>
#include <limits>
#include <point.h>
#include <edge.h>
#include <cmath>

float dist2D(const Point &p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

float interpolateZ(const Edge &e, const Point &p) {
	const float p1Dist = dist2D(e.p1);
	const float p2Dist = dist2D(e.p2);

	const float b = (p2Dist * e.p1.z - p1Dist * e.p2.z) / (p2Dist - p1Dist);
	
	const float m = (e.p2.z - b) / p2Dist;

	return m * dist2D(p) + b;
}
