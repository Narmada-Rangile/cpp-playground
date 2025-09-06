// Implement a function to check if a given string is a palindrome.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// function to make a character lower case
char to_lower(const char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

bool is_palindrome_no_alphanumeric (const string& str)
{
    // if user enters anything other than alphanumeric characters. We will discard them.
    string clean_str;

    for (const char& c : str)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            clean_str += to_lower(c);
        }
    }

    string reversed = clean_str;
    reverse(reversed.begin(), reversed.end());

    return clean_str == reversed;
}

// also considers alphanumeric characters while checking.
bool is_palindrome (const string& str)
{
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Input string: " << str << endl;

    if (is_palindrome_no_alphanumeric(str))
    {
        cout << "The string is a palindrome (ignoring case and non-letters)" << endl;
    } else
    {
        cout << "The string is not a palindrome. (ignored case and non-letters)" << endl;
    }

    if (is_palindrome(str))
    {
        cout << "This string is a palindrome. (considering case and non-letters)" << endl;
    } else
    {
        cout << "The string is not a palindrome. (considering case and non-letters)" << endl;
    }

    return 0;
}
