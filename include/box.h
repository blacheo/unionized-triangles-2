#pragma once

struct Triangle;
struct Point;

struct Box {
    float minX, maxX, minY, maxY;
    bool isIn(const Triangle &t) const;
    bool isIn(const Point &p) const;
};