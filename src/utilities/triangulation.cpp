#include "triangulation.h"
#include <list>
#include <point.h>
#include <triangle.h>
#include <optional>
#include <pointList.h>




bool isAnEar(Triangle triangle, const std::vector<Point> &points) {
    for (const Point &p: points) {
        if (triangle.pointInTriangle(p)) {
            return false;
        }
    }
    return true;
}

int mod(int a, int b) {
    return (a + b) % b;
}



std::optional<Triangle> removeEar(int &index, PointList &pointList, const std::vector<Point> &allPoints) {
    PointNode &p = pointList.points[index];
    const int next = pointList.next(p);
    const int prev = pointList.prev(p);

    const PointNode &nextNode = pointList.points[next];
    const PointNode &prevNode = pointList.points[prev];
/*
    Triangle candidate;

    if (index > next_index && next_index < previous_index) {
        candidate = Triangle{points[index], points[next_index], points[previous_index], 0};
    }

    if (index < next_index) {
        candidate = Triangle{points[index], points[next_index], points[previous_index], 0};

    }
    */

    Triangle candidate = Triangle{p.p, nextNode.p, prevNode.p, 0}; 

    if (isAnEar(candidate, allPoints)) {

        index = pointList.next(nextNode);
        pointList.remove(index);
        
        return candidate;
    }
    index = prev;
    return {};

}



std::vector<Triangle> triangulate(std::vector<Point> points) {
    std::vector<Triangle> result;

    PointList polygon = PointList(points);
    int i = 0;
    while (!polygon.empty()) {

        std::optional<Triangle> t = removeEar(i, polygon, points);
        if (t.has_value()) {
            result.push_back(t.value());
        }
    }
    

    return result;

}