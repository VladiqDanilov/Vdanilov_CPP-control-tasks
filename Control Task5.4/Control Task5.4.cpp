#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 4) {
        cerr  << argv[0] << " ONLY: -a/-m operand1 operand2" << endl;
        return 1;
    }

    const char* flag = argv[1];
    int operand1, operand2;

    if (strncmp(flag, "-a", 2) != 0 && strncmp(flag, "-m", 2) != 0) {
        cerr << "Invalid flag. Use -a for addition or -m for multiplication." << endl;
        return 1;
    }

    try {
        operand1 = stoi(argv[2]);
        operand2 = stoi(argv[3]);
    }
    catch (const invalid_argument& e) {
        cerr << "One or both operands are not integers." << endl;
        return 1;
    }

    if (strncmp(flag, "-a", 2) == 0) {
        int sum = operand1 + operand2;
        cout << "Sum: " << sum << endl;
    }
    else if (strncmp(flag, "-m", 2) == 0) {
        int product = operand1 * operand2;
        cout << "Product: " << product << endl;
    }
}

