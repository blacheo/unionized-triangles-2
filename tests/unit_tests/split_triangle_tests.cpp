#include <gtest/gtest.h>
#include <split_triangle.h>
#include <triangle.h>
#include <edge.h>

TEST(SplitTriangleTests, NormalCase) {
    Triangle t = Triangle({0,0}, {0,5}, {2,3}, 1, 1);
    Edge e{{4,3}, {3,1}};

    auto results = splitTriangle(t, e);

    ASSERT_EQ(results.size(), 2);

    auto pos = results[0];
    auto neg = results[1];

    std::vector<Point> expected_pos = {};
    std::vector<Point> expected_neg = {};
    EXPECT_EQ(pos, expected_pos);
    EXPECT_EQ(neg, expected_neg);
}

TEST(SplitTriangleTests, NormalCase2) {
    Triangle t = Triangle({0.1, 9}, {2,4}, {5,5}, 2, 4);
    Edge e{{5,3}, {0,5}};

    auto results = splitTriangle(t, e);

    auto pos = results[0];
    EXPECT_TRUE(pos.size() > 1);
}