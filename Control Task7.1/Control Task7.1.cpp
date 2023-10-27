#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time addTime(const Time& other) const {
        Time result;
        result.hours = hours + other.hours;
        result.minutes = minutes + other.minutes;
        result.seconds = seconds + other.seconds;

        if (result.seconds >= 60) {
            result.minutes += result.seconds / 60;
            result.seconds %= 60;
        }
        if (result.minutes >= 60) {
            result.hours += result.minutes / 60;
            result.minutes %= 60;
        }

        return result;
    }


    // вычит интервалов времени
    Time subtractTime(const Time& other) const {
        Time result;
        result.hours = hours - other.hours;
        result.minutes = minutes - other.minutes;
        result.seconds = seconds - other.seconds;

        if (result.seconds < 0) {
            result.seconds += 60;
            result.minutes--;
        }
        if (result.minutes < 0) {
            result.minutes += 60;
            result.hours--;
        }

        if (result.hours < 0) {
            // считываем допустимые значени¤ времени
            result.hours += 24;
        }

        return result;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Time currentTime1;
    cout << "введите часы: ";
    cin >> currentTime1.hours;
    cout << "введите минуты: ";
    cin >> currentTime1.minutes;
    cout << "введите секунды: ";
    cin >> currentTime1.seconds;

    cout << "время: " << currentTime1.hours << " часов, " << currentTime1.minutes << " минут, "
        << currentTime1.seconds << " секунд." << endl;

    cout << "\n" << "\n" << endl;

    Time currentTime2;
    cout << "введите часы: ";
    cin >> currentTime2.hours;
    cout << "введите минуты: ";
    cin >> currentTime2.minutes;
    cout << "введите секунды: ";
    cin >> currentTime2.seconds;
    cout << "время: " << currentTime2.hours << " часов, " << currentTime2.minutes << " минут, "
        << currentTime2.seconds << " секунд." << endl;

    Time sum = currentTime1.addTime(currentTime2);
    Time difference = currentTime1.subtractTime(currentTime2);

    cout << "\n" << "\n" << endl;
    cout << "сумма времени: " << sum.hours << " часов, " << sum.minutes << " минут, " << sum.seconds << " секунд." << std::endl;
    cout << "разница времени: " << difference.hours << " часов, " << difference.minutes << " минут, " << difference.seconds << " секунд." << std::endl;
}

