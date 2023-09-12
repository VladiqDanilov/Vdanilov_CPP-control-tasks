// Control proj 2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    int s;
    int ch=0;
    bool validn = false;

    cout << " введите номер СНИЛС содержащий 9 символов"<<endl;
    cin >> n;
    cout << "\n" << " введите Контрольное Число" << endl;
    cin >> s;
    cout << "\n";

    if (n >= 100000000 && n <= 999999999) {
        int sum = 0;
        int pos = 9;
        while (n>0)
        {
            int dig = n % 10;
            sum += dig * pos;
            pos--;
            n /= 10;
        }
        if (sum < 100) {
            ch = sum;
        }
        if (sum == 100 || sum == 101) {
            ch = 00;
        }
        if (sum > 101) {
            int ost = sum % 101;
            if (ost < 100) {
                ch = ost;
            }
            if (ost == 100) {
                ch = 00;
            }
        }
    }
    else {
        cout << " номер СНИЛС должнен быть 9-значным.";
        exit;
    }
    if (ch == s) {
        validn = true;
    }
    cout << "result: " << endl;
    cout << "\n" << std::boolalpha << validn << std::endl;
}

