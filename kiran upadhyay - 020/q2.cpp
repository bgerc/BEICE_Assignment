#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    
    Employee(int id, const string& name, double salary) : id(id), name(name), salary(salary) {}


    int getId() const {
        return id;
    }

    
    string getName() const {
        return name;
    }

    
    double getSalary() const {
        return salary;
    }

    
    bool hasSalaryGreaterThan(double amount) const {
        return salary > amount;
    }
};


void inputEmployeeData(vector<Employee>& employees) {
    int id;
    string name;
    double salary;
    int numEmployees;

    
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    cin.ignore(); 


    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter ID of employee " << (i + 1) << ": ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter name of employee " << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter salary of employee " << (i + 1) << ": ";
        cin >> salary;
        cin.ignore(); 

        employees.emplace_back(id, name, salary);
    }
}


void displayHighSalaryEmployees(const vector<Employee>& employees, double amount) {
    bool found = false;
    cout << "Employees with salary greater than " << amount << ":" << endl;
    for (const auto& employee : employees) {
        if (employee.hasSalaryGreaterThan(amount)) {
            cout << "ID: " << employee.getId() << ", Name: " << employee.getName()
                 << ", Salary: " << employee.getSalary() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No employees found with a salary greater than " << amount << "." << endl;
    }
}

int main() {
    vector<Employee> employees;
    double salaryThreshold;

    inputEmployeeData(employees);

    
    cout << "Enter salary threshold: ";
    cin >> salaryThreshold;

    
    displayHighSalaryEmployees(employees, salaryThreshold);

    return 0;
}
