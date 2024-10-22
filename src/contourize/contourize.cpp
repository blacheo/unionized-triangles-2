#include <shapes/triangle.h>
#include <vector>
#include "contourize.h"

std::vector<Point> sortPoints(std::vector<Point> &points) {

}




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