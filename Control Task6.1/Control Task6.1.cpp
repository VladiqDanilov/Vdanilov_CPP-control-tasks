#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    string poemLine;
    ofstream outputFile("poem.txt");

    if (outputFile.is_open()) {
        cout << "Введите стихотворение. Для завершения введите пустую строку:\n";

        while (true) {
            getline(cin, poemLine);

            if (poemLine.empty()) {
                break; // Если строка пуста, завершаем ввод.
            }

            outputFile << poemLine << '\n';
        }

        outputFile.close();
        cout << "Строки успешно записаны в файл poem.txt." << endl;
    }
    else {
        cerr << "Ошибка открытия файла." << endl;
    }

}
