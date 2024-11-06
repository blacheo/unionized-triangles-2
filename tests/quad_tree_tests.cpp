#include <gtest/gtest.h>
#include <quad_tree.h>

TEST (QuadTreeTest, SingleInsertion) {
    QuadTree q{Box{0, 10, 0, 10}};

    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 0);

    auto t2 = Triangle(Point{3,1}, Point{6,1}, Point{4,3}, 0);
    

    q.addTriangle(std::make_shared<Triangle>(t1));
    q.addTriangle(std::make_shared<Triangle>(t2));

    EXPECT_TRUE(true);
}