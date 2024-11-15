#include <gtest/gtest.h>
#include <contourize.h>
#include <triangle.h>
#include <intersections.h>

TEST(ContourizeTest, Simple) {
	std::vector<Point> points{{6,1}, {4,3}, {4, 1}, {3.3333, 1.6666}};

	auto result = contourize(points);

	std::vector<Point> expected{{4,1}, {3.3333,1.6666}, {4,3}, {6,1}};
	EXPECT_EQ(result, expected);
}


