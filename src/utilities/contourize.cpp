#include <contourize.h>
#include <point.h>
#include <orientation.h>
#include <list>

const char* ContourizeException::what() const throw() {
    return "Infinite Loop detected";
}

bool isCounterClockwiseForAll(const Point &previous, const Point &candidate, const std::vector<Point> & points) {
    for (const auto &point : points) {
        if (previous == point || candidate == point) {
            continue;
        }
	auto o = orientation(previous, candidate, point);
        if (o == Collinear) {
            continue;
        }

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
    const int size = candidates.size();

    // infinite loop detection
    int seen = 0;

    while (!candidates.empty()) {
        // detect infinite loop
        if (seen >= candidates.size()) {
            throw ContourizeException();
        }
  

        if (isCounterClockwiseForAll(previous, candidates.front(), points)) {
            previous = candidates.front();
            candidates.pop_front();
	        result.push_back(previous);
            seen = 0;
        } else {
            candidates.push_back(candidates.front());
            candidates.pop_front();
            seen++;
        }
    }
    return result;
}
