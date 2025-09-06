// Write a function to count the number of words in a given C-style string.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// using stringstream to count words in a string
int count_words (const string& str)
{
    stringstream ss(str);
    string word;
    int count (0);

    while (ss >> word)
    {
        count++;
    }
    return count;
}

void display_words (const string& str)
{
    stringstream ss(str);
    string word;

    int word_num = 1;
    while (ss >> word)
    {
        cout << word_num++ << ": " << word << endl;
    }
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Input string: '" << str << "'" << endl;

    const int word_count = count_words(str);
    cout << "Number of words: " << word_count << endl;

    if (word_count > 0)
    {
        display_words(str);
    }

    return 0;
}
