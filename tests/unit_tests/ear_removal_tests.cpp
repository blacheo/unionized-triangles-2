#include <gtest/gtest.h>
#include <triangulation.h>
#include <vector>
#include <point.h>
#include <pointList.h>

TEST(EarRemovalTests, SingleEarRemoval) {
    std::vector<Point> polygon = {
        {3,48}, {52, 8}, {99,50}, {138,25},
         {175, 77}, {131, 72}, {111, 113},
          {72, 43}, {26, 55}, {29, 100}};

    PointList pointList = PointList(polygon);
    int index = 0;
    auto t = removeEar(index, pointList, polygon, 0,0);
    EXPECT_FALSE(t.has_value());
    EXPECT_TRUE(true);

    auto t2 = removeEar(index, pointList, polygon,0,0);

    auto t3 = removeEar(index, pointList, polygon,0,0);
}