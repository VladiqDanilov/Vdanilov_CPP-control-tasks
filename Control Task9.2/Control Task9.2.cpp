#include <iostream>
#include <stdexcept>

using namespace std;

class TimeError : public std::exception
{
public:
    TimeError(const std::string& message) : message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;
};


class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0)
    {
    }

    Time(int h, int m, int s)
    {
        if (h < 0 || m < 0 || s < 0 || m >= 60 || s >= 60)
        {
            throw TimeError("Неправильные значения времени");
        }
        int extraMinutes = 0;
        int extraHours = 0;

        if (s >= 60)
        {
            extraMinutes = s / 60;
            s %= 60;
        }

        if (m >= 60)
        {
            extraHours = m / 60;
            m %= 60;
        }

        hours = h + extraHours;
        minutes = m + extraMinutes;
        seconds = s;
    }
    int getHours() const {
        return hours;
    }
    int getMinutes() const {
        return minutes;
    }
    int getSeconds() const {
        return seconds;
    }
    void consoleTime() const {
        cout << "\n" << hours << ":" << minutes << ":" << seconds << endl;
    }

    Time operator+(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes;
        result.hours = hours + other.hours;

        if (result.seconds >= 60) {
            result.seconds -= 60;
            result.minutes += 1;
        }

        if (result.minutes >= 60) {
            result.minutes -= 60;
            result.hours += 1;
        }

        return result;
    }

};


int main()
{
    setlocale(LC_ALL, "ru");
    try {
        Time t1 = { 12, 53, 20 };


        cout << "Current time1: ";
        t1.consoleTime();

        Time sum;

        Time t2 = { 8, 24, 7 };
        cout << "Current time2: ";
        t2.consoleTime();

        sum = t1 + t2;
        sum.consoleTime();

        cout << "\n\n" << endl;

        Time t3 = { -1, 0, 0 };
    }
    catch(const TimeError& error){
        cerr << "Ошибка: " << error.what() << std::endl;
    }
    

}

