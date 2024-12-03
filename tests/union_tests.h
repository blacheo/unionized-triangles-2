#pragma once
#include <triangle.h>

struct UnionParams
{
	Triangle t1;
	Triangle t2;
	std::vector<Triangle> expected;
};

class InstantiateUnionTests : public testing::TestWithParam<UnionParams>{};


std::ostream &operator<<(std::ostream &os, const UnionParams &u);

