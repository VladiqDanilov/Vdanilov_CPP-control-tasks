#include <iostream>
using namespace std;

template <typename T>
T avgMean(const T arr[], int n) {
    T s=0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s / n;
}

int main()
{
    int intArr[] = { 1, 2, 3, 4, 5 };
    long longArr[] = { 65536, 65538, 65500, 70000, 95000 };
    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    char charArr[] = { 1, 2, 2, 4, 4, 8, 8, 9, 9, 9, 7, 11, 13, 14, 15 };

    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    double doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    long longSize = sizeof(longArr) / sizeof(longArr[0]);
    int charSize = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << "Avg for intArr: " << avgMean(intArr, intSize) << std::endl;
    std::cout << "Avg for LongArr: " << avgMean(longArr, longSize) << std::endl;
    std::cout << "Avg for doubleArr: " << avgMean(doubleArr, doubleSize) << std::endl;
    std::cout << "Avg for charArr: " << avgMean(charArr, charSize) << std::endl;
}
