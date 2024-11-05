#include <gtest/gtest.h>
#include <contourize.h>
#include <triangle.h>
#include <intersections.h>

TEST(ContourizeTest, TwoTriangles) {
    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 0);
    auto t2 = Triangle(Point{3,1}, Point{6,1}, Point{4,3}, 0);

    auto contour = contourize(t1, t2);

    EXPECT_TRUE(contour.size() > 0);
    std::vector<Point> expectedContour {Point{0,0}, 
    Point{5,0}, 
    Point{4, 1}, 
    Point{6,1}, 
    Point{4,3}, 
    Point{3.33333325, 1.66666675}, 
    Point{2,3}};
    EXPECT_EQ(contour, expectedContour);

}

TEST (ContourizeTests, TriangleSingleDipTest) {
    auto t1 = Triangle({0,0}, {5,0}, {2,6}, 0);
    auto t2 = Triangle({1,1}, {7,3}, {8,6}, 0);

    auto newIntersections = intersections(t1, t2);

    auto contour = contourize(t1, t2);

    std::vector<Point> expectedContour{
        {0,0}, {5,0}, {4,2}, {7,3}, {8,6}, {4,3}, {2,6}
    };

    EXPECT_EQ(contour, expectedContour);
    
}