#pragma once
struct Triangle;
struct Point;
enum Orientation {
    Clockwise, Collinear, Counterclockwise
};

Orientation orientation(const Point &p1, const Point &p2, const Point &p3);

Orientation orientation(const Triangle &t);