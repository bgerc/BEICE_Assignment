#include <iostream>
using namespace std;
bool x = false;

class Employee
{
private:
    int id;
    string name;
    double salary;
public:
    friend void greaterSalary(Employee& e, double salary);
    void getData() {
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void showData() {
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
    }
};
void greaterSalary(Employee& e, double salary) {
    if (e.salary > salary) {
        e.showData();
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
        e[i].getData();
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
