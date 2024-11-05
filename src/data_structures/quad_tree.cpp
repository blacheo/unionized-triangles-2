#include <quad_tree.h>
#include <triangulation.h>

QuadTree::QuadTree(Box b) : AbstractQuadTree{b}
{
}


void QuadTree::addTriangle(const Triangle &t)
{
    if (!b.isIn(t))
    {
        return;
    }

    
        q.children = {
            QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY}),
            QuadTree(Box{b.maxX / 2, b.maxX, b.minY, b.maxY / 2}),
            QuadTree(Box{b.maxX / 2, b.maxX, b.maxY / 2, b.maxY}),
            QuadTree(Box{b.minX, b.maxX / 2, b.minY, b.maxY / 2})};
        // if the old and new triangle intersect, we want to avoid infinite additions to the tree.
        // create new set of triangles that don't intersect
        std::vector<Triangle> newTriangles = triangulate(old, t);
        for (int i = 0; i < q.children.size(); i++)
        {
            for (int j = 0; j < newTriangles.size(); i++)
            {
                q.children[i].addTriangle(newTriangles[i]);
            }
        }
       
    
   
        for (int i = 0; i < q.children.size(); i++)
        {
            addTriangle(t);
        }
  
}

std::vector<Triangle> QuadTree::visibleSurface() const
{
    switch (status)
    {
    case Empty:
        return {};
        break;
    case Single:
        return {q.t};
    case Quad:
    {
        std::vector<Triangle> results;
        for (const auto &t : q.children)
        {
            auto ts = t.visibleSurface();
            results.insert(results.end(), ts.begin(), ts.end());
        }
    }

    default:
        break;
    }
}