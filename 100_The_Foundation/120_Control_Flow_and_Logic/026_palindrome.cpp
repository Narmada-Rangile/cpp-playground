// Check if a number is a palindrome (reads the same forwards and backward).

#include <iostream>
#include <cmath>
using namespace std;

bool is_palindrome(int);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    const bool ans = is_palindrome(n);
    ans ? cout << "The number is palindrome": cout << "The number is not palindrome";

    return 0;
}

bool is_palindrome(int num)
{
    const int original_num = num;
    int reversed_num = 0;

    while (num > 0)
    {
        const int digit = num % 10;
        reversed_num = (reversed_num*10) + digit;
        num = floor(num/10);
    }

    return original_num == reversed_num;
}
