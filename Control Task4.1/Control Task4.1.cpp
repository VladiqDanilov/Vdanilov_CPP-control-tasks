#include <iostream>
#include <math.h>

using namespace std;

int getRoots(int a, int b, int c, double& x1, double& x2) {
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        x1 = x2 = 0;
        return -1;
    }
    else if (d > 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        return 1;
    }
    else
    {
        x1 = x2 = -b / (2 * a);
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int a, b, c;
    double x1, x2;
    cout << "Введите a:" << endl;
    cin >> a;
    cout << ("Введите b:") << endl;
    cin >> b;
    cout << ("Введите c:") << endl;
    cin >> c;

    int res = getRoots(a, b, c, x1, x2);
    cout << "\n" << "Корень уравнения с коэффициентами" << endl;
    cout << "\n" << "a =" << a << endl;
    cout << "\n" << "b =" << b << endl;
    cout << "\n" << "c =" << c << endl;
    if (res == 0)
    {
        cout << "\n" <<" равны x1 = x2 = " << x1 <<endl;
    }
    else if (res == 1)
    {
        cout << "\n" << " равны x1 = " << x1 <<" ; x2 = "<< x2 <<endl;
    }
    else
    {
        cout << "\n" << " нет Действительных" << endl;
    }
}
