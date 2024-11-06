#include <quad_tree.h>
#include <union.h>

QuadTree::QuadTree(Box b) : b{b} {}

int QuadTree::pointIntersection(Point p) const
{
    int triangleId = POINT_NOT_IN_QUADTREE;
    if (!b.isIn(p))
    {
        return POINT_NOT_IN_QUADTREE;
    }
    if (triangles.size() > 0)
    {
        int depth = INT32_MAX;
        for (const Triangle &t : triangles)
        {
            if (t.depth < depth && t.pointInTriangle(p))
            {
                depth = t.depth;
                triangleId = t.id;
            }
        }
        return triangleId;
    }

    for (const QuadTree &q : children)
    {
        int id = q.pointIntersection(p);
        if (id != POINT_NOT_IN_QUADTREE)
        {
            triangleId = POINT_NOT_IN_QUADTREE;
        }
    }
    return triangleId;
}

void QuadTree::addTriangle(Triangle triangle)
{

    if (!b.isIn(triangle))
    {
        return;
    }

    if (triangles.size() >= QUADTREE_NODE_MAX_SHAPE && children.empty())
    {
        children = {
            QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY}),
            QuadTree(Box{b.maxX / 2, b.maxX, b.minY, b.maxY / 2}),
            QuadTree(Box{b.maxX / 2, b.maxX, b.maxY / 2, b.maxY}),
            QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY / 2})};

        for (QuadTree &c : children)
        {

            c.addTriangle(triangle);
            for (const Triangle &t : triangles)
            {
                c.addTriangle(t);
            }
        }
        triangles.clear();
        return;
    }

    if (children.empty())
    {
        triangles.push_back(triangle);
        return;
    }

    for (QuadTree &c : children)
    {
        for (const Triangle &t : triangles)
        {
            c.addTriangle(t);
        }
    }
}