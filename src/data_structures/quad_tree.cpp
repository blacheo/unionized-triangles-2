#include <quad_tree.h>

QuadTree::QuadTree(Box b) : b{b}, status{Empty} {
    q.nothing = false;
}

void QuadTree::addTriangle(const Triangle &t)
{
    if (!b.isIn(t)) {
        return;
    }
    switch (status)
    {
    case Empty:
        status = Single;
        q.t = t;
        break;

    case Single:

        Triangle old = q.t;

        
        status = Quad;
        q.children = {
            QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY}),
             QuadTree(Box{b.maxX / 2, b.maxX, b.minY, b.maxY / 2}),
              QuadTree(Box{b.maxX / 2, b.maxX, b.maxY / 2, b.maxY}),
               QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY / 2})
            };
            // if the old and new triangle intersect, we want to avoid infinite additions to the tree.
            // create new set of triangles that don't intersect
            std::vector<Triangle> newTriangles = triangulate(old, t);
        for (int i = 0; i < q.children.size(); i++) {
            for (int j = 0; j < newTriangles.size(); i++) {
                q.children[i].addTriangle(newTriangles[i]);
            }
        }
        break;
    case Quad:
    for (int i = 0; i < q.children.size(); i++) {
        addTriangle(t);
    }
        break;
    default:
        break;
    }
}


std::vector<Triangle> QuadTree::visibleSurface() const {
    // for every 
}