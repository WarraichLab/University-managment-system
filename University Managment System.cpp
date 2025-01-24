#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// --- Linked List for Student Management ---
struct Student {
    int rollNumber;
    string name;
    Student* next;
};

struct Section {
    string sectionName;
    Student* studentList;
};

map<string, Section> sections;

void addStudentToSection(string sectionName, int roll, string name) {
    if (sections.find(sectionName) == sections.end()) {
        sections[sectionName] = {sectionName, nullptr};
    }

    Student*& head = sections[sectionName].studentList;
    Student* newStudent = new Student{roll, name, nullptr};
    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newStudent;
    }
}

void displayStudentsInSection(string sectionName, bool sorted) {
    if (sections.find(sectionName) == sections.end() || !sections[sectionName].studentList) {
        cout << "No students in section " << sectionName << ".\n";
        return;
    }

    vector<Student*> studentVector;
    Student* temp = sections[sectionName].studentList;
    while (temp) {
        studentVector.push_back(temp);
        temp = temp->next;
    }

    if (sorted) {
        sort(studentVector.begin(), studentVector.end(), [](Student* a, Student* b) {
            return a->rollNumber < b->rollNumber;
        });
    }

    for (Student* s : studentVector) {
        cout << s->name << " (Roll: " << s->rollNumber << ")\n";
    }
}

// --- Queue for Course Enrollment ---
struct Queue {
    vector<int> students;
    int capacity;

    Queue(int cap) : capacity(cap) {}

    void enqueue(int roll) {
        if (students.size() < capacity) {
            students.push_back(roll);
            cout << "Student with Roll " << roll << " added to the course.\n";
        } else {
            cout << "Course is full. Student added to the waiting list.\n";
        }
    }

    void dequeue() {
        if (!students.empty()) {
            cout << "Student with Roll " << students.front() << " removed from the course.\n";
            students.erase(students.begin());
        } else {
            cout << "No students in the queue.\n";
        }
    }

    void displayQueue() {
        if (students.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Students in Queue: ";
        for (int roll : students) {
            cout << roll << " ";
        }
        cout << "\n";
    }
};

// --- Stack for Attendance ---
struct Stack {
    vector<pair<int, bool>> records;

    void push(int roll, bool present) {
        records.push_back({roll, present});
        cout << "Attendance recorded for Roll " << roll << ": " << (present ? "Present" : "Absent") << "\n";
    }

    void displayAttendanceForSection(string sectionName) {
        if (sections.find(sectionName) == sections.end() || !sections[sectionName].studentList) {
            cout << "No students in section " << sectionName << ".\n";
            return;
        }

        Student* temp = sections[sectionName].studentList;
        cout << "Mark attendance for section: " << sectionName << "\n";
        while (temp) {
            cout << "Roll " << temp->rollNumber << " - " << temp->name << " (1 for Present, 0 for Absent): ";
            bool present;
            cin >> present;
            push(temp->rollNumber, present);
            temp = temp->next;
        }
    }

    void displayRecords() {
        if (records.empty()) {
            cout << "No attendance records.\n";
            return;
        }
        cout << "Attendance Records: \n";
        for (auto& record : records) {
            cout << "Roll " << record.first << ": " << (record.second ? "Present" : "Absent") << "\n";
        }
    }
};

// --- Binary Tree for Course Prerequisites ---
struct CourseNode {
    string courseName;
    CourseNode* left;
    CourseNode* right;

    CourseNode(string name) : courseName(name), left(nullptr), right(nullptr) {}
};

void addCourse(CourseNode*& root, string course) {
    if (!root) {
        root = new CourseNode(course);
    } else if (course < root->courseName) {
        addCourse(root->left, course);
    } else {
        addCourse(root->right, course);
    }
}

void inorderTraversal(CourseNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->courseName << " ";
    inorderTraversal(root->right);
}

// --- Main Function ---
int main() {
    Queue courseQueue(3);
    Stack attendanceStack;
    CourseNode* courseTree = nullptr;

    int choice;
    do {
        cout << "\n=== University Management System ===\n";
        cout << "1. Add Student to Section\n";
        cout << "2. Display Students in Section\n";
        cout << "3. Enroll in Course\n";
        cout << "4. Remove from Course\n";
        cout << "5. Display Course Queue\n";
        cout << "6. Mark Attendance for Section\n";
        cout << "7. Display Attendance Records\n";
        cout << "8. Add Course Prerequisite\n";
        cout << "9. View Course Prerequisites\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string sectionName;
                int roll;
                string name;
                cout << "Enter Section Name: ";
                cin >> sectionName;
                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                addStudentToSection(sectionName, roll, name);
                break;
            }
            case 2: {
                string sectionName;
                bool sorted;
                cout << "Enter Section Name: ";
                cin >> sectionName;
                cout << "Display sorted? (1 for Yes, 0 for No): ";
                cin >> sorted;
                displayStudentsInSection(sectionName, sorted);
                break;
            }
            case 3: {
                int roll;
                cout << "Enter Roll Number to Enroll: ";
                cin >> roll;
                courseQueue.enqueue(roll);
                break;
            }
            case 4:
                courseQueue.dequeue();
                break;
            case 5:
                courseQueue.displayQueue();
                break;
            case 6: {
                string sectionName;
                cout << "Enter Section Name: ";
                cin >> sectionName;
                attendanceStack.displayAttendanceForSection(sectionName);
                break;
            }
            case 7:
                attendanceStack.displayRecords();
                break;
            case 8: {
                string course;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, course);
                addCourse(courseTree, course);
                break;
            }
            case 9:
                cout << "Course Prerequisites: ";
                inorderTraversal(courseTree);
                cout << "\n";
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
