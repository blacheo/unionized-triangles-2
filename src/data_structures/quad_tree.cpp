#include <quad_tree.h>
#include <union.h>

QuadTree::QuadTree(Box b) : b{b} {}

void QuadTree::addTriangle(std::shared_ptr<Triangle> t)
{

    if (!b.isIn(*t))
    {
        return;
    }

    if (this->t == nullptr && children.empty())
    {
        this->t = t;
        return;
    }

    if (!children.empty())
    {
        for (auto &c : children)
        {
            c.addTriangle(t);
        }
    }

    children = {
        QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY}),
        QuadTree(Box{b.maxX / 2, b.maxX, b.minY, b.maxY / 2}),
        QuadTree(Box{b.maxX / 2, b.maxX, b.maxY / 2, b.maxY}),
        QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY / 2})};

    auto newTriangles = unionize(*t, *(this->t));
    this->t = nullptr;

    for (auto &c : children)
    {
        for (auto &newT : newTriangles)
        {
            c.addTriangle(std::make_shared<Triangle>(newT));
        }
    }
}