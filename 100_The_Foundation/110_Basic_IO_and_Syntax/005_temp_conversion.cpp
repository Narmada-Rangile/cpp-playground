// This script converts temperatures between Celsius and Fahrenheit.

#include <iostream>

int main() {
    double celsius, fahrenheit;
    char choice;

    std::cout << "Temperature Conversion Program\n";
    std::cout << "Choose conversion type:\n";
    std::cout << "1. Celsius to Fahrenheit (C to F)\n";
    std::cout << "2. Fahrenheit to Celsius (F to C)\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == '1') {
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> celsius;
        fahrenheit = (celsius * 9.0 / 5.0) + 32;
        std::cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit.\n";
    } else if (choice == '2') {
        std::cout << "Enter temperature in Fahrenheit: ";
        std::cin >> fahrenheit;
        celsius = (fahrenheit - 32) * 5.0 / 9.0;
        std::cout << fahrenheit << " Fahrenheit is " << celsius << " Celsius.\n";
    } else {
        std::cout << "Invalid choice! Please run the program again.\n";
    }

    return 0;
}
