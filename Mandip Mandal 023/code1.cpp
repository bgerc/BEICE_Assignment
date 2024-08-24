// Question no 1

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    string dateOfBirth;

public:
    Person() {}
    Person(string n, string dob)
    {
        name = n;
        dateOfBirth = dob;
    }

    string getName() const
    {
        return name;
    }

    string getDateOfBirth() const
    {
        return dateOfBirth;
    }
};

int main()
{
    int numPeople;
    cout << "Enter the number of people you want to record: ";
    cin >> numPeople;

    Person* people = new Person[numPeople];

    for (int i = 0; i < numPeople; ++i)
    {
        string name, dob;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter date of birth: ";
        cin >> dob;
        people[i] = Person(name, dob);
    }

    string searchDob;
    cout << "DOB to filter: " << endl;
    cin >> searchDob;

    bool found = false;
    cout << "Matched Date of Birth: " << searchDob << ":" << endl;
    for (int i = 0; i < numPeople; ++i)
    {
        if (people[i].getDateOfBirth() == searchDob)
        {
            cout << people[i].getName() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No people found with the given date of birth." << endl;
    }

    delete[] people;

    return 0;
}