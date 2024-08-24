//Assignment 2
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;

    
    Employee() : id(0), name(""), salary(0.0) {}
    
    Employee(int emp_id,   string &emp_name, double emp_salary): id(emp_id), name(emp_name), salary(emp_salary) {}
        
    void display()  {
        cout << "Employee(ID: " << id << ", Name: " << name << ", Salary: " << salary << ")" <<endl;
    }
};

int main() {
    int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int id;
        string name;
        double salary;

        cout << "Enter details for employee " << i + 1 << ":" <<endl;
        cout << "ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Name: ";
        getline( cin, name);
        cout << "Salary: ";
        cin >> salary;

        employees[i] = Employee(id, name, salary);
    }

    double threshold;
    cout << "Enter the salary threshold: ";
    cin >> threshold;

    cout << "Employees with salary greater than " << threshold << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (employees[i].salary > threshold) {
            employees[i].display();
        }
    }

    return 0;
}