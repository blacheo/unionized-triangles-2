#include <split_triangle.h>
#include <constants.h>
#include <contourize.h>
#include <triangle.h>
#include <edge.h>
#include <intersections.h>

std::vector<std::vector<Point>> splitShape(const std::vector<Point> &points, const Edge &line)
{
    // get intersections
    auto intr = intersections(points, line);

    std::vector<Point> pos;
    std::vector<Point> neg;
    for (int i = 0; i < points.size(); i++)
    {
        if (line.positiveSide(points[i]))
        {
            pos.push_back(points[i]);
        }
        else
        {
            neg.push_back(points[i]);
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