#include <gtest/gtest.h>
#include <union.h>
#include <triangle.h>
#include <orientation.h>

struct UnionParams
{
	Triangle t1;
	Triangle t2;
	std::vector<Triangle> expected;
};

std::ostream &operator<<(std::ostream &os, const UnionParams &u) {
	os << u.t1 << "|" << u.t2;
	return os;
}

class InstantiateUnionEdgeTests : public testing::TestWithParam<UnionParams>
{
};

TEST_P(InstantiateUnionEdgeTests, UnionTest)
{
	const Triangle &t1 = GetParam().t1;
	const Triangle &t2 = GetParam().t2;
	auto expected = GetParam().expected;

	ASSERT_NE(orientation(t1), Clockwise);
	ASSERT_NE(orientation(t2), Clockwise);

	auto result = unionize(t1, t2);

	EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(EdgeUnionTests, InstantiateUnionEdgeTests, testing::Values(
																		// Point on top of triangle
																		UnionParams{Triangle({0, 0, 4}, {5, 0, 4}, {2, 3, 4}, 1), Triangle({1, 1, 0}, {1, 1, 0}, {1, 1, 0}, 2), {Triangle({0, 0, 4}, {5, 0, 4}, {2, 3, 4}, 1), Triangle({1, 1, 0}, {1, 1, 0}, {1, 1, 0}, 2)}},
																		// Point on edge of triangle
																		UnionParams{Triangle({0, 0, 6}, {5, 0, 6}, {2, 3, 6}, 1), Triangle({0, 2, 3}, {0, 2, 3}, {0, 2, 3}, 2), {Triangle({0, 0, 6}, {5, 0, 6}, {2, 3, 6}, 1), Triangle({0, 2, 3}, {0, 2, 3}, {0, 2, 3}, 2)}},
																		// Point on vertex of triangle
																		UnionParams{Triangle({0, 0, 2}, {5,0,2}, {2,3,2}, 1), Triangle({0,0,0}, {0,0,0}, {0,0,0}, 2), {Triangle({0, 0, 2}, {5,0,2}, {2,3,2}, 1), Triangle({0,0,0}, {0,0,0}, {0,0,0}, 2)}}
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

	std::vector<Triangle> expected;

	EXPECT_EQ(results, expected);
}
