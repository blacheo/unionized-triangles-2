#pragma once
#include "triangle.h"
#include <memory>
#include <vector>
#include "box.h"

#define QUADTREE_NODE_MAX_SHAPE 4

class QuadTree {
    Box b;
    std::shared_ptr<Triangle> t;

    std::vector<QuadTree> children;

    public:
        QuadTree(Box b);
        void addTriangle(std::shared_ptr<Triangle> t);
        std::vector<Triangle> visibleSurface() const;
        Triangle pointIntersection(Point p) const;

};