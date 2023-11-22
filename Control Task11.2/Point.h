#pragma once
class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {}
    double distanceToCenter() const;
    bool operator<(const Point& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};


