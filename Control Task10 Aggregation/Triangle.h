#pragma once
#include "Dot.h"
class Triangle
{
private:
    Dot* point1;
    Dot* point2;
    Dot* point3;
public:
    Triangle(Dot* p1, Dot* p2, Dot* p3);
    double area() const;
};

