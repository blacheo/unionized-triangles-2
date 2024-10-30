cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
	tests/unit_tests/simple_triangle_tests.cpp
	tests/unit_tests/contourize_tests.cpp
	tests/unit_tests/point_in_triangle_tests.cpp
	tests/unit_tests/triangulation_tests.cpp
	tests/unit_tests/ear_removal_tests.cpp
	src/utilities/intersections.cpp
	tests/union_tests.cpp
	src/shapes/triangle.cpp
	src/shapes/triangle_edges.cpp
	src/utilities/contourize.cpp
	src/shapes/edge.cpp
	src/utilities/orientation.cpp
	src/shapes/point.cpp
	src/union.cpp
	src/utilities/triangulation.cpp
	src/utilities/pointList.cpp
	tests/unit_tests/orientation_tests.cpp
)

include_directories(include)

target_link_libraries(
	tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

