#include <iostream>

using namespace std;

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
    int getHours() const{
        return hours;
    }
    int getMinutes() const {
        return minutes;
    }
    int getSeconds() const {
        return seconds;
    }
    void consoleTime() const {
        cout << "\n" << hours <<":"<< minutes << ":" << seconds <<endl;
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
    Time t1 = { 12, 53, 20 };


    std::cout << "Current time1: ";
    t1.consoleTime();

    Time sum;

    Time t2 = { 8, 24, 7 };
    std::cout << "Current time2: ";
    t2.consoleTime();

    sum = t1 + t2;
    sum.consoleTime();
}

