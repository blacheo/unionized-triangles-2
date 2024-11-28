#include <gtest/gtest.h>
#include <contourize.h>
#include <triangle.h>
#include <intersections.h>

TEST(ContourizeTest, Simple) {
	std::vector<Point> points{{0,0}, {5,0}, {2, 3}};

	auto result = contourize(points);

	std::vector<Point> expected{{0,0}, {5,0}, {2, 3}};
	EXPECT_EQ(result, expected);
}

TEST (ContourizeTest, Collinear) {
	std::vector<Point> points {{2,3,5}, {0,0,5}, {2.5,2.5,5}, {-0,0,5}};
	auto result = contourize(points);
	
}

TEST(ContourizeTest, Triangle) {
	std::vector<Point> points{{3,1}, {4,1}, {3.33333, 1.6666}};
	auto result = contourize(points);

	std::vector<Point> expected{{3,1}, {4,1}, {3.33333, 1.6666}};
	EXPECT_EQ(result, expected);
}

/*
TEST(ContourizeTest, TestCase3) {

	std::vector<Point> points{{0.100000001,9}, {5,5}, {1.91037738, 4.2358489}, {2.27272725, 4.090909}, {9.80392265, 1.07843113}};
	auto result = contourize(points);


	std::vector<Point> expected{{3,1}, {4,1}, {3.33333, 1.6666}};
	EXPECT_EQ(result, expected);
}*/
