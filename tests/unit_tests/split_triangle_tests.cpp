#include <gtest/gtest.h>
#include <split_triangle.h>
#include <triangle.h>
#include <edge.h>


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

TEST(SplitTriangleTests, OnEdge1) {
    std::vector<Point> t {{0,0}, {0,5}, {2,3}};
    Edge e = Edge{{1,1}, {0,1}};

    auto results = splitShape(t, e);

    EXPECT_EQ(results[0].size(), 4);
    EXPECT_EQ(results[1].size(), 3);
}

TEST(SplitTriangleTests, OnEdge2) {

    std::vector<Point> t {{0,0}, {0,5}, {2,3}};
    Edge e {{1,1}, {0,3}};

    auto results = splitShape(t,e);

    EXPECT_EQ(results[0].size(), 4);
}
