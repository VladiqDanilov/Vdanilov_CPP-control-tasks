#include <iostream>
#include <string>

using namespace std;

string to_binary(int num) {
    string binr;
	string dig;
	while (num>0)
	{
		dig = to_string(num % 2);
		binr.insert(0, dig);
		num = num / 2;
	}
	return binr;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите n (n > 0):"<< "\n" <<endl;
	cin >> n;
	if (n > 0) 
	{
		string res = to_binary(n);
		cout << '\n'<< "Число n в двоичной: " << res << endl;
	}
	else
	{
		cout << '\n' << "Пожалуйста, введите положительное значение n." << endl;
	}
}
