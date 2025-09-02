// Prompt for a username and password and compare them against hardcoded, correct values.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username, password;
    cout << "Enter Username: " << endl;
    cin >> username;

    cout << "Enter password: " << endl;
    cin >> password;

    if (username.compare("dilicalflame") == 0 && password.compare("streaming") == 0)
    {
        cout << "credentials correct, logged in." << endl;
    } else
    {
        cout << "can't login, invalid credentials." << endl;
    }
    return 0;
}
