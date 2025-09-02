// Read three distinct numbers and use nested if-else statements to find the largest one.

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter three numbers seperated by space: " << endl;
    cin >> a >> b >> c;

    if (a > b)
    {
        if (c > a)
        {
            cout << "c is largest" << endl;
        } else
        {
            cout << "a is largest" << endl;
        }
    } else if (c > b)
    {
        cout << "c is largest" << endl;
    } else
    {
        cout << "b is largest" << endl;
    }
    return 0;
}
