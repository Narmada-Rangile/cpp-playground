// Use an array of strings to manage a list of tasks. Implement functions to add, view, and mark tasks as complete.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function to display all tasks from the to-do
void display_tasks (const vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "\n===== TO-DO LIST =====" << endl;
    int task_num = 1;
    for (const string& task : tasks)
    {
        cout << task_num++ << ". " << task << endl;
    }
    cout << "===== ===== ===== =====" << endl;
}

void add_task (vector<string>& tasks)
{
    string new_task;
    cout << "Enter new task: ";
    cin.ignore(); // doing this to clear input buffer if any
    getline(cin, new_task);

    tasks.push_back(new_task);
    cout << "Task added successfully!" << endl;
}

void remove_task (vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks to remove. " << endl;
        return;
    }

    int task_num;
    cout << "Enter the task number to remove in (1-" << tasks.size() << "): ";
    cin >> task_num;

    if (task_num < 1 || task_num > static_cast<int>(tasks.size()))
    {
        cout << "Invalid task number!" << endl;
        return;
    }

    tasks.erase(tasks.begin() + task_num - 1);
    cout << "Task removed successfully!" << endl;
}

int main()
{
    vector<string> tasks;
    int choice;

    cout << "===== SIMPLE TO-DO LIST MANAGER =====" << endl;

    do
    {
        cout << "\n1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Exit the program\n" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                add_task(tasks);
                break;
            case 2:
                display_tasks(tasks);
                remove_task(tasks);
                break;
            case 3:
                display_tasks(tasks);
                break;
            case 4:
                cout << "See ya!" << endl;
                break;
            default:
                cout << "Invalid Choice! Try Again!!" << endl;
        }
    }
    while (choice != 4);

    return 0;
}
