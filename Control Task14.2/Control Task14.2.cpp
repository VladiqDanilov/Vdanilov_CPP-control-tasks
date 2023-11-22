#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename T>
void Print(const T& container, const std::string& separator) {

    bool first = true;
    for (const auto& element : container) {

        if (!first) {
            std::cout << separator;
        }
        else {
            first = false;
        }
        std::cout << element;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    Print(vec, ", ");

    std::list<std::string> strList = { "one", "two", "three", "four" };
    Print(strList, " \t ");
}
