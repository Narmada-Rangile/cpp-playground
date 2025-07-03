// This program demonstrates how to read user input and echo it back to the console.

#include <iostream>
#include <string>

int main()
{
    // Declare a string variable to hold user input
    std::string input;

    // Prompt the user for input
    std::cout << "Please enter your name: ";

    // Read user input from the console
    std::cin >> input;

    // Echo the input back to the console
    std::cout << "Hello, " << input << "! Welcome to the program." << std::endl;
}
