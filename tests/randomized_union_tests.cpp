#include <gtest/gtest.h>
#include <triangle.h>
#include <union.h>

class RandomizedUnionTests {
    public testing::TestWithParam<>
};

float triangleArea() {
    
}

TEST_P(RandomizedUnionTests, RandomTest)
{

    Triangle top = Triangle({0, 5}, {3, 2}, {5, 3}, 1, 1);
    Triangle bottom = Triangle({0.1, 9}, {2, 4}, {5,5}, 2, 2);

    auto results = unionize(bottom, top);

    std::vector<Triangle> expected_results_1 = {
        Triangle({0.1, 9}, {1.91038, 4.23585}, {5,5}, 2, 2),
        Triangle({1.91038,4.23585}, {2.27273,4.09091}, {5, 5}, 2, 2),
        Triangle({0,5}, {3,2}, {5,3}, 1, 1)
    };

    EXPECT_EQ(results, expected_results_1);
}