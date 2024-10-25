#include <vector>
#include <triangle.h>
#include <orientation.h>

Triangle clockwiseToCounterclockwise(const Triangle &t) {
    return Triangle(t.points[0], t.points[2], t.points[1], t.depth);
}

//
bool isCounterClockwiseForAll(const Point &previous, const Point &candidate, const std::vector<Point> & points) {
    for (const auto &point : points) {
        if (previous == point || candidate == point) {
            continue;
        }
        if (orientation(previous, candidate, point) != Counterclockwise) {
            return false;
        }
    }
    return true;
}


Point nextPoint(const Point &previous, std::vector<Point> candidates, const std::vector<Point> points) {
    for (int i = 0; i < candidates.size(); i++) {
        if (isCounterClockwiseForAll(previous, candidates[i], points)) {
            Point p = candidates[i];
            candidates.erase(i + candidates.begin());
            return p;
        }
    }
} 

std::vector<Point> sortPoints(const Triangle &t1, const Triangle &t2, const std::vector<Point> points) {
    std::vector<Point> result;
    const int NUM_TRIANGLE_POINTS = 3;
    // using convex hull algorithm
    // start at leftmost point
    Point minX = t1.points[0];

    for (int i = 1; i < NUM_TRIANGLE_POINTS; i++) {
        if (t1.points[i].x < minX.x) {
            minX = t1.points[i];
        }
    }

    for (int i = 0; i < NUM_TRIANGLE_POINTS; i++) {
        if (t2. points[i].x < minX.x) {
            minX = t2.points[i];
        }
    }

    // filter out points

    std::vector<Point> candidates;
     for (int i = 1; i < NUM_TRIANGLE_POINTS; i++) {
        if (!(t1.points[i] == minX)) {
            candidates.push_back(t1.points[i]);
        } 
    }

    for (int i = 0; i < NUM_TRIANGLE_POINTS; i++) {
        if (t2.points[i] != minX) {
            candidates.push_back(t2.points[i]);
        }
    }


    Point previous = minX;
    for (int i = 0; i < candidates.size(); i++) {
        nextPoint(previous, candidates, points);
    }

     
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