#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    char* name;
    int id;
    float salary;

public:
    Employee() : id(0), salary(0) {}

    Employee(char* a, int i, float sal) {
        name = new char[strlen(a) + 1];
        strcpy(name, a);
        id = i;
        salary = sal;
    }

    bool operator>(int sal) const {
        return salary > sal;
    }

    void output() const {
        cout << "Employee ID: " << id << "\nEmployee Name: " << name << "\nEmployee Salary: NRs." << salary << endl;
    }

    ~Employee() {
        delete[] name;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees you want to record: ";
    cin >> n;
    Employee* e = new Employee[n];

    char name[100];
    int id, salary;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") Enter employee name: ";
        cin.ignore();
        cin.getline(name, 100);
        cout << "   Enter " << name << "'s id: ";
        cin >> id;
        cout << "   Enter " << name << "'s salary: ";
        cin >> salary;
        e[i] = Employee(name, id, salary);
        cout << endl;
    }

    cout << "\n\nEnter the employee salary you want to filter: ";
    cin >> salary;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (e[i] > salary) {
            cout << "\n\n";
            e[i].output();
            count++;
        }
    }

    if (count == 0) {
        cout << "No matching data.";
    } else {
        cout << "Total filter: " << count;
    }

    delete[] e;
    return 0;
}
 