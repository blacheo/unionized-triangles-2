#include <gtest/gtest.h>
#include <interpolate_z.h>
#include <point.h>

struct InterpolateParams {
    std::vector<Point> points;
    float expected_z;
};

class InstantiateInterpolateZTests : public testing::TestWithParam<InterpolateParams>{
};

TEST_P (InstantiateInterpolateZTests, Interpolate) {
    
	std::vector<Point> points = GetParam().points;

    float z = interpolateZ(points, {0,1,0});

    EXPECT_EQ(z,GetParam().expected_z);
}

INSTANTIATE_TEST_SUITE_P(Interpolation, InstantiateInterpolateZTests, testing::Values(
    InterpolateParams{
        {{1,1,3}, {2,2,3}, {4,5,3}}
        , 3},
    InterpolateParams{{{1,1,5}, {1,1,5}, {1,1,5}}, 5}));