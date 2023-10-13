#include <iostream>

using namespace std;

int* max_vect(int size, const int a[], const int b[]) {
    int* result = new int[size]; //присваивает указателю result адрес начала выделенной памяти для массива
    for (int i = 0; i < size; i++) {
        result[i] = (a[i] > b[i]) ? a[i] : b[i];
    }
    return result;
}
int main()
{
    int a[] = { 1,2,3,4,5,6,7,2 };
    int b[] = { 7,6,5,4,3,2,1,3 };
    int kc = sizeof(a) / sizeof(a[0]);
    int* c;
    c = max_vect(kc, a, b);
    for (int i = 0; i < kc; i++)
        //Вывод результата.
        cout << c[i] << " ";
    cout << endl;
    delete[]c;
}
