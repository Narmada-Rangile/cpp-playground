// Generate a random number and have the user guess it, providing "too high" or "too low" feedback until they guess correctly.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    const int random = rand() % 101;

    int guess;

    while (guess != random)
    {
        cout << "Guess the number: " << endl;
        cin >> guess;
        if (guess > random)
        {
            cout << "high" << endl;
        } else if (guess == random)
        {
            cout << "you won!" << endl;
        } else
        {
            cout << "low" << endl;
        }
    }
    return 0;
}
