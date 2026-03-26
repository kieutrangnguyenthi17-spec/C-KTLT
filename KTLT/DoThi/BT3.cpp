#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>  // cho numeric_limits
using namespace std;

struct Student {
    string name;
    double score;
};

int findStudent(const vector<Student> &students, const string &name) {
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].name == name) {
            return i;
        }
    }
    return -1;
}

void sortStudents(vector<Student> &students) {
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if (a.score != b.score) return a.score > b.score;
        return a.name < b.name;
    });
}

void printStudents(const vector<Student> &students) {
    cout << "\n-- Student List --\n";
    for (const auto &s : students) {
        cout << s.name << " " << s.score << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    cout << "Enter student name and score:\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].score;
    }

    while (true) {
        cout << "\n1. Add or update student score\n";
        cout << "2. Delete student by name\n";
        cout << "3. Print sorted student list\n";
        cout << "4. Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            string name;
            double score;
            cout << "Enter name and score: ";
            cin >> name >> score;

            int pos = findStudent(students, name);
            if (pos != -1) {
                students[pos].score = score;  // update score
                cout << "Updated student " << name << "'s score to " << score << ".\n";
            } else {
                students.push_back({name, score});  // add new student
                cout << "Added student " << name << " with score " << score << ".\n";
            }
        }
        else if (choice == 2) {
            string name;
            cout << "Enter name to delete: ";
            cin >> name;

            int pos = findStudent(students, name);
            if (pos != -1) {
                students.erase(students.begin() + pos);
                cout << "Deleted student " << name << ".\n";
            } else {
                cout << "Student " << name << " not found.\n";
            }
        }
        else if (choice == 3) {
            sortStudents(students);
            printStudents(students);
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please choose again.\n";
        }
    }

    return 0;
}
