#include <contourize.h>
#include <point.h>
#include <orientation.h>
#include <list>

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

std::vector<Point> contourize(const std::vector<Point> &points) {
    std::list<Point> candidates(points.begin(), points.end());
    std::vector<Point> result;

    Point previous = points[0];
    while (!candidates.empty()) {
        if (isCounterClockwiseForAll(previous, candidates.front(), points)) {
            previous = candidates.front();
            candidates.pop_front();
        } else {
            candidates.push_back(candidates.front());
            candidates.pop_front();
        }
    }
    return result;
}