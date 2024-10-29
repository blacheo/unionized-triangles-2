#include "gtest/gtest.h"
#include <union.h>
#include<triangle.h>

TEST (UnionTrivialTests, NotTouching) {
    Triangle t1 = Triangle{{0,0}, {5,0}, {2,3}, 0};
    Triangle t2 = Triangle{{6,0}, {10,0}, {7,5}, 0};

    auto ts = unionize(t1, t2);

    EXPECT_TRUE(ts.size() == 2);
}


TEST (UnionTests, TwoIntersections) {

    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 0);
    auto t2 = Triangle(Point{3,1}, Point{6,1}, Point{4,3}, 0);

    auto ts = unionize(t1, t2);

    EXPECT_TRUE(ts.size() > 0);
}