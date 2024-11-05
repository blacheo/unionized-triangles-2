#pragma once
#include <vector>
#include <triangle.h>
#include <box.h>

class AbstractQuadTree
{
    protected:
    Box b;
    AbstractQuadTree(Box b);
    public:
    virtual void addTriangle(const Triangle &t) = 0;
    virtual std::vector<Triangle> visibleSurface() const = 0;
    virtual Triangle triangleIntersection(const Point &p) const = 0;
};

class QuadTreeLeaf : AbstractQuadTree
{
    Triangle t;

    void addTriangle(const Triangle &t) override;
};

class QuadTree : AbstractQuadTree
{
    std::vector<AbstractQuadTree> children;

public:
    QuadTree(Box b);
    void addTriangle(const Triangle &t) override;
};
