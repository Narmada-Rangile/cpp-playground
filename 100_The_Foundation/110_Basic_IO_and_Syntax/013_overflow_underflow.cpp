#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int num = INT_MAX;
    cout << "Initial value of num: " << num << endl;
    num++;
    cout << "Value of num after overflow: " << num << endl;
    num = INT_MIN;
    cout << "Initial value of num: " << num << endl;
    num--;
    cout << "Value of num after underflow: " << num << endl;
    return 0;
}
