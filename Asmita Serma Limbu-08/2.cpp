/*Design a class Employee with id,name,and salary as data members.Implement functions to input employee data and display employees who have a salary greater than the user-specified amount*/
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    Employee() : id(0), name(""), salary(0.0) {}
    Employee(int empId, string empName, double empSalary) : id(empId), name(empName), salary(empSalary) {}
    void input() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        cin>>name;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }
    double getSalary() const {
        return salary;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};
void displayHighSalary(const Employee employees[], int count, double minSalary) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (employees[i].getSalary() > minSalary) {
            employees[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "No employees found with salary greater than " << minSalary << endl;
    }
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    char choice;
    do {
        if (count >= MAX_EMPLOYEES) {
            cout << "Maximum number of employees " << endl;
            break;
        }
        employees[count].input();
        count++;
        cout << "Do you want to add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    double minSalary;
    cout << "Enter the minimum salary to display employees: ";
    cin >> minSalary;
    displayHighSalary(employees, count, minSalary);

    return 0;
}