#include <iostream>
#include "Point.h"
double Point::distanceToCenter() const
{
	return sqrt(x * x + y * y);
}
bool Point::operator<(const Point& other) const {
	return Point::distanceToCenter() < other.distanceToCenter();
}


