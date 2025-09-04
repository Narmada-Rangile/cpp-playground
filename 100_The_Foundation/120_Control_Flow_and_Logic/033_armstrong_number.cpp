// Check if a number is an Armstrong number (a number that is equal to the sum of its own digits each raised to the power of the number of digits).

#include <iostream>
#include <cmath>
using namespace std;


int count_digits(int num)
{
    if (num == 0) return 1;
    int count = 0;
    num = fabs(num);

    while (num > 0)
    {
        num = floor(num/10);
        count++;
    }

    return count;
}

bool is_armstrong(int num)
{
    const int original_num = num;
    const int num_of_digits = count_digits(num);
    int sum = 0;

    while (num > 0)
    {
        const int digit = num % 10;
        sum += pow(digit, num_of_digits);
        num = floor(num/10);
    }

    return sum == original_num;
}

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;

    const bool answer = is_armstrong(number);
    answer ? cout << "Number is armstrong" : cout << "Not an armstrong number";

    return 0;
}
