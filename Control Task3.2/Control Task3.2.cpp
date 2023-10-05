#include <iostream>
#include <cmath>
using namespace std;

// вычисление кубического корня с использованием pow
double cubicRootUsingPow(double x) {
    return pow(x, 1.0 / 3);
}

// вычисление кубического корня с использованием итерационной формулы
double cubicRootUsingIteration(double x, double epsilon = 1e-6) {
    double result = x;
    double prevResult;

    do {
        prevResult = result;
        result = (1.0 / 3) * (2 * prevResult + x / (prevResult * prevResult));
    } while (abs(result - prevResult) >= epsilon); //пока разница между текущим и предыдущим 
                                                    //приближениями не станет меньше или равна epsilon.


    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    double number;

    cout << "ведите число: ";
    cin >> number;
    cout << "\n";

    double cubicRoot1 = cubicRootUsingPow(number);
    double cubicRoot2 = cubicRootUsingIteration(number);

    cout << "Кубический корень (pow): " << cubicRoot1 << endl;
    cout << "Кубический корень (итерация): " << cubicRoot2 << endl;
    cout << "\n" << endl;
    if (cubicRoot1 == cubicRoot2) {
        cout << '\n' << "приближение точно" << endl;
    }
    else
    {
        cout << '\n' << "вычисленное значение дальше от истинного больше чем на 1e-6" << endl;
    }

    return 0;
}
