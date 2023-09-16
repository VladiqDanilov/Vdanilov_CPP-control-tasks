#include <iostream>
#include <random>
#include <math.h>

using namespace std;

int main()
{
    int c;
    setlocale(LC_ALL, "ru");
    random_device Rand;
    std::mt19937 gen(Rand());
    uniform_int_distribution<int> dist(0, 10);
    int centrX= dist(gen);
    int centrY= dist(gen);
    int score = 0;
    int req_score = 50;
    int cnt=0;

//    cout << centrX << " и " << centrY << endl;

    while (score < req_score)
    {
        int x;
        int y;
        cout << "\n" << "введите координату выстрела по X" << endl;
        cin >> x;
        cout << "\n" << "введите координату выстрела по Y" << endl;
        cin >> y;

        cnt++;

        double dist = sqrt(pow((centrX - x), 2) + pow((centrY - y), 2));
        if (dist <= 1) {
            score += 10;
            cout << "\n" << "Попадание! : +10. score: " << score << endl;
        }
        else if(dist <= 2){
            score += 5;
            cout << "\n" << "Попадание! : +5 к score: " << score << endl;
        }
        else if (dist <= 3) {
            score += 1;
            cout << "\n" << "Попадание! : +1 к score: " << score << endl;
        }
        else {
            cout << "\n" << "Не попали" << endl;
        }

    }
    cout << "\n" << "Колличество очков:" << score << endl;

    if (cnt <= 7) {
        cout << "\n" << "Твой уровень: Снайпер" << endl;
    }
    else if(cnt>7 &&cnt<12)
    {
        cout << "\n" << "Твой уровень: просто стрелок" << endl;
    }
    else
    {
        cout << "\n" << "Твой уровень: новичок" << endl;
    }

    cout << "Центр был в точке: " << centrX << " ; " << centrY << endl;


}