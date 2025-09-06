// Write a function that takes a C-style string (character array) and converts all lowercase letters to uppercase.

#include <iostream>
#include <string>
using namespace std;

void string_to_uppercase (string& str)
{
    for (char& c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            c -= 32; // using ASCII to convert to uppercase.
        }
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Original string: " << str << endl;

    string_to_uppercase(str);

    cout << "Uppercase string: " << str << endl;

    return 0;
}
