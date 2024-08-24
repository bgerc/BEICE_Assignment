#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name = "", const string& dateOfBirth = "")
        : name(name), dateOfBirth(dateOfBirth) {}

    string getName() const { return name; }
    string getDateOfBirth() const { return dateOfBirth; }

    void setName(const string& name) { this->name = name; }
    void setDateOfBirth(const string& dateOfBirth) { this->dateOfBirth = dateOfBirth; }

private:
    string name;
    string dateOfBirth;
};

int main() {
    const int MAX_PERSONS = 100;
    Person persons[MAX_PERSONS];
    int numPersons = 0;

    cout << "Enter the number of persons (up to " << MAX_PERSONS << "): ";
    cin >> numPersons;
    cin.ignore();

    if (numPersons > MAX_PERSONS) {
        cout << "Number exceeds maximum limit of " << MAX_PERSONS << "." << endl;
        return 1;
    }

    for (int i = 0; i < numPersons; ++i) {
        string name, dateOfBirth;
        cout << "Enter the person's name: ";
        getline(cin, name);
        cout << "Enter the person's date of birth (YYYY-MM-DD): ";
        getline(cin, dateOfBirth);
        persons[i].setName(name);
        persons[i].setDateOfBirth(dateOfBirth);
    }

    string searchDateOfBirth;
    cout << "Enter the date of birth to search (YYYY-MM-DD): ";
    getline(cin, searchDateOfBirth);

    bool found = false;
    cout << "Persons with the matching date of birth:" << endl;
    for (int i = 0; i < numPersons; ++i) {
        if (persons[i].getDateOfBirth() == searchDateOfBirth) {
            cout << persons[i].getName() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No persons found with the matching date of birth." << endl;
    }

    return 0;
}
