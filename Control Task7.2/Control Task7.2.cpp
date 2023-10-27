#include <iostream>
#include <cmath>

using namespace std;

// Структура для хранения корней уравнения
struct Roots {
    double x1;
    double x2;
};

Roots getRoots(int a, int b, int c) {
    Roots result;

    double d = b * b - 4 * a * c;

    if (d < 0) {
        result.x1 = result.x2 = 0; // Нет действительных корней
    }
    else if (d == 0) {
        result.x1 = result.x2 = -b / (2 * a); // Один действительный корень
    }
    else {
        result.x1 = (-b + sqrt(d)) / (2 * a);
        result.x2 = (-b - sqrt(d)) / (2 * a); // Два действительных корня
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b, c;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;

    Roots roots = getRoots(a, b, c);

    //обращаемся к корням непосредственно через значения в отличие от по ссылке
    if (roots.x1 == 0 && roots.x2 == 0) {
        cout << "Нет действительных корней" << endl;
    }
    else if (roots.x1 == roots.x2) {
        cout << "Один корень: x = " << roots.x1 << endl;
    }
    else {
        cout << "Два корня: x1 = " << roots.x1 << ", x2 = " << roots.x2 << endl;
    }
}