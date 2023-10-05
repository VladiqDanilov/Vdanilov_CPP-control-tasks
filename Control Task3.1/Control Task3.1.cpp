#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


bool num_processing(const std::string& input_str) {
    int conseс_cnt = 1;

    for (int i = 1; i < input_str.length(); ++i) {
        char current_char = input_str[i];
        char prev_char = input_str[i - 1];

        if (!(isdigit(current_char) || current_char == ' ' || current_char == '-')) {
            return false;
        }

        if (current_char == prev_char) {
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
    string ch;
    bool validn = false;

    cout << "¬ведите номер и серию —Ќ»Ћ—а длиной 11 символов: " << endl;

    getline(cin, inpt1);

    if (inpt1.find(' ') != std::string::npos) {
        auto noSpaceEnd = std::remove(inpt1.begin(), inpt1.end(), ' ');
        inpt1.erase(noSpaceEnd, inpt1.end());
    }
    if (inpt1.find('-') != std::string::npos) {
        inpt1.erase(std::remove(inpt1.begin(), inpt1.end(), '-'), inpt1.end());
    }
//    cout << '\n' << inpt1 << endl;
    string a{ inpt1.end() - 2, inpt1.end() };
    string str_n = inpt1.substr(0, size(inpt1) - 2);

    string s = a;
    int n = stoi(str_n);
    if (str_n.length() == 9 && num_processing(str_n)) {
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
        cout << "\n" << " такого снилса не существует";
        exit;
    }
    if (ch == s) {
        validn = true;
    }
    cout << "\n" << "result: " << endl;
    cout << "\n" << std::boolalpha << validn << std::endl;
}

