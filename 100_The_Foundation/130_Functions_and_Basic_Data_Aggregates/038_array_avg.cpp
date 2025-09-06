// Create an array of numbers and write a function to compute their average.

#include <iostream>
using namespace std;

double array_avg (int arr[], const int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum/size;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    constexpr  int sz = size(arr);
    const double avg = array_avg(arr, sz);
    cout << "The average is: " << avg << endl;

    return 0;
}
