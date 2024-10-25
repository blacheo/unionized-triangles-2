#include <gtest/gtest.h>
#include <triangle.h>

TEST(PointInTriangleTests, PointInTriangle) {
    Triangle t = Triangle({1, 0.5}, {3, 0.2}, {2, 1}, 0);
    EXPECT_TRUE(t.pointInTriangle({1.96, 0.467}));
    EXPECT_FALSE(t.pointInTriangle({1.107,0.834}));
    EXPECT_FALSE(t.pointInTriangle({2.553, 0.823}));
    EXPECT_FALSE(t.pointInTriangle({1.63, 0.13}));
}