// Prompt the user for a number and display its multiplication table up to 10.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    for (int i = 1; i < 11; i++)
    {
        cout << n << " x " << i << " = " << (n * i) << endl;
    }
    return 0;
}
