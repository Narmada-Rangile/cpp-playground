// Use parallel arrays to store student names, roll numbers, and marks in different subjects. Display a formatted report card.

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
    string name;
    vector<int> grades;

    Student(string n, const vector<int>& g) : name(n), grades(g) {}
};

// calculate avg grade
float calculate_avg (const vector<int>& grades)
{
    int sum = 0;
    for (const int& grade : grades)
    {
        sum += grade;
    }
    return static_cast<float>(sum) / static_cast<float>(grades.size());
}

// function to assign a letter grade like A, B, C, D and F
char assign_grade_letter(const float average)
{
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// function to display a student's report
void display_student_report (const Student& student, const int student_num)
{
    const float average = calculate_avg(student.grades);
    const char letter_grade = assign_grade_letter(average);

    cout << "Student " << student_num << ": " << student.name << endl;
    cout << "Grades: ";
    for (const int& grade: student.grades)
    {
        cout << grade << " ";
    }
    cout << endl;
    cout << "Average: " << fixed << setprecision(2) << average << endl;
    cout << "Letter Grade: " << letter_grade << endl;
    cout << "===== ===== ===== =====" << endl;
}

// function to display class summary
void display_class_summary(const vector<Student>& students)
{
    float class_total = 0;
    const Student* highest_student = &students[0];
    const Student* lowest_student = &students[0];

    float highest_avg = calculate_avg(students[0].grades);
    float lowest_avg = highest_avg;

    cout << "\n==== CLASS SUMMARY =====" << endl;

    for (const Student& student : students)
    {
        const float avg = calculate_avg((student.grades));
        class_total += avg;

        if (avg > highest_avg)
        {
            highest_avg = avg;
            highest_student = &student;
        }

        if (avg < lowest_avg)
        {
            lowest_avg = avg;
            lowest_student = &student;
        }
    }

    const float class_avg = class_total / students.size();

    cout << "Class Average: " << fixed << setprecision(2) << class_avg << endl;
    cout << "Highest Performer: " << highest_student->name << " (" << highest_avg << ")" << endl;
    cout << "Lowest Performer: " << lowest_student->name << " (" << lowest_avg << ")" << endl;
}

int main()
{
    vector<Student> students;
    int student_count;

    cout << "===== STUDENT REPORT CARD SYSTEM =====" << endl;

    cout << "Enter number of students: ";
    cin >> student_count;

    // Input student data
    for (int i = 0; i < student_count; i++)
    {
        cout << "\nEnter data for student " << (i+1) << ":" << endl;

        string name;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        vector<int> grades(3); // size set to 3, let us say three subjects.
        cout << "Maths grade: ";
        cin >> grades[0];

        cout << "Physics grade: ";
        cin >> grades[1];

        cout << "Chemistry grade: ";
        cin >> grades[2];

        Student student_temp(name, grades);
        students.push_back(student_temp);
    }

    // Display individual reports:
    cout << "\n===== INDIVIDUAL REPORTS =====" << endl;
    int student_num (1);
    for (const Student& student : students)
    {
        display_student_report(student, student_num++);
    }

    display_class_summary(students);
    return 0;
}
