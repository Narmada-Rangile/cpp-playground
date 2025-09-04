// Use nested loops to print a pattern of stars in the shape of a full pyramid.

#include <iostream>
using namespace std;

int main()
{
    short int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <=rows - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k < 2*i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
