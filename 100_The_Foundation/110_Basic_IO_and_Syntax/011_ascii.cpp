// Read a single character from the user and print its corresponding ASCII value

#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;
    cout << "The ASCII value of '" << c << "' is " << static_cast<int>(c) << endl;
    return 0;
}
