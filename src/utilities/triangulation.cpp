#include "triangulation.h"
#include <list>
#include <point.h>
#include <triangle.h>
#include <optional>
#include <pointList.h>
#include <orientation.h>




bool isAnEar(Triangle triangle, const std::vector<Point> &points) {
    for (const Point &p: points) {
        if (triangle.pointInTriangle(p)) {
            return false;
        }
    }
    return true;
}


std::optional<Triangle> removeEar(int &index, PointList &pointList, const std::vector<Point> &allPoints,int depth, int id) {
    PointNode &p = pointList.points[index];
    const int next = p.next();
    const int prev = p.prev();


    const PointNode &nextNode = pointList.points[next];
    const PointNode &prevNode = pointList.points[prev];

    Triangle candidate = Triangle{p.p, nextNode.p, prevNode.p, depth, id}; 

    if (orientation(p.p, nextNode.p, prevNode.p) == Counterclockwise && isAnEar(candidate, allPoints)) {

        pointList.remove(index);
        index = next;
        
        return candidate;
    }
    index = next;
    return {};

}



std::vector<Triangle> triangulate(std::vector<Point> points, int depth, int id) {
    std::vector<Triangle> result;

    PointList polygon = PointList(points);
    int i = 0;
    while (polygon.getSize() >= 4) {

        std::optional<Triangle> t = removeEar(i, polygon, points, depth, id);
        if (t.has_value()) {
            result.push_back(t.value());
        }
    }

    const PointNode curr = polygon.points[i];
    const int next = curr.next();
    const int prev = curr.prev();
    
    Triangle last {curr.p, polygon.points[next].p, polygon.points[prev].p, depth, id};
    result.push_back(last);
    

    return result;

}