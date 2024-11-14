#include <vector>
#include <triangle.h>
#include <triangle_edges.h>
#include <intersections.h>
#include <contourize.h>
#include <triangulation.h>

std::vector<Point> getPointsOnSide(const Edge &e, const std::vector<Point> intr, const Triangle &bottom)
{
    std::vector<Point> result;
    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        if (e.positiveSide(bottom.points[i]))
        {
            result.push_back(bottom.points[i]);
        }
    }

    for (const auto &p : intr)
    {
        if (e.positiveSide(p))
        {
            result.push_back(p);
        }
    }
    return result;
}

std::vector<Triangle> unionizeTopAndBottom(const Triangle &top, const Triangle &bottom)
{
    if (intersections(top, bottom).empty()) {
        return {};
    }
    std::vector<Triangle> result;
    TriangleEdges topEdges = TriangleEdges(top);
    TriangleEdges botEdges = TriangleEdges(bottom);

    std::vector<Point> intrPoints;

    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        for (int j = 0; j < NB_TRIANGLE_SIDES; j++)
        {
            auto cand = intersectionWithinEdgeDirection(topEdges.edges[i], botEdges.edges[i]);
            if (cand.has_value())
            {
                intrPoints.push_back(cand.value());
            }
        }
    }

    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        std::vector<Point> currentShape = getPointsOnSide(topEdges.edges[i], intrPoints, bottom);
        std::vector<Point> orderedPoints = contourize(currentShape);
        std::vector<Triangle> newTriangles = triangulate(orderedPoints);
        result.insert(result.begin(), newTriangles.begin(), newTriangles.end());
    }

    return result;
}

std::vector<Triangle> unionize(const Triangle &t1, const Triangle &t2)
{
    if (t1.depth < t2.depth)
    {
        return unionizeTopAndBottom(t1, t2);
    }
    return unionizeTopAndBottom(t2, t1);
}