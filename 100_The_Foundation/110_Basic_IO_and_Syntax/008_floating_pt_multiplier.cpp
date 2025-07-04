// Prompt the user for two floating point numbers and calculate their product

#include <iostream>
using namespace std;

int main()
{
    float num1, num2;
    cout << "Enter two floating point numbers: ";
    cin >> num1 >> num2;
    const float product = num1 * num2;

    cout << product << endl;

    return 0;
}
