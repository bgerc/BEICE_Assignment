#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    
    void input() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }
    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
    double getSalary() const {
        return salary;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee> employees(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].input();
    }

    double threshold;
    cout << "Enter the salary threshold: ";
    cin >> threshold;

    cout << "Employees with salary greater than " << threshold << ":" << endl;
    for (const auto& emp : employees) {
        if (emp.getSalary() > threshold) {
            emp.display();
        }
    }

    return 0;
}