// Demonstrate what happens when you add 1 to the maximum integer value
// and subtract 1 from the minimum integer value.

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    constexpr int int_max = INT_MAX;
    constexpr int int_min = INT_MIN;

    cout << "Max Integer: " << int_max << endl;
    cout << "Max Integer + 1: " << int_max + 1 << endl;
    cout << "Min Integer" << int_min << endl;
    cout << "Min Integer - 1: " << int_min - 1 << endl;

    return 0;

}
