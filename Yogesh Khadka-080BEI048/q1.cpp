/*Create a class person with name and date of birth as data members.Ask the user to enter a date of birth and print namme with a matched date of birth*/

#include <iostream>
#include <vector>
using namespace std;

class Person {
    string name;
    string dateOfBirth;
public:
    void setName(string n) {
        name = n;
    }

    void setDateOfBirth(string dob) {
        dateOfBirth = dob;
    }

    string getName() const {
        return name;
    }

    string getDateOfBirth() const {
        return dateOfBirth;
    }

    bool compareDateOfBirth(string dobDay, string dobMonth, string dobYear) const {
        string personDay = dateOfBirth.substr(0, 2);
        string personMonth = dateOfBirth.substr(3, 2);
        string personYear = dateOfBirth.substr(6, 4);
    
        return (personDay == dobDay) && (personMonth == dobMonth) && (personYear == dobYear);
    }
};

int main() {
    vector<Person> people;
    int n;

    cout << "Enter the number of people: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Person person;
        string name, dobDay, dobMonth, dobYear;

        cout << "Enter name: ";
        cin >> name;
        person.setName(name);

        cout << "Enter date of birth day: ";
        cin >> dobDay;

        cout << "Enter date of birth month: ";
        cin >> dobMonth;

        cout << "Enter date of birth year: ";
        cin >> dobYear;

        string dob = dobDay + "/" + dobMonth + "/" + dobYear;
        person.setDateOfBirth(dob);

        people.push_back(person);
    }

    string dobDay, dobMonth, dobYear; // Declare the variables here
    cout << "Enter date of birth day to search: ";
    cin >> dobDay;

    cout << "Enter date of birth month to search: ";
    cin >> dobMonth;

    cout << "Enter date of birth year to search: ";
    cin >> dobYear;

    bool foundMatch = false;
    for (const auto& person : people) {
        if (person.compareDateOfBirth(dobDay, dobMonth, dobYear)) {
            cout << "\033[1mName: " << person.getName() << "\033[0m" << endl;
            cout << "Date of Birth: " << person.getDateOfBirth() << endl;
            cout << "Date of Birth matches!" << endl;
            foundMatch = true;
        }
    }

    if (!foundMatch) {
        cout << "No person with the given date of birth found." << endl;
    }

    return 0;
}