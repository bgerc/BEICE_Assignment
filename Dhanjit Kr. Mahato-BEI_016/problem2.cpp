/* Assignment
    
    Design a class Employee with id, name and salary as data members.
    Implement functions to imput employee data and display employees who have a salary greater than a user specified amount.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    char *name;
    int id;
    float salary;
    public:
        Employee()
        {
            id = 0;
            salary = 0;
        }
        Employee(char *a, int i, float sal) 
        {
            name = new char[strlen(a) + 1];
            strcpy(name, a);
            id = i;
            salary = sal;
        }
        bool operator > (int sal)
        {
            if (salary > sal)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void output()
        {
            cout << "Employee ID: " << id << endl << "Employee Name: " << name << endl << "Employee Salary: NRs." << salary << endl;
        }
        ~Employee()
        {
            delete[] name;
        }
};

int main()
{
    int n;
    cout << "Enter the number of employees you want to record: " << endl;
    cin >> n;
    Employee *e = new Employee[n];
    char name[100];
    int id;
    int salary;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ") Enter employee name: ";
        cin.ignore();
        cin.getline(name, 100);
        cout << "   Enter " << name << "'s id: ";
        cin >> id;
        cout << "   Enter " << name << "'s salary: ";
        cin >> salary;
        e[i] = Employee(name, id, salary);
        cout << endl;
    }
    cout << endl << endl;
    cout << "Enter the employee salary you want to filter: ";
    cin >> salary;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i] > salary)
        {
            cout << endl << endl;
            e[i].output();
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No matching date.";
    }
    else 
    {
        cout << "Total filter: " << count;
    }
    return 0;
}