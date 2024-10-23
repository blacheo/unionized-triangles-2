#include "orientation.h"
#include <shapes/point.h>

Orientation orientation(const Point &p1, const Point &p2, const Point &p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) {
        return Collinear;
    }

    return (val > 0) ? Clockwise : Counterclockwise; 
}