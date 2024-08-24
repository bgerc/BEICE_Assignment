#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Employee {
public:
    int id;
    string name;
    double salary;

    Employee(int i, string n, double s) : id(i), name(n), salary(s) {}

    static Employee inputEmployee() {
        int id;
        string name;
        double salary;

        cout << "Enter employee ID: ";
        cin >> id;

        cout << "Enter employee name: ";
        cin.ignore(); // Ignore newline character left in input buffer
        getline(cin, name);

        cout << "Enter employee salary: ";
        cin >> salary;

        return Employee(id, name, salary);
    }

    void displayEmployee() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

void displayEmployees(const vector<Employee>& employees, double minSalary) {
    cout << "Employees with salary greater than " << minSalary << ":\n";
    for (const auto& employee : employees) {
        if (employee.salary > minSalary) {
            employee.displayEmployee();
            cout << endl;
        }
    }
}

int main() {
    vector<Employee> employees;

    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        employees.push_back(Employee::inputEmployee());
    }

    double minSalary;
    cout << "Enter minimum salary: ";
    cin >> minSalary;

    displayEmployees(employees, minSalary);

    return 0;
}