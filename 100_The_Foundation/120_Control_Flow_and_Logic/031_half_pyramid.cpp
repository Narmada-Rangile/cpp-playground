// Use nested loops to print a pattern of stars in the shape of a right-angled triangle.

#include <iostream>
using namespace std;

int main()
{
    short int rows;
    cout << "Enter num of rows: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
