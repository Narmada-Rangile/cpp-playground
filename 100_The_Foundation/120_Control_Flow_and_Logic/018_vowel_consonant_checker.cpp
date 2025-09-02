// Read a character and determine if it is a vowel or a consonant.

#include <iostream>
using namespace std;

int main()
{
    const char ch = getchar();

    if (int num_ch = static_cast<int>(ch);
        num_ch == 65 ||
        num_ch == 69 ||
        num_ch == 73 ||
        num_ch == 79 ||
        num_ch == 85 ||
        num_ch == 97 ||
        num_ch == 101 ||
        num_ch == 105 ||
        num_ch == 111 ||
        num_ch == 117)
    {
        cout << "vowel" << endl;
    } else cout << "consonant" << endl;
    return 0;
}
