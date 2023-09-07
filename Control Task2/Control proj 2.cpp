#include <iostream>
#include <cmath>

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i < int(sqrt(x)) + 1; i++) {
        if (x % i == 0) {
            return false;
        }
        return true;
    }
}
bool is_super_prime(int n) {
    if (!is_prime(n)) {
        return false;
    }

    int count = 0;
    for (int x = 2; x < n; x++) {
        if (is_prime(x)) {
            count++;
        }
    }
    return is_prime(count);
}


int main()
{
    int number;
    std::cout <<"input number" << std::endl;
    std::cin >> number;
    bool result = is_super_prime(number);
    std::cout <<"\n" << number << (result ? " is Super-prime" : " is NOT Super-prime") << std::endl;
    return 0;
}
