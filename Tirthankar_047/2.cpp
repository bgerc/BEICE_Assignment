#include <iostream>
#include <vector>
#include <string.h>

class Employee {
public:
    int id;
    char name[50];
    double salary;

    Employee(int id, const char* name, double salary) {
        this->id = id;
        strcpy(this->name, name);
        this->salary = salary;
    }
};

void displayHighSalaryEmployees(const std::vector<Employee>& employees, double threshold) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].salary > threshold) {
            std::cout << "ID: " << employees[i].id << ", Name: " << employees[i].name << ", Salary: " << employees[i].salary << std::endl;
        }
    }
}

int main() {
    std::vector<Employee> employees = {
        Employee(1, "Tirthankar Khatiwada", 50000),
        Employee(2, "Purushottam khatiwada", 60000),
        Employee(3, "Kamala Niroula", 40000)
    };

    double salaryThreshold;
    std::cout << "Enter salary threshold: ";
    std::cin >> salaryThreshold;

    std::cout << "Employees with salary greater than " << salaryThreshold << ":" << std::endl;
    displayHighSalaryEmployees(employees, salaryThreshold);

    return 0;
}
