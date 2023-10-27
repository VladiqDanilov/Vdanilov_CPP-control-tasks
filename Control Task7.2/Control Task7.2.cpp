#include <iostream>
#include <cmath>

using namespace std;

// ��������� ��� �������� ������ ���������
struct Roots {
    double x1;
    double x2;
};

Roots getRoots(int a, int b, int c) {
    Roots result;

    double d = b * b - 4 * a * c;

    if (d < 0) {
        result.x1 = result.x2 = 0; // ��� �������������� ������
    }
    else if (d == 0) {
        result.x1 = result.x2 = -b / (2 * a); // ���� �������������� ������
    }
    else {
        result.x1 = (-b + sqrt(d)) / (2 * a);
        result.x2 = (-b - sqrt(d)) / (2 * a); // ��� �������������� �����
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b, c;

    cout << "������� a: ";
    cin >> a;
    cout << "������� b: ";
    cin >> b;
    cout << "������� c: ";
    cin >> c;

    Roots roots = getRoots(a, b, c);

    //���������� � ������ ��������������� ����� �������� � ������� �� �� ������
    if (roots.x1 == 0 && roots.x2 == 0) {
        cout << "��� �������������� ������" << endl;
    }
    else if (roots.x1 == roots.x2) {
        cout << "���� ������: x = " << roots.x1 << endl;
    }
    else {
        cout << "��� �����: x1 = " << roots.x1 << ", x2 = " << roots.x2 << endl;
    }
}