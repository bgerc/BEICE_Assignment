#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    Employee(int id = 0, const string& name = "", double salary = 0.0)
        : id(id), name(name), salary(salary) {}

    void inputEmployeeData() {
        cout << "Enter employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter employee name: ";
        getline(cin, name);

        cout << "Enter employee salary: ";
        cin >> salary;
        cin.ignore();
    }

    void displayEmployee() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }

    double getSalary() const {
        return salary;
    }

private:
    int id;
    string name;
    double salary;
};

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    cout << "Enter the number of employees (up to " << MAX_EMPLOYEES << "): ";
    cin >> numEmployees;
    cin.ignore();

    if (numEmployees > MAX_EMPLOYEES) {
        cout << "Number exceeds maximum limit of " << MAX_EMPLOYEES << "." << endl;
        return 1;
    }

    for (int i = 0; i < numEmployees; ++i) {
        cout << "Input data for employee " << (i + 1) << endl;
        employees[i].inputEmployeeData();
    }

    double salaryThreshold;
    cout << "Enter the salary threshold: ";
    cin >> salaryThreshold;
    cin.ignore();

    cout << "Employees with salary greater than $" << salaryThreshold << ":" << endl;
    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].getSalary() > salaryThreshold) {
            employees[i].displayEmployee();
            found = true;
        }
    }

    if (!found) {
        cout << "No employees found with a salary greater than $" << salaryThreshold << "." << endl;
    }

    return 0;
}

