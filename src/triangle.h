#pragma once

struct Point {
	float x, y;
};

struct Edge {
	Point p1, p2;
};

struct Triangle {
	Point p1, p2, p3;
	int depth;
	// neighbours
};
