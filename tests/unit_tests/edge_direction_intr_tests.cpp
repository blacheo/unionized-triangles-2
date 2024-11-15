#include <intersections.h>
#include <gtest/gtest.h>
#include <edge.h>

TEST(EdgeDirectionIntersectionTests, BasicTests) {
	Edge e1{ {5,0}, {2,3}};

	Edge e2{{3,1}, {6,1}};

	auto result = intersectionWithinEdgeDirection(e1, e2);

	ASSERT_TRUE(result.has_value());

	Point expected = Point{4,1};
	EXPECT_EQ(result.value(), expected);

	Edge e3{{4,3}, {3,1}};
	auto result2 = intersectionWithinEdgeDirection(e3, e1);

	ASSERT_TRUE(result2.has_value());
	Point expected2 = Point{3.33333,1.66667};
	EXPECT_EQ(result2.value(), expected2);

	Edge e4{{3,1}, {4,3}};
	Edge e5{{0,0}, {5,0}};

	auto result3 = intersectionWithinEdgeDirection(e4, e5);
	EXPECT_FALSE(result3.has_value()) << result3.value();
}

