// Implement a calculator for +, -, *, / operations using a switch-case statement based on user input.

#include <iostream>
using namespace std;

int main()
{
    double number1, number2;
    char op;

    cout << "Enter two numbers: ";
    cin >> number1 >> number2;

    cout << "Enter operator + - * /: ";
    cin >> op;

    switch (op)
    {
        case '+': cout << number1 + number2; break;
        case '-': cout << number1 - number2; break;
        case '*': cout << number1 * number2; break;
        case '/':
            {
                if (number2 == 0)
                {
                    cout << "Error: div by 0 not defined";
                    break;
                }

                cout << number1 / number2; break;
            }
        default:
            {
                cout << "invalid operator";
                break;
            }

    };


    return 0;
}
