#include <iostream>
#include <string>
using namespace std;
class Employee
{
    string name;
    int id;
    float salary;

public:
    Employee(string n = "", int i = 0, float s = 0) : name(n), id(i), salary(s) {}

    void input()
    {
        cin.ignore();
        cout << "Enter name : ";
        getline(cin, name);
        cout << "Enter id : ";
        cin >> id;
        cout << "Enter Salary : ";
        cin >> salary;
        cout << endl;
    }
    bool checkSal(int &sal) const
    {
        return (salary >= sal);
    }

    void output() const
    {
        cout << "Name : " << name;
        cout << ",  ID : " << id;
        cout << ",  Salary : " << salary;
    }
};
int main()
{
    int n;
    cout << "Enter Total Number of Employees : ";
    cin >> n;

    Employee *Emp = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the details for Employee " << i + 1 << endl;
        Emp[i].input();
    }

    int sal;
    cout << "Enter a specific amount of salary : ";
    cin >> sal;

    cout << "\nLists of People having salary greater than " << sal << endl;
    int SN = 1;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (Emp[i].checkSal(sal))
        {
            cout << SN << ". ";
            Emp[i].output();
            cout << endl;
            SN++;
            check = true;
        }
    }
    if (!check)
    {
        cout << "No match found." << endl;
    }
    delete[] Emp;

    return 0;
}
