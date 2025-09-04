// Conversion between lengths in meters and feet.

#include <iostream>

int main()
{
    double meter, feet;
    char choice;

    std::cout << "Length Conversion Program" << std::endl;
    std::cout << "Choose Conversion Type: \n";
    std::cout << "1. Meters to Feet\n";
    std::cout << "2. Feet to Meters\n";
    std::cout << "Enter Choice: (1 or 2): ";
    std::cin >> choice;

    if (choice == '1')
    {
        std::cout << "Enter Length in Meters: ";
        std::cin >> meter;
        feet = meter * 3.28;
        std::cout << meter << " Meters is " << feet << " feet.\n";
    }
    else if (choice == '2')
    {
        std::cout << "Enter Length in Feet: ";
        std::cin >> feet;
        meter = feet / 3.28;
        std::cout << feet << " Feet is " << meter << " Meters.\n";
    }
    else
    {
        std::cout << "Invalid Choice. Please run the program again.\n";
    }

    return 0;
}
