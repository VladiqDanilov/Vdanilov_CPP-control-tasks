#include <iostream>
#include "Dot.h"
#include "Triangle.h"

int main()
{
    std::cout << "\n" << "this is aggregation" << std::endl;
    Dot p1(0, 0);
    Dot p2(3, 0);
    Dot p3(0, 4);

    Triangle triangle(0, 0, 3, 0, 0, 4);

    std::cout << "Area: " << triangle.area() << std::endl;

    return 0;
}

