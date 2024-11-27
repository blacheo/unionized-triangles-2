#include <gtest/gtest.h>
#include <triangle.h>
#include <union.h>

TEST (UnionNeighbourTests, NeighbourTest) {
	Triangle t1 = Triangle({}, {}, {}, 1, {2});
	Triangle t2 = Triangle({}, {}, {}, 2, {1});

	auto results = unionize(t1, t2);
	std::vector<Triangle> expected ={t1, t2} ;

	EXPECT_EQ(results, expected);
}
