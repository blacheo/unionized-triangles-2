#include <union.h>
#include <contourize.h>
#include <triangle.h>
#include <constants.h>
#include <list>
#include <triangle_edges.h>
#include <intersections.h>

std::vector<Triangle> unionizeTopAndBottom(const Triangle &top, const Triangle &bot) {
	std::vector<Triangle> result;

	std::list<Point> intr;
	TriangleEdges topEdges = TriangleEdges(top);

	// keep track of relevant triangles
	
	for (int i = 0; i < NB_TRIANGLE_SIDES; i++) {
		const Edge &e = topEdges.edges[i]; 
		auto newIntr = intersections(e, bot);
		// split triangle if exists
		// currently relevant triangles
		// add these to result
		
		// future relevant triangles
		// use to 

		// filter using previous edges

		// create shape if points exists
		contourize();
	}
	return result;

}
