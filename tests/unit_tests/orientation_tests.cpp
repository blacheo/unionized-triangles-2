#include <gtest/gtest.h>
#include <orientation.h>
#include <point.h>

TEST (OrientationTests, Collinear) {
    EXPECT_EQ(orientation(Point{0,0}, Point{1,0}, Point{2,0}), Collinear);
}

TEST (OrientationTests, ExampleCounterClockwiseTest) {
    EXPECT_EQ(orientation(Point{0,0}, Point{4,4}, Point{1,2}), Counterclockwise);
}
