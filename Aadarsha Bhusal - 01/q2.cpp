#include <iostream>
bool x = false;

class Employee
{
private:
    int m_id;
    std::string m_name;
    double m_salary;
public:
    friend void greaterSalary(Employee& e, double salary);
    void setData() {
        std::cout << "Enter id: ";
        std::cin >> m_id;
        std::cout << "Enter name: ";
        std::cin >> m_name;
        std::cout << "Enter salary: ";
        std::cin >> m_salary;
    }
    void displayData() {
        std::cout << "ID: " << m_id << "\n";
        std::cout << "Name: " << m_name << "\n";
        std::cout << "Salary: " << m_salary << "\n";
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
    std::cout << "Enter n: ";
    std::cin >> n;
    Employee e[n];
    for (int i = 0; i < n; i++) {
        e[i].setData();
    }

    double salary;
    std::cout << "User specified amount: ";
    std::cin >> salary;

    std::cout << "Employees having greater than given salary: \n";
    for (int i = 0; i < n; i++) {
        greaterSalary(e[i], salary);
    }
    if (x == false) {
        std::cout << "No data found!!!" << std::endl;
    }

    return 0;
}