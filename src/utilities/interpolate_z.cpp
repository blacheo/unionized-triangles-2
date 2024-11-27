#include <interpolate_z.h>
#include <limits>
#include <point.h>
#include <cmath>


float interpolateZ(const std::vector<Point> &shape, const Point &p) {
    // create direction vectors
    const Point v1 = -(shape[0] - shape[1]);
    const Point v2 = -(shape[0] - shape[2]);

    const Point &origin = shape[0];

    float t = (p.y * v1.x - origin.y * v1.x - p.x * v1.y + origin.x * v1.y) / (v1.x * v2.y - v1.y * v2.x);
    float s = (p.y - origin.y - t * v2.y) / v1.y;

    if (s == - std::numeric_limits<float>::infinity() || std::isnan(s)) {
        s = 0;
    }

    if (t == - std::numeric_limits<float>::infinity() || std::isnan(t)) {
       t = 0; 
    }

    return origin.z + v1.z * s + v2.z * t;
}
