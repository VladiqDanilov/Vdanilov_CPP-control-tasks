#include <iostream>
#include <stdexcept>

using namespace std;

class TimeError : public std::exception
{
public:
    TimeError(const string& message) : message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;
};

class TimeValueError : public std::runtime_error
{
public:
    TimeValueError(const char* message) : std::runtime_error(message) {}
};

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    //нормализация времени
    void normalize() {
        int totalSeconds = getTotalSeconds();

        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
    }

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

    friend Time operator+(double num, const Time& timeObj);

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
        cout << "\n\n" << endl;
    }
    //новый метод
    int getTotalSeconds() const
    {
        return hours * 3600 + minutes * 60 + seconds;
    }
    // Перегруженный оператор сравнения
    bool operator<(const Time& other) const {
        return getTotalSeconds() < other.getTotalSeconds();
    }
    void setTimeFromSeconds(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        normalize();
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
    Time operator+(double secondsToAdd) const {
        Time result = *this;
        result.seconds += secondsToAdd;
        result.normalize();
        return result;
    }


    Time operator-(const Time& other) const {
        Time result;

        int thisSeconds = getTotalSeconds();
        int otherSeconds = other.getTotalSeconds();

        if (thisSeconds < otherSeconds) {
            throw TimeValueError("Невозможно вычесть большее время из меньшего.");
        }

        int diffSeconds = thisSeconds - otherSeconds;

        result.hours = diffSeconds / 3600;
        result.minutes = (diffSeconds % 3600) / 60;
        result.seconds = diffSeconds % 60;

        result.normalize();

        return result;
    }
};
Time operator+(double num, const Time& curr) {
    Time result = curr;
    int totalSec = result.getTotalSeconds();
    totalSec += static_cast<int>(num);
    result.setTimeFromSeconds(totalSec);
    return result;
}



int main()
{
    setlocale(LC_ALL, "ru");
    try {
        Time t1 = { 2, 7, 11 };


        cout << "Current time1: ";
        t1.consoleTime();

        Time sum;

        Time t2 = { 3, 55, 36 };
        cout << "Current time2: ";
        t2.consoleTime();

        cout << "Summ time 1 time2: ";
        sum = t1 + t2;
        sum.consoleTime();

        cout << "Delta time 1 time2: ";
        Time razn = t1 - t2;
        razn.consoleTime();

        cout << "Time plus double ";
        Time FL = t1 + 7200;
        FL.consoleTime();

        cout << "double plus Time ";
        Time AdditionToFL = 5564.055 + t2;
        AdditionToFL.consoleTime();

        cout << "\n\n" << endl;
        if (t1 < t2) {
            cout << "T1 меньше T2" << endl;
        }
        else {
            cout << "T1 - больше или равно T2" << endl;
        }
    }
    catch(const TimeError& error){
        cerr << "Ошибка: " << error.what() << std::endl;
    }
    catch (const TimeValueError& error) {
        cerr << "Невозможно вычесть большее время из меньшего" << endl;
    }
    

}

