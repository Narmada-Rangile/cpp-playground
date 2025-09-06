// Create a program that counts the number of duplicate elements in an array

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_duplicates(const vector<int>& arr)
{
    unordered_map<int, int> frequency;

    for (const int& elem: arr)
    {
        // for each element, we make key: value here
        frequency[elem]++;
    }

    int duplicate_count = 0;
    for (const auto& [first, second] : frequency)
    {
        // greater than one because we need to see the elements that occur more than 1 time.
        if (second > 1)
        {
            // minus 1 because we are calculating extra occurrences.
            duplicate_count += second - 1;
        }
    }

    return duplicate_count;
}

// function to show the duplicates in a beautiful way
void display_duplicates(const vector<int>& arr)
{
    unordered_map<int, int> frequency;

    for (const int& elem: arr)
    {
        // for each element, we make key: value here
        frequency[elem]++;
    }

    cout << "Duplicate elements and their frequencies: " << endl;
    for (const auto& [first, second] : frequency)
    {
        if (second > 1)
        {
            cout << first << " appears " << second << " times." << endl;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array: ";
    for (int& elem : arr)
    {
        cin >> elem;
    }

    cout << "Array elements: ";
    for (const int& elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    const int duplicates = count_duplicates(arr);
    cout << "Number of duplicate elements: " << duplicates << endl;

    display_duplicates(arr);

    return 0;
}
