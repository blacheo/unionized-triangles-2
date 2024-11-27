#include <gtest/gtest.h>
#include <convex_triangulation.h>
#include <vector>

TEST(ConvexTriangulationTests, Simple) {
	
	Point p1{1,3};
	Point p2{2,2};
	Point p3{3,2.1};
	Point p4{4,3.2};
	Point p5{2.1,4};

	std::vector<Point> points = {
		p1, p2, p3, p4, p5
	};	

	auto results = convexTriangulation(points, 2);

	std::vector<Triangle> expected_result {
		Triangle(p1, p2, p3, 2),
			Triangle(p1, p3, p5, 2),
			Triangle(p5, p3, p4, 2)
	};
	
	EXPECT_EQ(results, expected_result);

}

TEST(ConvexTriangulationTests, TrivialTriangle) {
	std::vector<Point> points = {
		{0,0},
		{2,0},
		{1.5, 2}
	};

	auto results = convexTriangulation(points, 1);
	Triangle expected_triangle = Triangle({0,0}, {2,0}, {1.5, 2}, 1);

	EXPECT_EQ(results.size(), 1);
	EXPECT_EQ(results[0], expected_triangle);
}
