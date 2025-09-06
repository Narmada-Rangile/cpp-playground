// Write a function to reverse the elements of an array in-place.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using algorithm STL
void reverse_array(vector<int>& arr)
{
    reverse(arr.begin(), arr.end());
}

// manual reversing
void reverse_array_manual (vector<int>& arr)
{
    auto start = arr.begin();
    auto end = arr.end() - 1;

    while (start < end)
    {
        swap(*start, *end);
        ++start;
        --end;
    }
}

// make a function to display the array
void display_array (const vector<int>& arr)
{
    for (const int& elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int& element : arr)
    {
        cin >> element;
    }

    cout << "Original Array: ";
    display_array(arr);

    reverse_array_manual(arr);
    cout << "Reversed Array: ";
    display_array(arr);

    return 0;
}
