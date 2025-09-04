// Ask the user for a number N and use a for loop to print all integers from 1 to N.

#include <iostream>
using namespace std;

void print_numbers(int);

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    print_numbers(n);
    return 0;
}

void print_numbers(const int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << i << endl;
    }
}
