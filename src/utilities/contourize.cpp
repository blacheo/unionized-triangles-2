#include <vector>
#include <triangle.h>
#include <orientation.h>

Triangle clockwiseToCounterclockwise(const Triangle &t) {
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

std::vector<Point> contourize(const Triangle &t1, const Triangle &t2, const std::vector<Point> &intersections) {
    std::vector<Point> result;
    const int NUM_TRIANGLE_POINTS = 3;
    // using convex hull algorithm
    // start at leftmost point

    // get points
    // initially ignoring intersection points because they cannot be the leftmost
    std::vector<Point> points;

    points.insert(points.end(), t1.points, t1.points + NUM_TRIANGLE_POINTS);
    points.insert(points.end(), t2.points, t2.points + NUM_TRIANGLE_POINTS);

    int minX = 0;
    for (int i = 0; i < points.size(); i++) {
        if (points[minX].x > points[i].x) {
            minX = i;
        }
    }

    // add intersection points
    points.insert(points.end(), intersections.begin(), intersections.end());

    int previous = minX;
    int candidate;

    do {
        
        result.push_back(points[previous]);
        candidate = (previous + 1) % points.size();
        for (int i = 0; i < points.size(); i++) {
            if (orientation(points[previous], points[candidate], points[i]) == Counterclockwise) {
                candidate = i;
            }
        }
        previous = candidate;
    } while (previous != minX);

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