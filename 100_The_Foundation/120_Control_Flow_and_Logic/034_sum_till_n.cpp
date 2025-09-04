// Calculate the sum of all natural numbers from 1 to a user-specified N.

#include <iostream>
using namespace std;

long int sum(const int n)
{
    return (n*(n+1))/2;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    const long int answer = sum(n);
    cout << "answer: " << answer;
    return 0;
}
