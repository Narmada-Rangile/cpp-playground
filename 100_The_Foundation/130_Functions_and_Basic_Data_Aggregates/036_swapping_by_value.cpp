// Create a function that attempts to swap two numbers passed by value to demonstrate scope.

#include <iostream>
using namespace std;

void swap (int a, int b)
{
    // using XOR swap algorithm
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "INSIDE SWAP FUNCTION => a: " << a << ", b: " << b << endl;
}

int main()
{
    constexpr int a(7);
    constexpr int b(42);

    swap(a, b);
    cout << "INSIDE MAIN FUNCTION: => a: " << a << ", b: " << b << endl;

    return 0;
}
