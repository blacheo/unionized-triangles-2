#include <vector>
#include <triangle.h>
#include <orientation.h>
#include <triangle_edges.h>
#include <stack_vector.h>
#include <intersections.h>

Triangle clockwiseToCounterclockwise(const Triangle &t)
{
    return Triangle(t.points[0], t.points[2], t.points[1], t.depth);
}

/*
bool isCounterClockwiseForAll(const Point &previous, const Point &candidate, const std::vector<Point> & points) {
    for (const auto &point : points) {
        if (previous == point || candidate == point) {
            continue;
        }
        if (orientation(previous, point, candidate) != Counterclockwise) {
            return false;
        }
    }
    return true;
}
*/

/*
Point nextPoint(const Point &previous, std::vector<Point> &candidates, const std::vector<Point> &points) {
    Point mostCounterclockwise = candidates[0];
    for (int i = 1; i < candidates.size(); i++) {
        if (isCounterClockwiseForAll(previous, candidates[i], points)) {
            Point p = candidates[i];
            candidates.erase(i + candidates.begin());
            return p;
        }
    }

    return Point{-69,-69};
}
*/

float distanceSquared(const Point &p1, const Point &p2)
{
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

bool closestPoint(const Point &refPoint, const Point &p1, const Point &p2)
{
    float d1 = distanceSquared(refPoint, p1);
    float d2 = distanceSquared(refPoint, p2);
    return d1 < d2;
}

struct IntersectionAndEdge
{
    Point p;
    int edge;
};

std::vector<Point> contourize(const Triangle &leftmostTriangle, const Triangle &otherTriangle, int leftmostInd)
{
    std::vector<Point> result;

    const TriangleEdges lftEdges(leftmostTriangle);
    const TriangleEdges otherEdges(otherTriangle);
    StaticVector<IntersectionAndEdge> intersectionVector;

    bool usingLeftTriangle = true;

    int prev = leftmostInd;
    do
    {
        const Triangle &currentTriangle = usingLeftTriangle ? leftmostTriangle : otherTriangle;
        const TriangleEdges &other = !usingLeftTriangle ? lftEdges : otherEdges;
        result.push_back(currentTriangle.points[prev]);

        int nextPointInTriangle = (prev + 1) % NB_TRIANGLE_SIDES;
        const Edge &e1 = Edge{currentTriangle.points[prev], currentTriangle.points[nextPointInTriangle]};

        for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
        {
            auto intrs = intersection(e1, other.edges[i]);
            if (intrs.has_value())
            {
                intersectionVector.push_back(IntersectionAndEdge{intrs.value(), i});
            }
        }

        if (intersectionVector.getSize() == 0)
        {
            prev = nextPointInTriangle;
            continue;
        }
        else
        {
            // intersections found. Must switch to next triangle
            usingLeftTriangle = !usingLeftTriangle;
            int edgeIndex = intersectionVector.items[0].edge;
            if (intersectionVector.getSize() == 2 && !closestPoint(currentTriangle.points[prev], intersectionVector.items->p, intersectionVector.items[1].p))
            {
                // closest edge
                edgeIndex = intersectionVector.items[1].edge;
                result.push_back(intersectionVector.items[1].p);
            }
            else
            {
                result.push_back(intersectionVector.items[0].p);
            }

            const Edge &e2 = other.edges[edgeIndex];
            const std::pair<int, int> edgePointIndexes = TriangleEdges::otherPoint(edgeIndex);

            if (!e1.positiveSide(e2.p1))
            {
                prev = edgePointIndexes.first;
            }
            else
            {
                prev = edgePointIndexes.second;
            }
        }

    } while (!(prev == leftmostInd));
    return result;
}

/*

std::vector<Point> contourize(const Triangle &t1, const Triangle &t2, const std::vector<Point> &newIntersections) {
    std::vector<Point> result;
    // Go through each event point.
    // If an even point is in a triangle, it is not part of the final Triangle
    for (auto &p : t1.points) {
        if (!t2.pointInTriangle(p)) {
            result.push_back(p);
        }
    }

    for (auto &p : t2.points) {
        if (!t2.pointInTriangle(p)) {
            result.push_back(p);
        }
    }

    result.insert(result.end(), newIntersections.begin(), newIntersections.end());

    return result;
}

*/