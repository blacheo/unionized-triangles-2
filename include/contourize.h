#pragma once
#include <vector>
#include <string>
#include <exception>

struct Triangle;
struct Point;

class ContourizeException : public std::exception {
    virtual const char *what() const throw();
};

// creates a contour from a list of points 
std::vector<Point> contourize(const std::vector<Point> &points);