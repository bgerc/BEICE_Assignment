#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;
};

int main() {
    Employee employees[12];

    employees[0].id = 14;
    employees[0].name = "Bijay Dhakal";
    employees[0].salary = 50000.0;

    employees[1].id = 15;
    employees[1].name = "Hari Rai";
    employees[1].salary = 51000.0;

    employees[2].id = 16;
    employees[2].name = "Rahul Shrestha";
    employees[2].salary = 52000.0;

    employees[3].id = 17;
    employees[3].name = "Tirthankar Khatiwada";
    employees[3].salary = 53000.0;

    employees[4].id = 18;
    employees[4].name = "Kamal Dhakal";
    employees[4].salary = 54000.0;

    employees[5].id = 19;
    employees[5].name = "Kalpana Roila";
    employees[5].salary = 55000.0;

    employees[6].id = 20;
    employees[6].name = "Sushant Yadav";
    employees[6].salary = 56000.0;

    employees[7].id = 21;
    employees[7].name = "Bishab Shakya";
    employees[7].salary = 57000.0;

    employees[8].id = 22;
    employees[8].name = "Suraj Jaiswal";
    employees[8].salary = 58000.0;

    employees[9].id = 23;
    employees[9].name = "Samman Khanal";
    employees[9].salary = 59000.0;

    employees[10].id = 24;
    employees[10].name = "Prasoon Dahal";
    employees[10].salary = 60000.0;

    employees[11].id = 25;
    employees[11].name = "Anmol Katwal";
    employees[11].salary = 61000.0;

    double salary_threshold;
    cout << "Enter a salary threshold: ";
    cin >> salary_threshold;

    for (int i = 0; i < 12; i++) {
        if (employees[i].salary > salary_threshold) {
            cout << "Employee " << employees[i].name << " (ID: " << employees[i].id << ")" << endl;
        }
    }

    return 0;
}
