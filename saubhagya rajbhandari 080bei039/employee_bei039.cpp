#include <iostream>
#include <string>

using namespace std;

class employee {
    string name;
    int id;
    double salary;

public:
    employee() 
    {
        name=" ";
        id=0;
        salary=0.0;
    }

    void getinput() {
        cout << "Enter the ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter the name of employee: ";
        getline(cin, name);
        cout << "Enter the salary of employee: ";
        cin >> salary;
        cin.ignore();
         
    }

    double getsalary()  {
        return salary;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

void findgreatestsalary(employee emp[], int count, double givensal) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (emp[i].getsalary() > givensal) {
            emp[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "No salary is more than the given amount." << endl;
    }
}

int main() {
    employee emp[100];
    int count = 0;
    char choice;
    double givensalary;

    do {
        if (count >= 100) {
            cout << "Sorry, max limit reached." << endl;
            break;
        }
        emp[count].getinput();
        count++;
        cout << "Do you have more input (y/n)? ";
        cin >> choice;
        cin.ignore(); 
    } while (choice == 'y' || choice == 'Y');

    cout << "Enter the salary you want to compare: ";
    cin >> givensalary;

    findgreatestsalary(emp, count, givensalary);

    return 0;
}
