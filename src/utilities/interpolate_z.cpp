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
    const float pDist = dist2D(p);

    if (p1Dist - p2Dist == 0) {
        return e.p1.z;
    }

    const float m = (e.p1.z - e.p2.z) / (p1Dist - p2Dist);
    const float b = e.p1.z - p1Dist * m;


	return m * pDist + b;
}
