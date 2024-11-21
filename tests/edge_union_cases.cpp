#include <gtest/gtest.h>
#include <union.h>
#include <triangle.h>

TEST(UnionEdgeTests, TriangleVertexOnEdge) {
	Triangle t1 = Triangle({}, {}, {}, 1, 1);
	Triangle t2 = Triangle({}, {}, {}, 2, 2);

	auto result = unionize(t1, t2);

}

TEST(UnionEdgeTests, TriangleEdgeLength0) {
	Triangle t1 = Triangle({1,1}, {2,2}, {3,3}, 1, 1);
	Triangle t2 = Triangle({}, {}, {}, 2, 2);
}

TEST(UnionEdgeTests, TriangleOnSide) {
	Triangle t1 = Triangle({}, {}, {}, 1, 1);
	Triangle t2 = Triangle({}, {}, {}, 2, 2);
}
