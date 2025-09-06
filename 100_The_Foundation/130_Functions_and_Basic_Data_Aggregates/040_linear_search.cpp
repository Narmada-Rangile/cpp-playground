// Implement a function that searches for a given element in an array and returns its index or -1 if not found.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linear_search(const vector<int>& arr, const int target)
{
    if (const auto it = find(arr.begin(), arr.end(), target); it != arr.end())
    {
        return distance(arr.begin(), it); // distance from 1st elem to the target. = index
    }
    return -1; // not found
}

// let us make another linear search function which is more verbose.
int linear_search_alt(const vector<int>& arr, const int target)
{
    int index = 0;
    for (const int& element : arr)
    {
        if (element == target)
        {
            return index;
        }
        index++;
    }
    return  -1;
}

int main()
{
    int size, target;

    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter " << size << " elements: ";
    for (int& element : arr)
    {
        cin >> element;
    }

    cout << "Enter the element to search: ";
    cin >> target;

    const int result = linear_search(arr, target);

    // let us display the elements first
    cout << "Array elements: ";
    for (const int& elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    if (result != -1)
    {
        cout << "Element " << target << " found at index " << result << endl;
    } else
    {
        cout << "Element " << target << " not found in array" << endl;
    }
    return 0;
}
