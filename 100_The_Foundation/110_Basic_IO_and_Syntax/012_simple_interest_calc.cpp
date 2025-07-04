// Take principal, rate, and time as input and calculate the simple interest.

#include <iostream>
using namespace std;

int main() {
    double principal, rate, time;

    cout << "Enter the principal amount: ";
    cin >> principal;

    cout << "Enter the rate of interest (in %): ";
    cin >> rate;

    cout << "Enter the time period (in years): ";
    cin >> time;

    const double simpleInterest = (principal * rate * time) / 100;

    cout << "The simple interest is: " << simpleInterest << endl;

    return 0;
}
