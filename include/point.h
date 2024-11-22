#pragma once
#include <ostream>

struct Point {
	float x, y, z;
	bool operator==(const Point &other) const;
};

std::ostream &operator<<(std::ostream &os, Point const &p);
