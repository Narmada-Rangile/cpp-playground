// Count the total number of digits in a given integer.

#include <algorithm>
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

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    const int answer = count_digits(num);
    cout << "Number of digits: " << answer << endl;
    return 0;
}
