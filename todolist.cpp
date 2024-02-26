#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string name;
    bool completed;

    Task(const string& n) : name(n), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& taskName) {
    tasks.push_back(Task(taskName));
    cout << "Task \"" << taskName << "\" added." << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (tasks[i].completed ? "[X] " : "[ ] ");
        cout << tasks[i].name << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task \"" << tasks[taskIndex - 1].name << "\" marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        cout << "Task \"" << tasks[taskIndex - 1].name << "\" removed." << endl;
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskName;
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, taskName);
                addTask(tasks, taskName);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
