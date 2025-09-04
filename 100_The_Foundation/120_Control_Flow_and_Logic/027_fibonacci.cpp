// Generate the Fibonacci sequence up to a specified number of terms.

#include <iostream>
using namespace std;

void fib(int);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    fib(n);

    return 0;
}

void fib(const int n)
{
    int t1 = 0, t2 = 1;
    cout << t1 << " " << t2 << " ";

    for (int i = 3; i <= n; i++)
    {
        const int next_term = t1 + t2;
        cout << next_term << " ";
        t1 = t2;
        t2 = next_term;
    }
}
