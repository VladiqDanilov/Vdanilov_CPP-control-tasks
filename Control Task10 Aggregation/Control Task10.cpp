#include <iostream>
#include "Dot.h"
#include "Triangle.h"

int main()
{
    std::cout << "\n" << "this is aggregation" << std::endl;
    Dot p1(0, 0);
    Dot p2(3, 0);
    Dot p3(0, 4);

    Triangle triangle(&p1, &p2, &p3);

    std::cout << "Area: " << triangle.area() << std::endl;

    return 0;
}

