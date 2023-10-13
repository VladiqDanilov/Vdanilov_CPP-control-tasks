#include <iostream>

using namespace std;

void fillVL(int mas[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
}

int sumEL(int mas[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
    }
    return s;
}

int avgEL(int mas[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
    }
    return s / n;
}

int sumOTR(int mas[], int n) {
    int otr = 0;
    for (int j = 0; j < n; j++) {
        if (mas[j] < 0) {
            otr += mas[j];
        }
    }
    return otr;
}

int sumPOLSH(int mas[], int n) {
    int pls = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0) {
            pls += mas[i];
        }
    }
    return pls;
}

int sumEven(int mas[], int n) {
    int su_chet = 0;
    for (int i = 0; i < n; i = i + 2) {
        su_chet += mas[i];
    }
    return su_chet;
}

int sumUnev(int mas[], int n) {
    int su_nech = 0;
    for (int i = 1; i < n; i = i + 2) {
        su_nech += mas[i];
    }
    return su_nech;
}

void sortArr(int mas[], int n) {
    int min = 0;
    int buf = 0;

    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            min = (mas[j] < mas[min]) ? j : min;
        if (i != min) {
            buf = mas[i];
            mas[i] = mas[min];
            mas[min] = buf;
        }
    }

//    for (int i = 0; i < n; i++)
//        cout << mas[i] << '\t';
}

int main()
{
    setlocale(LC_ALL, "ru");
    int mas[n];
    cout << "введите 10 элементов массива"<<endl;
    fillVL(mas, n);
    cout << '\n' << "характеристики массива:" << endl;
    cout << '\n' << endl;
    cout << '\n' << "сумма элементов: " << sumEL(mas, n) <<endl;
    cout << '\n' << "срзнач элементов: " << avgEL(mas, n) << endl;
    cout << '\n' << "сумма положительных элементов: " << sumPOLSH(mas, n) << endl;
    cout << '\n' << "сумма потрицательных элементов: " << sumOTR(mas, n) << endl;
    cout << '\n' << "сумма четных элементов: " << sumEven(mas, n) << endl;
    cout << '\n' << "сумма нечетных элементов: " << sumUnev(mas, n) << endl;

    cout << '\n' << '\n' << "массив до сортировки "<< endl;
    for (int cnt = 0; cnt < n; cnt++)
        cout << mas[cnt] << '\t';


    sortArr(mas, n);



    cout << "\n" << "полученный массив" << endl;
    for (int cnt = 0; cnt < n; cnt++)
        cout << mas[cnt] << '\t';
}