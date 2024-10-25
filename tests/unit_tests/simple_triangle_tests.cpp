#include <gtest/gtest.h>
#include <triangle.h>
#include <intersections.h>

TEST (TriangleIntersectionTests, TriangleIntersection) {
    auto t1 = Triangle(Point{0,0}, Point{2,3}, Point{5,0}, 0);
    auto t2 = Triangle(Point{3,1}, Point{4,3}, Point{6,1}, 0);

    std::vector<Point> results = intersections(t1, t2);

    EXPECT_TRUE(results.size() == 2) << "Actual size: " << results.size();

}


