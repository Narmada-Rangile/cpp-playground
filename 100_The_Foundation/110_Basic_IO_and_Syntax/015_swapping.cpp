// **Swap Numbers** - Swap two variables using temp variable

#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    int b = 2;
    cout << "Value before swapping -> a: " << a << endl;
    cout << "Value before swapping -> b: " << b << endl;

    const int temp = a;
    a = b;
    b = temp;

    cout << "Value after swapping -> a: " << a << endl;
    cout << "Value after swapping -> b: " << b << endl;
}
