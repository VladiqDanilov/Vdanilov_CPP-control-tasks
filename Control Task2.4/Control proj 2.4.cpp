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

//    cout << centrX << " � " << centrY << endl;

    while (score < req_score)
    {
        int x;
        int y;
        cout << "\n" << "������� ���������� �������� �� X" << endl;
        cin >> x;
        cout << "\n" << "������� ���������� �������� �� Y" << endl;
        cin >> y;

        cnt++;

        double dist = sqrt(pow((centrX - x), 2) + pow((centrY - y), 2));
        if (dist <= 1) {
            score += 10;
            cout << "\n" << "���������! : +10. score: " << score << endl;
        }
        else if(dist <= 2){
            score += 5;
            cout << "\n" << "���������! : +5 � score: " << score << endl;
        }
        else if (dist <= 3) {
            score += 1;
            cout << "\n" << "���������! : +1 � score: " << score << endl;
        }
        else {
            cout << "\n" << "�� ������" << endl;
        }

    }
    cout << "\n" << "����������� �����:" << score << endl;

    if (cnt <= 7) {
        cout << "\n" << "���� �������: �������" << endl;
    }
    else if(cnt>7 &&cnt<12)
    {
        cout << "\n" << "���� �������: ������ �������" << endl;
    }
    else
    {
        cout << "\n" << "���� �������: �������" << endl;
    }

    cout << "����� ��� � �����: " << centrX << " ; " << centrY << endl;


}