#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int a = 5;
    float b = a; // implicit conversion of int to float.

    float c = 5.5;
    int d = static_cast<int>(c); // d is 5, explicit type conversion.

    float e = 10.3;
    int f = static_cast<int>(e);

    cout << "a: " << a << endl;
    cout << "typeof a: " << typeid(a).name() << endl;
    cout << "b: " << b << endl;
    cout << "typeof b: " << typeid(b).name() << endl;
    cout << "c: " << c << endl;
    cout << "typeof c: " << typeid(c).name() << endl;
    cout << "d: " << d << endl;
    cout << "typeof d: " << typeid(d).name() << endl;
    cout << "e: " << e << endl;
    cout << "typeof e: " << typeid(e).name() << endl;
    cout << "f: " << f << endl;
    cout << "typeof f: " << typeid(f).name() << endl;


    /////////////////////
    // Arithmetic
    /////////////////////

    int g = 5;
    double h = 10.0;

    const double sum = g + h;
    const double diff = g - h;
    const double mul = g * h;
    double div = h/g; // why ans is 2 and not 2.0

    cout << "\nsum: " << sum << endl;
    cout << "diff: " << diff << endl;
    cout << "mul: " << mul << endl;
    cout << "div: " << div << endl; // ans is 2 because cout formats the precision.
    cout << "typeof div: " << typeid(div).name() << endl;

    return 0;
}
