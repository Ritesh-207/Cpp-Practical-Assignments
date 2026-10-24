
#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    int id;
    string name;
    double salary;

public:
    void inputEmployee() {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        getline(cin >> ws, name);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayEmployee() {
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name;
        cout << "\nSalary: Rs. " << salary << endl;
    }
};

// Single Inheritance
class Developer : public Employee {
public:
    string language;

    void input() {
        inputEmployee();
        cout << "Enter Programming Language: ";
        getline(cin >> ws, language);
    }

    void display() {
        displayEmployee();
        cout << "Programming Language: " << language << endl;
    }
};

// Multilevel Inheritance
class TeamLead : public Developer {
public:
    int teamSize;

    void input() {
        Developer::input();
        cout << "Enter Team Size: ";
        cin >> teamSize;
    }

    void display() {
        Developer::display();
        cout << "Team Size: " << teamSize << endl;
    }
};

// Second base class for multiple inheritance
class TaxInfo {
protected:
    double taxRate;

public:
    void inputTax() {
        cout << "Enter Tax Rate (%): ";
        cin >> taxRate;
    }

    void displayTax() {
        cout << "Tax Rate: " << taxRate << "%" << endl;
    }
};

// Multiple Inheritance
class Payroll : public Employee, public TaxInfo {
public:
    void input() {
        inputEmployee();
        inputTax();
    }

    void display() {
        displayEmployee();
        displayTax();
        cout << "Estimated Tax: Rs. "
             << salary * taxRate / 100 << endl;
    }
};

// Hierarchical Inheritance
class Manager : public Employee {
public:
    string department;

    void input() {
        inputEmployee();
        cout << "Enter Department: ";
        getline(cin >> ws, department);
    }

    void display() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

class Intern : public Employee {
public:
    int duration;

    void input() {
        inputEmployee();
        cout << "Enter Internship Duration (months): ";
        cin >> duration;
    }

    void display() {
        displayEmployee();
        cout << "Internship Duration: "
             << duration << " months" << endl;
    }
};

// Additional class for hybrid inheritance
class ProjectInfo {
protected:
    string projectName;

public:
    void inputProject() {
        cout << "Enter Project Name: ";
        getline(cin >> ws, projectName);
    }

    void displayProject() {
        cout << "Project Name: " << projectName << endl;
    }
};

// Hybrid Inheritance:
// TeamLead -> Developer -> Employee
// ProjectManager inherits TeamLead and ProjectInfo
class ProjectManager : public TeamLead, public ProjectInfo {
public:
    void input() {
        TeamLead::input();
        inputProject();
    }

    void display() {
        TeamLead::display();
        displayProject();
    }
};

int main() {
    int choice;

    cout << "=== EMPLOYEE MANAGEMENT SYSTEM ===\n";
    cout << "1. Single Inheritance\n";
    cout << "2. Multilevel Inheritance\n";
    cout << "3. Multiple Inheritance\n";
    cout << "4. Hierarchical Inheritance - Manager\n";
    cout << "5. Hierarchical Inheritance - Intern\n";
    cout << "6. Hybrid Inheritance\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Developer d;
            d.input();
            cout << "\n--- Developer Details ---\n";
            d.display();
            break;
        }

        case 2: {
            TeamLead t;
            t.input();
            cout << "\n--- Team Lead Details ---\n";
            t.display();
            break;
        }

        case 3: {
            Payroll p;
            p.input();
            cout << "\n--- Payroll Details ---\n";
            p.display();
            break;
        }

        case 4: {
            Manager m;
            m.input();
            cout << "\n--- Manager Details ---\n";
            m.display();
            break;
        }

        case 5: {
            Intern i;
            i.input();
            cout << "\n--- Intern Details ---\n";
            i.display();
            break;
        }

        case 6: {
            ProjectManager p;
            p.input();
            cout << "\n--- Project Manager Details ---\n";
            p.display();
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

