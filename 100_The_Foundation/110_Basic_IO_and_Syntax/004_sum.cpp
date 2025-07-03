// This program takes two integers as input from the user and outputs their sum.

#include <iostream>

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    const int sum = a + b;
    std::cout << "The sum of " << a << " and " << b << " is: " << sum << std::endl;

    return 0;
}
