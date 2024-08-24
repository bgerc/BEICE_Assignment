#include <iostream>
using namespace std;
bool x = false;

class Employee
{
private:
    int m_id;
    string m_name;
    double m_salary;
public:
    friend void greaterSalary(Employee& e, double salary);
    void setData() {
        cout << "Enter id: ";
        cin >> m_id;
        cout << "Enter name: ";
        cin >> m_name;
        cout << "Enter salary: ";
        cin >> m_salary;
    }
    void displayData() {
        cout << "ID: " << m_id << "\n";
        cout << "Name: " << m_name << "\n";
        cout << "Salary: " << m_salary << "\n";
    }
};
void greaterSalary(Employee& e, double salary) {
    if (e.m_salary > salary) {
        e.displayData();
        x = true;
    }
}
int main()
{
    int n{};
    cout << "Enter n: ";
    cin >> n;
    Employee e[n];
    for (int i = 0; i < n; i++) {
        e[i].setData();
    }

    double salary;
    cout << "User specified amount: ";
    cin >> salary;

    cout << "Employees having greater than given salary: \n";
    for (int i = 0; i < n; i++) {
        greaterSalary(e[i], salary);
    }
    if (x == false) {
        cout << "No data found!" << endl;
    }
    return 0;
}
