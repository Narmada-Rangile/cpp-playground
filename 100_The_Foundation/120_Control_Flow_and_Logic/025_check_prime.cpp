// Determine if a given positive integer is a prime number.

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int);

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    const bool ans = is_prime(num);
    ans ? cout << "the number is prime" : cout << "the number is not prime";

    return 0;
}

bool is_prime(const int n)
{
    if (n <= 1) return false;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}
