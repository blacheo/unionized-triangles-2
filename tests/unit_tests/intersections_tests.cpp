#include <intersections.h>
#include <gtest/gtest.h>
#include <edge.h>

TEST (IntersectionTests, EdgeToEdgeTest) {
    Edge e1 {{5,0}, {2,6}};
    Edge e2 {{1,1}, {4,2}};

    auto p = intersectionWithinEdge(e1, e2);
    Point actual_point = p.value();
    Point expected_point = Point{4,2};
    EXPECT_TRUE(actual_point == expected_point);
}


TEST (IntersectionTests, EdgeTest) {
    Edge e1{{0.8, 3}, {5,3}};
    Edge e2{{2,0}, {5,5}};

    auto p = intersectionFirstSide(e1,e2);

    EXPECT_TRUE(p.has_value());
}