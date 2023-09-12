#include <iostream>
#include <vector>
#include <algorithm>

int min_coins(std::vector<int> coins, int target, std::vector<int>& res)
{
    int count = 0;
    res.clear();
    std::sort(coins.begin(), coins.end());

    for (auto coin = coins.rbegin(); coin != coins.rend()&& target > 0; ++coin)
    {
        if (target >= (*coin))
        {
            count += target / (*coin);
            target = target % (*coin);      
            res.push_back(*coin);
        }
    }

    return count;
}
int main()
{
    setlocale(LC_ALL, "ru");
    int t;
    std::vector<int> coins{ 1, 2, 5, 10 };
    std::cout << "������� ���.  ����� ���������� ������ ?" << std::endl;
    std::cin >> t;
    std::vector<int> res;

    int count = min_coins(coins, t, res);

    std::cout << "����������� ���������� �����: " << count << std::endl;
    std::cout << "�������������� ������: ";
    for (int coin : res) {
        std::cout << coin << " ";
    }
    std::cout << std::endl;
    return 0;

}
