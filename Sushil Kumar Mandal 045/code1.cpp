#include<iostream>
using namespace std;

// Multiple Inheritance
class person {
protected:
    string Name;
    int Age;
    int id;
public:
    void getdata() {
        cout << "Enter the name of the person: ";
        cin >> Name;
        cout << "Age: ";
        cin >> Age;
        cout << "Id: ";
        cin >> id;
    }
    void showdata() {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Id: " << id << endl;
    }
};

class employee {
protected:
    string designation;
    float basic_Salary;
    float total_Overtime;
    float hourly_rate;
public:
    void getdata() {
        cout << "Enter the designation of employee: ";
        cin >> designation;
        cout << "Enter the salary: ";
        cin >> basic_Salary;
        cout << "Enter rate of overtime per hour: ";
        cin >> hourly_rate;
        cout << "Total Overtime done in a month(in hr):  ";
        cin >> total_Overtime;
    }
    void showdata() {
        cout << "Designation: " << designation << endl;
    }
};

class computedSalary : public employee, public person {
    float total_Salary;
public:
    computedSalary() : total_Salary(0) {}

    void getdata() {
        person::getdata();
        employee::getdata();
    }

    void showdata() {
        total_Salary = basic_Salary + total_Overtime * hourly_rate;
        person::showdata();
        employee::showdata();
        cout << "Total Salary: " << total_Salary << endl;
    }
};

int main() {
    computedSalary s;
    s.getdata();
    s.showdata();
    return 0;
}