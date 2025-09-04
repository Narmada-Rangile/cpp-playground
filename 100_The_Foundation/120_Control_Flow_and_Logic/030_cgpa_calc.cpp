// Allow a user to enter grades and credit hours for several courses and calculate the Cumulative Grade Point Average.

#include <iostream>
using namespace std;

double cgpa(const float marks[], int num_courses);

int main()
{
    int num_courses;
    cout << "Enter number of courses: ";
    cin >> num_courses;

    float marks[num_courses];
    for (int i = 0; i < sizeof(marks)/sizeof(float); i++)
    {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks[i];
    }

    const double CGPA = cgpa(marks, num_courses);
    cout << "CGPA is: " << CGPA << endl;
    return 0;
}

double cgpa(const float marks[], const int num_courses)
{
    float grades[num_courses];

    double sum = 0, cgpa = 0;

    for (int i = 0; i < num_courses; i++)
    {
        grades[i] = marks[i] / 10;
        sum += grades[i];
    }

    cgpa = sum / num_courses;
    return cgpa;
}
