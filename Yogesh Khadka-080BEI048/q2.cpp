/*Design a class Employee with id,name and salary as data members.Implement functions to input employee data and display employees who have a salary greater than a user-specified amount*/
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    void inputEmployeeData() {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
    }

    void displayEmployeesWithSalaryGreaterThan(double amount) {
        if (salary > amount) {
            cout << "Employee ID: " << id << endl;
            cout << "Employee Name: " << name << endl;
            cout << "Employee Salary: " << salary << endl;
        }
    }
};

int main() {
    int numEmployees;
    double minSalary;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].inputEmployeeData();
    }

    cout << "Enter the minimum salary: ";
    cin >> minSalary;

    cout << "Employees with salary greater than " << minSalary << ":" << endl;
    for (int i = 0; i < numEmployees; i++) {
        employees[i].displayEmployeesWithSalaryGreaterThan(minSalary);
    }

    delete[] employees;

    return 0;
}