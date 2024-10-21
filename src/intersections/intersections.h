#pragma once
#include <vector>
#include "../shapes/point.h"
#include "../shapes/triangle.h"

struct TrigTrigInterResults {
    std::vector<Point> results;
};

std::vector<Point> intersections(Triangle t1, Triangle t2);