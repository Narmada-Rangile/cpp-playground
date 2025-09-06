// Write a function that finds the largest and smallest elements in an integer array.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_min (const vector<int>& arr)
{
    int min = INT_MAX;
    for (const int& element : arr)
    {
        if (element < min)
        {
            min = element;
        }
    }
    return min;
}

int find_max (const vector<int>& arr)
{
    int max = INT_MIN;
    for (const int& element: arr)
    {
        if (element > max)
        {
            max = element;
        }
    }
    return max;
}

int main()
{
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter " << size << " elements: ";
    for (int & element : arr)
    {
        cin >> element;
    }

    const int minimum = find_min(arr);
    const int maximum = find_max(arr);

    cout << "Array elements: ";
    for (const int& elem : arr)
    {
        cout << elem << " ";
    }

    cout << endl;

    cout << "Minimum value: " << minimum << endl;
    cout << "Maximum value: " << maximum << endl;

    return 0;
}
