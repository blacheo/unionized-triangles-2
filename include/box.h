#pragma once

struct Triangle;

struct Box {
    float minX, maxX, minY, maxY;
    bool isIn(const Triangle &t) const;
};