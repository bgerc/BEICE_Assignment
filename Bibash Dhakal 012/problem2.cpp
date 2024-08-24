/*Design a class employee with id, name, and salary as data memebers.Implement functions to implement functions to input employee data and
display employees who have a salary greater than a user-specified amount. */

#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    double salary;

public:
    void input()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }

    double getSalary() const
    {
        return salary;
    }
};

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].input();
    }

    double maxsalary;
    cout << "Enter the max. salary: ";
    cin >> maxsalary;

    cout << "Employees with salary greater than " << maxsalary << ":" << endl;
    for (int i = 0; i < n; ++i)
    {
        if (employees[i].getSalary() > maxsalary)
        {
            employees[i].display();
        }
    }

    delete[] employees;
    return 0;
}