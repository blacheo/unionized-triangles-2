#include "triangle_edges.h"
#include "triangle.h"

TriangleEdges::TriangleEdges(const Triangle &t) : e1{Edge{t.points[0], t.points[1]}}, e2{Edge{t.points[1], t.points[2]}}, e3{Edge{t.points[2], t.points[0]}}{
}