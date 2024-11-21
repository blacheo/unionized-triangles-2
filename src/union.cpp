#include <union.h>
#include <contourize.h>
#include <triangle.h>
#include <constants.h>
#include <list>
#include <triangle_edges.h>
#include <intersections.h>
#include <split_triangle.h>
#include <triangulation.h>

std::vector<Triangle> unionizeTopAndBottom(const Triangle &top, const Triangle &bot)
{
    std::vector<Triangle> result;

    std::list<Point> intr;
    TriangleEdges topEdges = TriangleEdges(top);

    // keep track of relevant triangles
    std::vector<Point> relv = {bot.points[0], bot.points[1], bot.points[2]};

    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        const Edge &e = topEdges.edges[i];
        auto shapes = splitShape(relv, e);
        // split triangle if exists
        // currently relevant triangles
        // add these to result
        if (!shapes[0].empty())
        {
            std::vector<Triangle> relvTriangles = triangulate(shapes[0], bot.depth, bot.id);
            result.insert(result.end(), relvTriangles.begin(), relvTriangles.end());
        }
        // future relevant triangles
        relv = shapes[1];
    }

    result.push_back(top);
    return result;
}

std::vector<Triangle> unionize(const Triangle &t1, const Triangle &t2)
{
    if (intersections(t1, t2).empty())
    {
        return {t1, t2};
    }
    if (t1.depth < t2.depth)
    {
        return unionizeTopAndBottom(t1, t2);
    }
    return unionizeTopAndBottom(t2, t1);
}