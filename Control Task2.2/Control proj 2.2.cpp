// Control proj 2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool has_no_more_than_2_consec_chars(const std::string& input_str) {
    int conseс_cnt = 1;

    for (int i = 1; i < input_str.length(); ++i) {
        if (input_str[i] == input_str[i - 1]) {
            conseс_cnt++;
            if (conseс_cnt > 2) {
                return false;
            }
        }
        else {
            conseс_cnt = 1;
        }
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    string inpt1;
    //int s;
    string ch;
    bool validn = false;

    cout << " введите номер и серию снисл длинной 11 символов"<<endl;
    cin >> inpt1;
    cout << "\n";
    string s = inpt1.substr(9, 11);
    string str_n = inpt1.substr(0, 9);
    bool no_more_than_2_consec_ch = has_no_more_than_2_consec_chars(str_n);
    int n = stoi(str_n);


    if (str_n.length()==9 && no_more_than_2_consec_ch) {
        int sum = 0;
        int pos = 1;
        while (n > 0)
        {
            int dig = n % 10;
            sum += dig * pos;
            pos++;
            n /= 10;
        }
        if (sum < 100) {
            ch = to_string(sum);
        }
        if (sum == 100 || sum == 101) {
            ch = '00';
        }
        if (sum > 101) {
            int ost = sum % 101;
            if (ost < 100) {
                ch = to_string(ost);
            }
            if (ost == 100) {
                ch = '00';
            }
        }
    }
    else {
        cout << " такого снилса не существует";
        exit;
    }
    if (ch == s) {
        validn = true;
    }
    cout << "\n" << "result: " << endl;
    cout << "\n" << std::boolalpha << validn << std::endl;
}

