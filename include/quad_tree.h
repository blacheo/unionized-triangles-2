#pragma once
#include "triangle.h"
#include <memory>
#include <vector>
#include "box.h"

const int POINT_NOT_IN_QUADTREE = -1;

#define QUADTREE_NODE_MAX_SHAPE 4

class QuadTree {
    Box b;
    std::vector<Triangle> triangles; 

    std::vector<QuadTree> children;

    public:
        QuadTree(Box b);
        void addTriangle(Triangle triangle);
        std::vector<Triangle> visibleSurface() const;
        // returns triangle id
        int pointIntersection(Point p) const;

};