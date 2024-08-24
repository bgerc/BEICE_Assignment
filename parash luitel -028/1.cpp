#include<iostream>
using namespace std;

class Person {
private:
    char name[100];
    int db;

public:
    void getInput() {
        cin.ignore();
        cout << "Enter the person's name: ";
        cin.getline(name, 100);
        cout << "Enter date of birth (in AD): ";
        cin >> db;
    }

    int getDob() const {
        return db;
    }

    void display() const {
        cout << "\nName: " << name;
    }
};

int main() {
    system("cls");
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    Person* persons = new Person[n];

    for (int i = 0; i < n; i++) {
        persons[i].getInput();
    }

    int dob;
    cout << "Enter the date of birth you want to search for: ";
    cin >> dob;

    cout << "Person(s) with the matching date of birth:";
    for (int i = 0; i < n; i++) {
        if (persons[i].getDob() == dob) {
            persons[i].display();
        }
    }

    delete[] persons;
    return 0;
}
