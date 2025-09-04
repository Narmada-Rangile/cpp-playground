// Use the sizeof operator to print the size in bytes of
// char, short, int, long, long long, float, double, and bool.

#include <iostream>
using namespace std;

int main()
{
    constexpr int char_size = sizeof(char);
    constexpr int short_size = sizeof(short);
    constexpr int int_size = sizeof(int);
    constexpr int long_size = sizeof(long);
    constexpr int long_long_size = sizeof(long long);
    constexpr int float_size = sizeof(float);
    constexpr int double_size = sizeof(double);
    constexpr int bool_size = sizeof(bool);

    cout << "size of char: " << char_size << endl;
    cout << "size of short: " << short_size << endl;
    cout << "size of int: " << int_size << endl;
    cout << "size of long: " << long_size << endl;
    cout << "size of long long: " << long_long_size << endl;
    cout << "size of float: " << float_size << endl;
    cout << "size of double: " << double_size << endl;
    cout << "size of bool: " << bool_size << endl;

    return 0;
}
