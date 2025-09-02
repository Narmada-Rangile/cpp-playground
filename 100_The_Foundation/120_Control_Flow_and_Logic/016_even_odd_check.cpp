// **Even/Odd Checker** - Determine if number is even or odd

#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;
    if (input % 2 == 0)
    {
        cout << "Number is even" << endl;
    } else
    {
        cout << "Number is odd" << endl;
    }
    return 0;
}
