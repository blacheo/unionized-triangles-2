#include <gtest/gtest.h>
#include <union.h>
#include <triangle.h>
#include <orientation.h>
#include "union_tests.h"



INSTANTIATE_TEST_SUITE_P(EdgeUnionTests, InstantiateUnionTests, testing::Values(
																		// Point on top of triangle
																		UnionParams{Triangle({0, 0, 4}, {5, 0, 4}, {2, 3, 4}, 1), Triangle({1, 1, 0}, {1, 1, 0}, {1, 1, 0}, 2), {Triangle({0, 0, 4}, {5, 0, 4}, {2, 3, 4}, 1), Triangle({1, 1, 0}, {1, 1, 0}, {1, 1, 0}, 2)}},
																		// Point on edge of triangle
																		UnionParams{Triangle({0, 0, 6}, {5, 0, 6}, {2, 3, 6}, 1), Triangle({0, 2, 3}, {0, 2, 3}, {0, 2, 3}, 2), {Triangle({0, 0, 6}, {5, 0, 6}, {2, 3, 6}, 1), Triangle({0, 2, 3}, {0, 2, 3}, {0, 2, 3}, 2)}},
																		// Point on vertex of triangle
																		UnionParams{Triangle({0, 0, 2}, {5,0,2}, {2,3,2}, 1), Triangle({0,0,0}, {0,0,0}, {0,0,0}, 2), {Triangle({0, 0, 2}, {5,0,2}, {2,3,2}, 1), Triangle({0,0,0}, {0,0,0}, {0,0,0}, 2)}},
																		// Line and Triangle
																		UnionParams{Triangle({0,0,5}, {5,0,5}, {2,3,5}, 1), Triangle({0,0,0}, {1,1,0}, {6,6,0}, 2), {Triangle({0,0,5}, {5,0,5}, {2,3,5}, 1), Triangle({0,0,0}, {1,1,0}, {6,6,0}, 2)}}
																		));

TEST(UnionEdgeTests, TriangleVertexOnEdge)
{
	Triangle t1 = Triangle({}, {}, {}, 1);
	Triangle t2 = Triangle({}, {}, {}, 2);

	auto result = unionize(t1, t2);
}

TEST(UnionEdgeTests, TriangleIsPoint)
{
	Triangle t1 = Triangle({1, 1, 2}, {2, 2, 2}, {3, 3, 2}, 1);
	Triangle t2 = Triangle({2, 2, 1}, {2, 2, 1}, {2, 2, 1}, 2);

	auto results = unionize(t1, t2);

	std::vector<Triangle> expected = {
		Triangle({1, 1, 2}, {2, 2, 2}, {3, 3, 2}, 1),
		Triangle({2, 2, 1}, {2, 2, 1}, {2, 2, 1}, 2)};

	EXPECT_EQ(results, expected);
}

TEST(UnionEdgeTests, TriangleOnSide)
{
	Triangle t1 = Triangle({0, 0, 1}, {0, 5, 1}, {2, 3, 1}, 1);
	Triangle t2 = Triangle({0, 1}, {1, 1}, {0, 3}, 2);

	auto results = unionize(t1, t2);

	std::vector<Triangle> expected = {
		Triangle({0,0,1}, {0.666667,1,1}, {0,1,1}, 1),
		Triangle({0,5,1}, {0,3,1}, {0.857143,1.28571,1}, 1),
		Triangle({0,5,1}, {0.857143,1.28571,1}, {2,3,1}, 1),
		Triangle({0,1,0}, {1,1,0}, {0,3,0}, 2)
	};

	EXPECT_EQ(results, expected);
}

