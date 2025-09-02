// Determine if a user-inputted year is a leap year.

#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter an year: " << endl;
    cin >> year;

    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        cout << "It is leap year" << endl;
    } else cout << "Not a leap year" << endl;
    return 0;
}
