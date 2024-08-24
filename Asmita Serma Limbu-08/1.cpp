/*Create a class person name and date of birth as a data members.Ask a user to enter a date of birth and print all persons name with a matched date of birth.
}
*/
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    string dateOfBirth;

    Person() {
        name = "";
        dateOfBirth = "";
    }

    Person(string name, string dateOfBirth) {
        this->name = name;
        this->dateOfBirth = dateOfBirth;
    }
};

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    cin.ignore();
    Person* people = new Person[n];

    for (int i = 0; i < n; i++) {
        string name, dob;
        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter date of birth (dd/mm/yyyy) of person " << i + 1 << ": ";
        getline(cin, dob);
        people[i] = Person(name, dob);
    }

    string searchDOB;
    cout << "Enter a date of birth to search (dd/mm/yyyy): ";
    getline(cin, searchDOB);

    cout << "Persons with date of birth " << searchDOB << ":\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (people[i].dateOfBirth == searchDOB) {
            cout << people[i].name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No persons found with date of birth " << searchDOB << ".\n";
    }
    delete[] people;
    return 0;
}