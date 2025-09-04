// Calculate the factorial of a non-negative integer entered by the user.

#include <iostream>
using namespace std;

double factorial (int);

int main()
{
    int n;
    cout << "Enter number to calc factorial: ";
    cin >> n;

    const double result = factorial(n);
    cout << "answer: " << result;
    return 0;
}

double factorial(const int n)
{
    if (n<=1) return 1;
    double result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
