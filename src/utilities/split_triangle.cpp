#include <split_triangle.h>
#include <constants.h>
#include <contourize.h>
#include <triangle.h>
#include <edge.h>
#include <intersections.h>

std::vector<std::vector<Point>> splitTriangle(const Triangle &t, const Edge &line)
{
    // get intersections
    auto intr = intersections(t, line);

    std::vector<Point> pos;
    std::vector<Point> neg;
    for (int i = 0; i < NB_TRIANGLE_SIDES; i++)
    {
        if (line.positiveSide(t.points[i]))
        {
            pos.push_back(t.points[i]);
        }
        else
        {
            neg.push_back(t.points[i]);
        }
    }

    if (!(pos.empty() || neg.empty()))
    {
        
            pos.insert(pos.end(), intr.begin(), intr.end());
            neg.insert(neg.end(), intr.begin(), intr.end());
    }    // Build Positive side

    pos = contourize(pos);

    // Build Negative side
    neg = contourize(neg);
    return std::vector<std::vector<Point>>{pos, neg};
}