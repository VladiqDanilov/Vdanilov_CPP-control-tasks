// Tasks 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    int x5, y5;

    cout << "���������� ������� ���������� ������ ��������������� ������ ������� �������" << endl;
    cout << "������� x-���������� ������� 1: ";
    cin >> x1;
    cout << "������� y-���������� ������� 1: ";
    cin >> y1;

    cout << "������� x-���������� ������� 2: ";
    cin >> x2;
    cout << "������� y-���������� ������� 2: ";
    cin >> y2;

    cout << "������� x-���������� ������� 3: ";
    cin >> x3;
    cout << "������� y-���������� ������� 3: ";
    cin >> y3;

    cout << "������� x-���������� ������� 4: ";
    cin >> x4;
    cout << "������� y-���������� ������� 4: ";
    cin >> y4;

    cout << "������� x-���������� ������� 5: ";
    cin >> x5;
    cout << "������� y-���������� ������� 5: ";
    cin >> y5;

    int sum = 0;
    sum += (x1 * y2 - x2 * y1);
    sum += (x2 * y3 - x3 * y2);
    sum += (x3 * y4 - x4 * y3);
    sum += (x4 * y5 - x5 * y4);
    sum += (x5 * y1 - x1 * y5);

    int area = abs(sum) / 2;

    cout << "������� ������������� �����: " << area << endl;

    return 0;
}

