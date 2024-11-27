#include <shift_triangle.h>
#include <triangle.h>
#include <constants.h>

void shiftZ(Triangle &t, float z) {
    for (int i =0; i < NB_TRIANGLE_SIDES; i++) {
        t.points[i].z += z;
    }
}