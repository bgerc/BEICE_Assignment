#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    char name[30];
    float salary;

    void inputData()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "Employee ID: " << id << endl;
        cout << "Employee name: " << name << endl;
        cout << "Employee salary: " << salary << endl;
    }
};
void display_employees(Employee emp[], int n, double sal)
{
    for (int i = 0; i < n; i++)
    {
        if (emp[i].salary > sal)
        {
            emp[i].display();
            cout << endl;
        }
    }
}

int main()
{

    Employee emp[100];
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for employee " << i + 1 << ":" << endl;
        emp[i].inputData();
        cout << endl;
    }
    double sal;
    cout << "Enter the salary threshold: ";
    cin >> sal;

    cout << "Employees with salary greater than " << sal << ":" << endl;
    display_employees(emp, n, sal);

    return 0;
}