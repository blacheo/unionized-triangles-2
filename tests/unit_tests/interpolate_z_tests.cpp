#include <gtest/gtest.h>
#include <interpolate_z.h>
#include <point.h>
#include <edge.h>

struct InterpolateParams {
    Edge e;
    Point point;
    float expected_z;
};

std::ostream &operator<<(std::ostream & out, const Edge &e) {
    return out << e.p1 << ", " << e.p2;
}

std::ostream &operator<<(std::ostream & out, const InterpolateParams &p) {
    return out << "Edge: " << p.e << "Point: " << p.point;
}

class InstantiateInterpolateZTests : public testing::TestWithParam<InterpolateParams>{
};

TEST_P (InstantiateInterpolateZTests, Interpolate) {
    
	Edge e = GetParam().e;
    Point point = GetParam().point;

    float z = interpolateZ(e, point);

    EXPECT_EQ(z,GetParam().expected_z);
}

INSTANTIATE_TEST_SUITE_P(Interpolation, InstantiateInterpolateZTests, testing::Values(
    InterpolateParams{{{1,1,3}, {2,2,3}}, {1.5,1.5},3},
    InterpolateParams{{{1,1,5}, {1,1,5}}, {1,1},5},
    InterpolateParams{{{1,1,10}, {2,3,15}}, {2,3},15},
    InterpolateParams{{{1,1,10}, {2,2,0}}, {1,1},10},
    InterpolateParams{{{1,1,10}, {2,2,0}}, {2,2},0},
    InterpolateParams{{{5, 3,3}, {2.5, 6,3}}, {0.540541,3.64865},3}
    ));

