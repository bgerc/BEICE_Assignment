#include <iostream>
#include <cstring>
using namespace std;

class Employee 
{
private:
    int id;
    string name;  
    double salary;

public:
    Employee() : id(0), salary(0.0) {}

    void inputData() {
        cout << "Enter employee ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
    }
    void displayData() 
     {
        cout << "ID:" << id << endl;
        cout << "Name:" << name << endl;
        cout << "Salary:" << salary << endl;
    }

    bool hasSalaryGreaterThan(double amount) const {
        return salary > amount;
    }
};

int main() 
{
    int n;
    double minSalary;
    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore(); 
    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter employees details: " << i + 1 << ":" << endl;
        emp[i].inputData();
    }
    cout << "Enter the minimum salary: ";
    cin >> minSalary;
    bool anyMatch = false;
    cout << "Employees with salary greater than:" << minSalary << endl;
    for (int i = 0; i < n; i++) {
        if (emp[i].hasSalaryGreaterThan(minSalary)) {
            emp[i].displayData();
            anyMatch = true;
        }
    }

    if (!anyMatch) {
        cout << "No employee has a salary greater than :" << minSalary << endl;
    }
delete[] emp; 
return 0;
 }
