// Write a function that sorts an integer array using the bubble sort algorithm.

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr)
{
    const int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;

        // some part is already sorted, so n - i - 1
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

// function to display the array
void display_array(const vector<int>& arr)
{
    for (const int& element : arr)
    {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter " << size << " elements: ";
    for (int& element : arr)
    {
        cin >> element;
    }

    cout << "\nOriginal Array: ";
    display_array(arr);

    bubble_sort(arr);
    cout << "Sorted Array: ";
    display_array(arr);

    return 0;
}
