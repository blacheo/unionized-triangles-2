#include <gtest/gtest.h>
#include <orientation.h>
#include <point.h>

TEST (OrientationTests, CounterClockwiseTest) {
    
    EXPECT_EQ(orientation(Point{0,0}, Point{1,0}, Point{0.5, 0.5}), Counterclockwise);
}

TEST (OrientationTests, Clockwise) {
    EXPECT_EQ(orientation(Point{0,0}, Point{0.5, 0.5}, Point{1,0}), Clockwise);
}

TEST (OrientationTests, Collinear) {
    EXPECT_EQ(orientation(Point{0,0}, Point{1,0}, Point{2,0}), Collinear);
}

TEST (OrientationTests, ExampleCounterClockwiseTest) {
    EXPECT_EQ(orientation(Point{0,0}, Point{4,4}, Point{1,2}), Counterclockwise);
}

/*TEST (OrientationTests, Counterclockwise2Test) {
    EXPECT_EQ(orientation({}, {}, {}), Counterclockwise);
}*/