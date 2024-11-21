#include <gtest/gtest.h>
#include <split_triangle.h>
#include <triangle.h>
#include <edge.h>

TEST(SplitTriangleTests, NormalCase) {
    Triangle t = Triangle({0,0}, {5,0}, {2,3}, 1, 1);
    Edge e{{4,3}, {3,1}};

    auto results = splitShape(std::vector<Point>{t.points[0], t.points[1], t.points[2]}, e);

    ASSERT_EQ(results.size(), 2);

    auto pos = results[0];
    auto neg = results[1];

    std::vector<Point> expected_pos = {{0,0}, {2,3}};
    std::vector<Point> expected_neg = {{5,0}};
    EXPECT_EQ(pos, expected_pos);
    EXPECT_EQ(neg, expected_neg);
}

TEST(SplitTriangleTests, NormalCase2) {
    std::vector<Point> t {{0.1, 9}, {2,4}, {5,5}};
    Edge e{{5,3}, {0,5}};

    auto results = splitShape(t, e);

    auto pos = results[0];
    EXPECT_TRUE(pos.size() > 1);
}

TEST(SplitTriangleTests, InvisibleIntersection) {
    Edge e {{0.1,9}, {2,4}};
    std::vector<Point> t{{0,5}, {3,2}, {5,5}};

    auto results = splitShape(t,e);

    EXPECT_TRUE(results[1].size() > 2);
}

TEST (SplitTriangleTests, Quadric) {
    Edge e {{2,4}, {5,5}};
    std::vector<Point> p{{3,2}, {5,3}, {1.91037738, 4.2358489}, {2.61290312,2.38709688}};

    auto results = splitShape(p,e);

    EXPECT_TRUE(results[0].size() > 2);
}