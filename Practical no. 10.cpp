
#include <iostream>
#include <string>
using namespace std;

// Class Template
template <class T>
class StudentResult {
    string name;
    T marks1, marks2;

public:
    void input() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks in Subject 1: ";
        cin >> marks1;

        cout << "Enter marks in Subject 2: ";
        cin >> marks2;
    }

    T totalMarks() {
        return marks1 + marks2;
    }

    double averageMarks() {
        return (static_cast<double>(marks1) + marks2) / 2.0;
    }

    void display() {
        cout << "\n--- Student Result ---\n";
        cout << "Student Name: " << name << endl;
        cout << "Subject 1 Marks: " << marks1 << endl;
        cout << "Subject 2 Marks: " << marks2 << endl;
        cout << "Total Marks: " << totalMarks() << endl;
        cout << "Average Marks: " << averageMarks() << endl;
    }

    T getMarks1() {
        return marks1;
    }

    T getMarks2() {
        return marks2;
    }
};

// Function Template
template <class T>
T findGreater(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    StudentResult<float> student;

    student.input();
    student.display();

    cout << "Greater Marks: "
         << findGreater(student.getMarks1(),
                        student.getMarks2())
         << endl;

    return 0;
}

