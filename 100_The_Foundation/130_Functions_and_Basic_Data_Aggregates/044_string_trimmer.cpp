// Create a function that accepts a string and an integer N, returning a version of the string truncated to N characters.

#include <iostream>
#include <string>
using namespace std;

void trim_string(string& str, const int n)
{
    if (n >= 0 && n < static_cast<int>(str.length()))
    {
        str = str.substr(0, n);
    }
}

int main()
{
    string str;
    int n;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter number of characters to keep: ";
    cin >> n;

    cout << "Original string: '" << str << "'" << endl;
    cout << "Original length: " << str.length() << endl;

    if (n < 0)
    {
        cout << "Invalid input! Number of characters cannot be negative." << endl;
        return 1;
    }

    trim_string(str, n);

    cout << "Trimmed string: '" << str << "'" << endl;
    cout << "New Length: " << str.length() << endl;

    return 0;
}
