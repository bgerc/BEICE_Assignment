#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Person {
private:
    string name;
    string dateOfBirth; 

public:
  
    Person(const string& name, const string& dob) : name(name), dateOfBirth(dob) {}

    string getName() const {
        return name;
    }

    
    string getDateOfBirth() const {
        return dateOfBirth;
    }

    bool matchesDateOfBirth(const string& dob) const {
        return dateOfBirth == dob;
    }
};


void printMatchingPersons(const vector<Person>& persons, const string& dob) {
    bool found = false;
    for (const auto& person : persons) {
        if (person.matchesDateOfBirth(dob)) {
            cout << person.getName() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No persons found with the given date of birth." << endl;
    }
}

int main() {
    vector<Person> persons;
    string name, dateOfBirth, searchDateOfBirth;
    int numPersons;

    cout << "Enter the number of persons: ";
    cin >> numPersons;
    cin.ignore();

    for (int i = 0; i < numPersons; ++i) {
        cout << "Enter name of person " << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter date of birth of person " << (i + 1) << " (YYYY-MM-DD): ";
        getline(cin, dateOfBirth);
        persons.emplace_back(name, dateOfBirth);
    }

    cout << "Enter date of birth to search (YYYY-MM-DD): ";
    getline(cin, searchDateOfBirth);

    
    cout << "Persons with date of birth " << searchDateOfBirth << ":" << endl;
    printMatchingPersons(persons, searchDateOfBirth);

    return 0;
}
