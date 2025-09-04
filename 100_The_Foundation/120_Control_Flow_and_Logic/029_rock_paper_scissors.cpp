// Implement the classic game where the user plays against the computer's random choice.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rps(const short unsigned int&);

int main()
{
    short unsigned int user_choice;
    cout << "0: ROCK;\n1: PAPER;\n2: SCISSOR:\n" << endl << "Enter your choice: ";
    cin >> user_choice;

    rps(user_choice);

    return 0;
}

void rps(const short unsigned int& user_choice)
{
    const short unsigned int random = rand() % 3;
    cout << random << endl;

    switch (random)
    {
        case 0: cout << "Computer Choice: Rock\n"; break;
        case 1: cout << "Computer Choice: Paper\n"; break;
        case 2: cout << "Computer Choice: Scissor\n"; break;
        default: cout << "Invalid Computer Choice"; break;
    }

    if (user_choice == random) cout << "It's a draw" << endl;
    else if ((user_choice == 0 && random == 2) ||
             (user_choice == 2 && random == 1) ||
             (user_choice == 2 && random == 0))
    {
        cout << "You Win" << endl;
    } else
    {
        cout << "You Lose" << endl;
    }
}

