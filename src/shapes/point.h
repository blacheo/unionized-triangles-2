#pragma once

struct Point {
	float x, y;
	bool operator==(const Point &other) const;
};