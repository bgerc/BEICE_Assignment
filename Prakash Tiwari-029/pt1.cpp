#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int dob; 

public:
    void getInput() {
        cout << "Enter the person's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter date of birth (in AD): ";
        cin >> dob;
    }

    int getDob() const {
        return dob;
    }

    void show() const {
        cout << "Name: " << name << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    Person* persons = new Person[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for person " << i + 1 << ":" << endl;
        persons[i].getInput();
    }

    int dob;
    cout << "Enter the date of birth you want to see details for: ";
    cin >> dob;

    cout << "The person/people with matched date of birth are:" << endl;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (persons[i].getDob() == dob) {
            persons[i].show();
            found = true;
        }
    }

    if (!found) {
        cout << "No persons found with the date of birth " << dob << endl;
    }

    delete[] persons;
    return 0;
}
