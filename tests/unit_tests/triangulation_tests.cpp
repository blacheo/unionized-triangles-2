#include "gtest/gtest.h"
#include <point.h>
#include <triangulation.h>

TEST(TriangulationTests, Page3Example) {
    std::vector<Point> polygon = {
        {3,48}, {52, 8}, {99,50}, {138,25},
         {175, 77}, {131, 72}, {111, 113},
          {72, 43}, {26, 55}, {29, 100}};

    auto t = triangulate(polygon);    
    EXPECT_TRUE(t.size() > 0);
}