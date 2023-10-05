#include <iostream>
using namespace std;

int sumLines(int n){
    if (n == 0) {
        return 0;
    }
    else
    {
        return 5*n +sumLines(n-1);
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    int num;
    cout << "ведите n (n > 0):"<< endl;
    cin >> num;

    if (num > 0) {
        int res = sumLines(num);
        cout << "\n" << res << endl;
    }
    else
    {
        cout << "\n" << "введите положительное значение n." << endl;
    }
}

