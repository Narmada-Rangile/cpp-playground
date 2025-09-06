// Encapsulate the prime-checking logic from a previous project into a boolean function.

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(const int number)
{
    // because 0 and 1 are not prime numbers.
    if (number <= 1) return false;
    // loop to find any divisor
    for (int i = 2; i < sqrt(number); ++i)
    {
        if (number % i == 0) return false; // divisor found
    }
    return true; // no divisor found, its a prime.
}

int main()
{
    int number;
    cout << "Enter a number: " ;
    cin >> number;

    is_prime(number) ? cout << number << " is a prime number" : cout << number << " is not a prime number.";
    return 0;
}
