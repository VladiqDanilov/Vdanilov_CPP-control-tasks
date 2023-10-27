#include "Triangle.h"
#include "Dot.h"
#include <cmath>
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : point1(x1, y1), point2(x2, y2), point3(x3, y3) {}

double Triangle::area()
{
    double side1 = point1.distanceTo(point2);
    double side2 = point2.distanceTo(point3);
    double side3 = point3.distanceTo(point1);

    double s = (side1 + side2 + side3) / 2.0;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}
