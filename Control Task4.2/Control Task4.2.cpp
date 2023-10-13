#include <iostream>

using namespace std;

//  принимаем аргументы по ссылке 
bool Input(int& a, int& b) {
    std::cout << "¬ведите значение a: ";
    if (!(std::cin >> a)) {
        std::cerr << "ќшибка ввода дл¤ 'a'\n";
        return false;
    }

    std::cout << "¬ведите значение b: ";
    if (!(std::cin >> b)) {
        std::cerr << "ќшибка ввода дл¤ 'b'\n";
        return false;
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int a, b;
    if (!Input(a, b)) {
        cerr << "error";
        return 1;
    }

    int s = a + b;
    std::cout << "—умма a и b: " << s << std::endl;
    return 0;
}

