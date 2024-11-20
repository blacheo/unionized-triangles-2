#include <contourize.h>
#include <point.h>
#include <orientation.h>
#include <list>

bool isCounterClockwiseForAll(const Point &previous, const Point &candidate, const std::vector<Point> & points) {
    for (const auto &point : points) {
        if (previous == point || candidate == point) {
            continue;
        }
	auto o = orientation(previous, candidate, point);
        if (o != Counterclockwise) {
            return false;
        }
    }
    return true;
}

std::vector<Point> contourize(const std::vector<Point> &points) {
    if (points.size() < 3) {
        return points;
    }

    std::vector<Point> result;

    Point previous = points[0];
    result.push_back(previous);
    std::list<Point> candidates(points.begin() + 1, points.end());
    while (!candidates.empty()) {
        if (isCounterClockwiseForAll(previous, candidates.front(), points)) {
            previous = candidates.front();
            candidates.pop_front();
	    result.push_back(previous);
        } else {
            candidates.push_back(candidates.front());
            candidates.pop_front();
        }
    }
    return result;
}
