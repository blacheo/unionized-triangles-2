#include <gtest/gtest.h>
#include <orientation.h>
#include <point.h>

TEST(OrientationTests, Collinear)
{
    EXPECT_EQ(orientation(Point{0, 0}, Point{1, 0}, Point{2, 0}), Collinear);
}

TEST(OrientationTests, ExampleCounterClockwiseTest)
{
    EXPECT_EQ(orientation(Point{0, 0}, Point{4, 4}, Point{1, 2}), Counterclockwise);
}

TEST(OrientationTests, TestAll)
{
    Point p1 = {3, 1};
    Point p2 = {4, 1};
    Point p3 = {3.333, 1.666};
    EXPECT_EQ(orientation(p1, p2, p3), Counterclockwise);
    EXPECT_EQ(orientation(p2, p1, p3), Clockwise);
}