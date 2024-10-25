#pragma once
#include <vector>
#include <triangle.h>

struct TrigTrigInterResults {
    std::vector<Point> results;
};

std::vector<Point> intersections(Triangle t1, Triangle t2);