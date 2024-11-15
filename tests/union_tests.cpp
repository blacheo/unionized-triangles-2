#include "gtest/gtest.h"
#include <union.h>
#include <triangle.h>

TEST(UnionTrivialTests, NotTouching)
{
    Triangle t1 = Triangle{{0, 0}, {5, 0}, {2, 3}, 0};
    Triangle t2 = Triangle{{6, 0}, {10, 0}, {7, 5}, 0};

    auto ts = unionize(t1, t2);

    EXPECT_TRUE(ts.size() == 2);
}

TEST(UnionTests, TwoIntersections)
{

    auto t1 = Triangle(Point{0, 0}, Point{5, 0}, Point{2, 3}, 0);
    auto t2 = Triangle(Point{3, 1}, Point{6, 1}, Point{4, 3}, 1);

    auto ts = unionize(t1, t2);

    EXPECT_TRUE(ts.size() == 3);

    std::vector<Triangle> expected{
	    Triangle({4,1}, {3.3333, 1.6666}, {4,3}, 1, 0),
		    Triangle({4,1}, {4,3}, {6,1}, 1,0),
    Triangle({0,0}, {5,0}, {2,3}, 0, 0)};
    EXPECT_EQ(ts, expected);
}

// Edge Case
TEST(UnionTests, SharesPointTest)
{
    // Case 1 t1 covers t2
    Triangle bottom = Triangle({0, 5}, {3, 2}, {5, 3}, 1, 1);
    Triangle top = Triangle({0.1, 7}, {5, 3}, {3.2, 9}, 2, 2);

    auto results = unionize(bottom, top);
    std::vector<Triangle> expected_results_1;

    EXPECT_EQ(results, expected_results_1);

    // Case 2 t2 covers t1
    bottom.depth = 3;

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2;

    EXPECT_EQ(results, expected_results_2);
}

TEST(UnionTests, FoldTriangleTest)
{

    Triangle bottom = Triangle({0, 5}, {3, 2}, {5, 3}, 1, 1);
    Triangle top = Triangle({0.1, 9}, {5, 5}, {2, 4}, 2, 2);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1;

    EXPECT_EQ(results, expected_results_1);

    bottom.depth = 3;

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2;

    EXPECT_EQ(results, expected_results_2);
}

TEST(UnionTests, IceCreamTest)
{
    Triangle bottom = Triangle({0, 5}, {3, 2}, {5, 3}, 2, 1);
    Triangle top = Triangle({-1, 5}, {2, 4}, {5, 7}, 1, 2);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1;

    EXPECT_EQ(results, expected_results_1);

    top.depth = 3;

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2;

    EXPECT_EQ(results, expected_results_2);
}

TEST(UnionTests, StarTest)
{
    Triangle bottom = Triangle({0, 3}, {2.5, 6}, {5, 3}, 1, 1);
    Triangle top = Triangle({0, 5}, {2, 0}, {5, 5}, 2, 2);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1;

    EXPECT_EQ(results, expected_results_1);

    bottom.depth = 3;

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2;

    EXPECT_EQ(results, expected_results_2);
}
