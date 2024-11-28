#include "gtest/gtest.h"
#include <union.h>
#include <triangle.h>
#include <orientation.h>
#include <shift_triangle.h>

TEST(UnionTrivialTests, NotTouching)
{
    Triangle t1 = Triangle{{0, 0}, {5, 0}, {2, 3}, 0};
    Triangle t2 = Triangle{{6, 0}, {10, 0}, {7, 5}, 0};

    auto ts = unionize(t1, t2);

    EXPECT_TRUE(ts.size() == 2);
}

TEST(UnionTests, TwoIntersections)
{

    auto t1 = Triangle(Point{0, 0, 0}, Point{5, 0, 0}, Point{2, 3, 0}, 1);
    auto t2 = Triangle(Point{3, 1, 1}, Point{6, 1, 1}, Point{4, 3, 1}, 2);

    auto ts = unionize(t1, t2);

    EXPECT_TRUE(ts.size() == 3);

    std::vector<Triangle> expected{
	    Triangle({6,1,1}, {4,3,1}, {3.333333,1.66666,1}, 2),
		    Triangle({4,3,1}, {3.33333,1.66667,1}, {4,1,1},2),
    Triangle({0,0}, {5,0}, {2,3}, 1)};
    EXPECT_EQ(ts, expected);
}

// Edge Case

TEST(UnionTests, SharesPointTest)
{
    // Case 1 t1 covers t2
    Triangle top = Triangle({0, 5}, {3, 2}, {5, 3}, 1);
    Triangle bottom = Triangle({0.1, 7, 5}, {5, 3,5}, {3.2, 9,5}, 2);

    auto results = unionize(bottom, top);
    std::vector<Triangle> expected_results_1;

    EXPECT_EQ(results, expected_results_1);

    // Case 2 t2 covers t1
    shiftZ(top, 10);

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2;

    EXPECT_EQ(results, expected_results_2);
}

TEST(UnionTests, FoldTriangleTest)
{

    Triangle top = Triangle({0, 5}, {3, 2}, {5, 3}, 1);
    Triangle bottom = Triangle({0.1, 9,1}, {2, 4,1}, {5,5,1}, 2);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1 = {
        Triangle({0, 5,3}, {2.6129, 2.3871,3}, {1.91038,4.23585,3}, 1),
        Triangle({3, 2,3}, {5, 3,3}, {2.27273,4.09091,3}, 1),
        Triangle({3,2,3}, {2.27273,4.09091,3}, {2.6129,2.3871,3}, 1),
        Triangle({2.6129,2.3871,3}, {2.27273,4.09091,3}, {2,4,3}, 1),
        Triangle({0.1,9,1}, {2,4,1}, {5,5,1}, 2)
    };

    EXPECT_EQ(results, expected_results_1);

    shiftZ(top, 3);

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2 = {
        Triangle({0,5, 3}, {2.6129, 2.3871, 3}, {1.91038, 4.23585, 3}, 1),
        Triangle({3,2, 3}, {5, 3, 3}, {2.6129, 2.3871, 3}, 1),
        Triangle({5,3, 3}, {2.27273, 4.09091, 3}, {2.6129, 2.3871, 3}, 1),
        Triangle({2.27273,4.09091, 3}, {2, 4, 3}, {2.6129, 2.3871, 3}, 1),
        Triangle({0.1,9}, {2, 4}, {5, 5}, 2)
    };

    EXPECT_EQ(results, expected_results_2);
}
/*
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
}*/

TEST(UnionTests, StarTest)
{
    Triangle bottom = Triangle({0, 3}, {5, 3}, {2.5, 6}, 1);
    Triangle top = Triangle({0, 5, 1}, {2, 0, 1}, {5, 5, 1}, 2);

    ASSERT_EQ(orientation(bottom.points[0], bottom.points[1], bottom.points[2]), Counterclockwise);
    ASSERT_EQ(orientation(top.points[0], top.points[1], top.points[2]), Counterclockwise);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1 = {
        Triangle({2,0}, {3.8, 3}, {0.8, 3}, 2),
        Triangle({5,5}, {3.33333, 5}, {4.30233, 3.83721}, 2),
        Triangle({0,5}, {0.540541, 3.64865}, {1.66667, 5}, 2),
        Triangle({0, 3}, {5, 3}, {2.5, 6}, 1)
    };

    EXPECT_EQ(results, expected_results_1);

    shiftZ(bottom, 3);

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2 = {
        Triangle({0,3}, {0.8,3}, {0.540541,3.64865}, 1),
        Triangle({5,3}, {4.30233,3.83721}, {3.8,3}, 1),
        Triangle({2.5,6}, {1.66667,5}, {3.33333,5}, 1),
        Triangle({0,5}, {2,0}, {5,5}, 2)
    };

    EXPECT_EQ(results, expected_results_2);
}

TEST (UnionTests, DepthTest) {

}