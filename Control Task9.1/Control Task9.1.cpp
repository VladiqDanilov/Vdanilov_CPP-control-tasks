#include <iostream>
#include <cmath> 
#include <stdexcept>

using namespace std;

class TriangleError : public exception
{
public:
    TriangleError(const string& message) : message(message) {}

    const char* what() const
    {
        return message.c_str();
    }

private:
    string message;
};




class  Triangle
{
public:
    Triangle(double a, double b, double c)
    {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
        {
            throw TriangleError("“реугольник с такими сторонами не существует.");
        }

        side_a = a;
        side_b = b;
        side_c = c;
    }

    double side_a;
    double side_b;
    double side_c;
    static double AreaOfTriangle(Triangle& tr) {
        double s = (tr.side_a + tr.side_b + tr.side_c) / 2.0;
        double area = sqrt(s * (s - tr.side_a) * (s - tr.side_b) * (s - tr.side_c));
        return area;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        Triangle tria1(3.0, 4.0, 5.0);
        cout << "площадь треугольника: " << Triangle::AreaOfTriangle(tria1) << endl;
    }
    catch (const TriangleError& error)
    {
        cerr << "ошибка: " << error.what() << endl;
    }
}

