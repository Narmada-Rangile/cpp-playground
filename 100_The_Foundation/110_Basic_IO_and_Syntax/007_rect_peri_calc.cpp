// Ask for width and height then output perimeter of rectangle

#include <iostream>

int main()
{
    double width, height;
    std::cout << "Enter width and height of rectangle: ";
    std::cin >> width >> height;
    std::cout << "Area of rectangle: " << width * height << '\n';
    std::cout << "Perimeter of rectangle:" << 2 * (width + height) << '\n';

    return 0;
}
