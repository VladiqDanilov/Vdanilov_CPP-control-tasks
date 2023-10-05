#include <iostream>
#include <cmath>
using namespace std;

double AreaOfTriangle(double sideLength) {
    double s = 3 * sideLength / 2;

    double area = sqrt(s * pow((s - sideLength), 3));
    return area;
}
double AreaOfTriangle(double a, double b, double c) {
    //существует ли треугольник с данными сторонами
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        cout << "Треугольник с такими сторонами не существует." << endl;
        return 0.0;
    }

    double s = (a + b + c) / 2.0;

    // Используем формулу Герона для вычисления площади
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int statem;
    double res;
    cout << "Выберите функцию для треугольника" << endl;
    cout << "1. Посчитать площадь равностороннего\n";
    cout << "2. Посчитать площадь разностороннего\n";
    cout << "3. Выход\n";
    cout << "Введите число: ";
    cin >> statem;
    cout << "\n" << endl;
    switch (statem) {
    case 1:
        double side;
        cout << "площадь РАВНостороннего тр." << endl;
        cout << "\n" << "Введите длину стороны" << endl;
        cin >> side;
        res = AreaOfTriangle(side);
        cout << "\n" << "Площадь треугольника Равна: " << endl;
        cout << '\n' << res << endl;
        break;
    case 2:
        double a, b, c;
        cout << "\n" << "площадь РАЗНостороннего тр." << endl;
        cout << "\n" << "введите 1 сторону треугольника " << endl;
        cin >> a;
        cout << "\n" << "введите 2 сторону треугольника " << endl;
        cin >> b;
        cout << "\n" << "введите 3 сторону треугольника " << endl;
        cin >> c;
        res = AreaOfTriangle(a, b, c);
        cout << "\n" << "Площадь треугольника Равна: " << endl;
        cout << '\n' << res << endl;
        break;
    case 3:
        exit;
    }
}