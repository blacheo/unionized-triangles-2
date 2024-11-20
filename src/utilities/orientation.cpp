#include "orientation.h"
#include <point.h>

float edgeValue(const Point &p1, const Point &p2) {
    return (p2.x - p1.x) * (p2.y + p1.y);
}

Orientation orientation(const Point &p1, const Point &p2, const Point &p3) {
    float val = edgeValue(p1, p2) + edgeValue(p2, p3) + edgeValue(p3, p1);
    if (val == 0) {
        return Collinear;
    }

    return (val > 0) ? Clockwise : Counterclockwise; 
}