#include <gtest/gtest.h>
#include <quad_tree.h>

TEST (QuadTreeTest, OverlappingTriangles) {

    QuadTree q{Box{0, 10, 0, 10}};
    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 1);
    auto t2 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 2);
    auto t3 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 3);
    auto t4 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 4);
    auto t5 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 5);

    q.addTriangle(t1);
    q.addTriangle(t2);
    q.addTriangle(t3);
    q.addTriangle(t4);
    q.addTriangle(t5);
    EXPECT_EQ(q.pointIntersection(Point{1,1}), 1);

}

TEST (QuadTreeTest, SingleInsertion) {
    QuadTree q{Box{0, 10, 0, 10}};

    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 0);

    auto t2 = Triangle(Point{3,1}, Point{6,1}, Point{4,3}, 0);
    

    q.addTriangle(t1);
    q.addTriangle(t2);

    EXPECT_TRUE(true);
}

TEST (QuadTreeTest, PointOnTriangleQueryTest) {
    QuadTree q{Box{0, 10, 0, 10}};

    auto t1 = Triangle(Point{0,0}, Point{5,0},  Point{2,3}, 1, 1);

    auto t2 = Triangle(Point{3,1}, Point{6,1}, Point{4,3}, 2, 2);
    

    q.addTriangle(t1);
    q.addTriangle(t2);

    EXPECT_EQ(q.pointIntersection(Point{1,1}), 1);
    EXPECT_EQ(q.pointIntersection(Point{5,1.5}), 2);
    EXPECT_EQ(q.pointIntersection(Point{3.5, 1.5}), 1);
    EXPECT_EQ(q.pointIntersection(Point{-1,-1}), POINT_NOT_IN_QUADTREE);

}