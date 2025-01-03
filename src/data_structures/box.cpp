#include <box.h>
#include <triangle.h>
#include <constants.h>

bool Box::isIn(const Triangle &t) const {
    for (int i = 0; i < NB_TRIANGLE_SIDES; i++) {
        float x = t.points[i].x;
        float y = t.points[i].y;
        if (x > minX && x < maxX && y > minY && y < maxY) {
            return true;
        }
    }
    return false;
}

bool Box::isIn(const Point &p) const {
    if (p.x > minX && p.x < maxX && p.y > minY && p.y < maxY) {
        return true;
    }
    return false;
}