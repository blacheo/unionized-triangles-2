#include <gtest/gtest.h>
#include <quad_tree.h>

TEST (QuadTreeTests, QuadTreeTest) {
    QuadTree q{{0, 10, 0, 10}};
    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 0);
    q.addTriangle(t1);

    EXPECT_TRUE(q.visibleSurface().size() > 0);
}