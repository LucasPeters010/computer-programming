#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class Point {
public:
    Point(int xValue, int yValue) : x(xValue), y(yValue) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void set(int a, int b) { x = a; y = b; }
    Point(const Point& other);
    Point& operator=(const Point&) = delete;
private:
    int x;
    int y;
};
