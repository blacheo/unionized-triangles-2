#include "edge.h"

bool Edge::positiveSide(const Point &p) const {
    float h = p1.y - p2.y;
    float g = p1.x - p2.x; 
    return -h * (p.x - p1.x) + g * (p.y - p1.y) >= 0;
}