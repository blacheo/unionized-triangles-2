#include <gtest/gtest.h>
#include <contourize.h>
#include <triangle.h>
#include <intersections.h>

TEST(ContourizeTest, TwoTriangles) {
    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 0);
    auto t2 = Triangle(Point{3,1}, Point{6,1}, Point{4,3}, 0);

    auto newIntersections = intersections(t1, t2);

    auto contour = contourize(t1, t2, newIntersections);

    EXPECT_TRUE(contour.size() > 0);

}