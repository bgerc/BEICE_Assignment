
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    int salary;

public:
    void getInfo();
    void display(int) const;
};

void Employee::getInfo() {
    cout << "Enter the id: ";
    cin >> id;
    cout << "Enter the name: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, name);
    cout << "Enter the salary: ";
    cin >> salary;
}

void Employee::display(int baseSalary) const {
    if (salary > baseSalary) {
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
}

int main() {
    int n, baseSalary;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].getInfo();
    }

    cout << "Enter the minimum salary to display: ";
    cin >> baseSalary;

    cout << "Employees with a salary greater than " << baseSalary << " are:" << endl;
    for (int i = 0; i < n; ++i) {
        employees[i].display(baseSalary);
    }

    delete[] employees;
    return 0;
}
