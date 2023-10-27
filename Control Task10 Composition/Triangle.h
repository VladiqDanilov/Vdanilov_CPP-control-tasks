#pragma once
#include "Dot.h"
class Triangle
{
public:
    Dot point1;
    Dot point2;
    Dot point3;

    Triangle(double x1, double y1, 
        double x2, double y2, double x3, double y3);
    double area();
};

