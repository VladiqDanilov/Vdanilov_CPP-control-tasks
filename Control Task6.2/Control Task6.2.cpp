#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0;
    int buf = 0;

    // Создаем файл для записи
    ofstream outputFile("arrays6.txt");

    if (outputFile.is_open())
    {
        outputFile << "Исходный массив: ";
        for (int i = 0; i < N; i++)
        {
            outputFile << a[i] << ' ';
        }
        outputFile << '\n';

        for (int i = 0; i < N; i++)
        {
            min = i;
            for (int j = i + 1; j < N; j++)
                min = (a[j] < a[min]) ? j : min;
            if (i != min)
            {
                buf = a[i];
                a[i] = a[min];
                a[min] = buf;
            }
        }

        // Записываем отсортированный массив
        outputFile << "Отсортированный массив: ";
        for (int i : a)
        {
            outputFile << i << ' ';
        }
        outputFile.close();

        cout << "Массив отсортирован и успешно записаны в файл output.txt." << endl;
    }
    else
    {
        cerr << "Ошибка открытия файла." << endl;
    }
}
