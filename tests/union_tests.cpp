#include "gtest/gtest.h"
#include <union.h>
#include <triangle.h>
#include <orientation.h>
#include <shift_triangle.h>
#include "union_tests.h"

std::ostream &operator<<(std::ostream &os, const UnionParams &u) {
	os << u.t1 << "|" << u.t2;
	return os;
}

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
		    Triangle({6,1,1}, {3.33333,1.66667,1}, {4,1,1},2),
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
    std::vector<Triangle> expected_results_1 = {
	Triangle({0.1, 7, 5}, {5, 3,5}, {3.2, 9,5}, 2),
    	Triangle({0, 5}, {3, 2}, {5, 3}, 1)
    };

    EXPECT_EQ(results, expected_results_1);

    // Case 2 t2 covers t1
    shiftZ(top, 10);

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2 {
	Triangle({0, 5, 10}, {3, 2, 10}, {5, 3, 10}, 1),
	Triangle({0.1, 7, 5}, {5, 3,5}, {3.2, 9,5}, 2)
    };

    EXPECT_EQ(results, expected_results_2);
}

TEST(UnionTests, FoldTriangleTest)
{

    Triangle top = Triangle({0, 5}, {3, 2}, {5, 3}, 1);
    Triangle bottom = Triangle({0.1, 9,1}, {2, 4,1}, {5,5,1}, 2);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1 = {
	    Triangle({0.1,9,1}, {1.91038,4.23585,1}, {2.27273,4.09091,1}, 2), 
	    Triangle({0.1,9,1}, {2.27273,4.09091,1}, {5,5,1}, 2), 
	    Triangle({0,5,0}, {3,2,0}, {5,3,0}, 1)
    };

    EXPECT_EQ(results, expected_results_1);

    shiftZ(top, 3);

    results = unionize(bottom, top);

    std::vector<Triangle> expected_results_2 = {
	    Triangle({0,5,3}, {2.6129,2.3871,3}, {1.91038,4.23585,3}, 1),
	    Triangle({3,2,3}, {5,3,3}, {2.27273,4.09091,3}, 1), 
	    Triangle({3,2,3}, {2.27273,4.09091,3}, {2.6129,2.3871,3}, 1),
	    Triangle({2.6129,2.3871,3}, {2.27273,4.09091,3}, {2,4,3}, 1), 
	    Triangle({0.1,9,1}, {2,4,1}, {5,5,1}, 2)
    };

    EXPECT_EQ(results, expected_results_2);
}


TEST(UnionTests, StarTest)
{
    Triangle top = Triangle({0, 3,0}, {5, 3,0}, {2.5, 6,0}, 1);
    Triangle bot = Triangle({0, 5, 1}, {2, 0, 1}, {5, 5, 1}, 2);

    ASSERT_EQ(orientation(top.points[0], top.points[1], top.points[2]), Counterclockwise);
    ASSERT_EQ(orientation(bot.points[0], bot.points[1], bot.points[2]), Counterclockwise);

    auto results = unionize(top, bot);

    std::vector<Triangle> expected_results_1 = {
        Triangle({2,0,1}, {3.8, 3,1}, {0.8, 3, 1}, 2),
        Triangle({5,5,1}, {3.33333, 5, 1}, {4.30233, 3.83721, 1}, 2),
        Triangle({0,5,1}, {0.540541, 3.64865, 1}, {1.66667, 5, 1}, 2),
        Triangle({0, 3}, {5, 3}, {2.5, 6}, 1)
    };

    EXPECT_EQ(results, expected_results_1);

    shiftZ(top, 3);

    results = unionize(top, bot);

    std::vector<Triangle> expected_results_2 = {
        Triangle({0,3,3}, {0.8,3,3}, {0.540541,3.64865,3}, 1),
        Triangle({5,3,3}, {4.30233,3.83721,3}, {3.8,3,3}, 1),
        Triangle({2.5,6,3}, {1.66667,5,3}, {3.33333,5,3}, 1),
        Triangle({0,5, 1}, {2,0,1}, {5,5,1}, 2)
    };

    EXPECT_EQ(results, expected_results_2);
}


TEST_P(InstantiateUnionTests, UnionTest)
{
	const Triangle &t1 = GetParam().t1;
	const Triangle &t2 = GetParam().t2;
	auto expected = GetParam().expected;

	ASSERT_NE(orientation(t1), Clockwise);
	ASSERT_NE(orientation(t2), Clockwise);

	auto result = unionize(t1, t2);

	EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(ParameterizedUnionTests, InstantiateUnionTests, testing::Values(
    UnionParams{Triangle({0, 0, 0}, {5, 0, 0}, {2, 3, 0}, 1), Triangle(Point{3, 1, 10}, Point{6, 1, 2}, Point{4, 3, 1}, 2), 
    {Triangle({6,1,2}, {4,3,1}, {3.333333,1.66666,7.23542}, 2),
     Triangle({6,1,2}, {3.33333,1.66667,7.23542}, {4,1,7.3680},2),
      Triangle({0,0}, {5,0}, {2,3}, 1)}}
));