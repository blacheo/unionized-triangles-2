#include <intersections.h>
#include <gtest/gtest.h>
#include <edge.h>

TEST (IntersectionTests, EdgeToEdgeTest) {
    Edge e1 {{5,0}, {2,6}};
    Edge e2 {{1,1}, {4,2}};

    auto p = intersection(e1, e2);
    Point actual_point = p.value();
    Point expected_point = Point{4,2};
    EXPECT_TRUE(actual_point == expected_point);
}
