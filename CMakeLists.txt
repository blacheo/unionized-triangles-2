cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_BUILD_TYPE Debug)

enable_testing()

project(intersection)

add_executable(
	tests
	tests/unit_tests/split_triangle_tests.cpp
	src/debug_utilities/mostly_equal.cpp
	tests/unit_tests/simple_triangle_tests.cpp
	tests/unit_tests/point_in_triangle_tests.cpp
	src/utilities/intersections.cpp
	tests/union_tests.cpp
	src/shapes/triangle.cpp
	src/shapes/triangle_edges.cpp
	src/utilities/contourize.cpp
	src/shapes/edge.cpp
	src/utilities/orientation.cpp
	src/shapes/point.cpp
	src/union.cpp
	src/utilities/pointList.cpp
	tests/unit_tests/orientation_tests.cpp
	tests/unit_tests/intersections_tests.cpp
	src/data_structures/box.cpp
	tests/edge_union_cases.cpp
	tests/unit_tests/convex_triangulation_tests.cpp
	src/utilities/convex_triangulation.cpp
	tests/unit_tests/edge_direction_intr_tests.cpp
	tests/unit_tests/contourize_tests.cpp
	src/debug_utilities/print_triangles.cpp
	src/utilities/split_triangle.cpp
	tests/unit_tests/orientation_tests.cpp
	tests/union_neighbours_tests.cpp
	src/debug_utilities/shift_triangle.cpp
	src/utilities/interpolate_z.cpp
	tests/unit_tests/interpolate_z_tests.cpp
)

include_directories(include)

target_link_libraries(
	tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

