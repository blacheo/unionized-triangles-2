#include "triangle_edges.h"
#include "triangle.h"

TriangleEdges::TriangleEdges(const Triangle &t) : e1{Edge{t.p1, t.p2}}, e2{Edge{t.p2, t.p3}}, e3{Edge{t.p3, t.p1}}{
}