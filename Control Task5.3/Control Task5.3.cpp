#include <iostream>

using namespace std;
int searchWithTransposition(int arr[], int size, int dgt1) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == dgt1) {
            if (i != 0) {
                // ќбмен местами найденного элемента с предыдущим
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
            return i; // ¬озвращаем индекс найденного элемента
        }
    }
    return -1; // ≈сли элемент не найден
}

int main()
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 3, 1, 4, 4, 5, 4, 2, 6, 5, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

//    cout << '\n' << size << endl;

    int dgt1 = 4;
    int index = searchWithTransposition(arr, size, dgt1);

    if (index != -1) {
        cout << "Ёлемент " << dgt1 << " найден в индексе " << index << endl;
    }
    else {
        cout << "Ёлемент " << dgt1 << " не найден." << endl;
    }

    int dgt2 = 4;
    int ind2 = searchWithTransposition(arr, size, dgt2);

    if (ind2 != -1) {
        cout << "Ёлемент " << dgt2 << " найден в индексе " << ind2 << endl;
    }
    else {
        cout << "Ёлемент " << dgt2 << " не найден." << endl;
    }
}