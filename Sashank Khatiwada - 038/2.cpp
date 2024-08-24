#include <iostream>
using namespace std;

class EMPLOYEE
{
    int id;
    char name[50];
    float salary;

    public:
    void getdata()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore(); 
        cin.getline(name, 50); 
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void showdata() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    float getsalary() const
    {
        return salary;
    }
};

int main()
{
    int n;
    float minsal;
    int i;
    bool f;

    cout << "Enter number of employees: ";
    cin >> n;

    
    EMPLOYEE e[n];

   
    for ( i = 0; i < n; i++)
    {
        cout << "Enter details of employee " << (i + 1) << ":" << endl;
        e[i].getdata();
    }

    cout << "Enter salary threshold: ";
    cin >> minsal;

    
    cout << "Employees with salary greater than " << minsal << ":" << endl;
    f = false;
    for ( i = 0; i < n; i++) 
    {
        if (e[i].getsalary() > minsal) 
        {
            e[i].showdata();
            f = true;
        }
    }

    if (!f) 
    {
        cout << "No employees found with a salary greater than " << minsal << "." << endl;
    }

    return 0;
}
