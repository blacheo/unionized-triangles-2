#pragma once
#include <vector>
#include <triangle.h>
#include <box.h>

enum Status {
    Empty,
    Single,
    Quad
};

class QuadTree {
    Box b;
    Status status;
    QuadContent q;
    public:
    void addTriangle(const Triangle &t);
    QuadTree(Box b);
    std::vector<Triangle> visibleSurface() const;
    Triangle triangleIntersection(const Point &p) const;

};

union QuadContent {

    Triangle t;
    std::vector<QuadTree> children;
    bool nothing;
    QuadContent() {};
    ~QuadContent() {};
};