#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    string dob;

    Person(string n, string d) : name(n), dob(d) {}
};

int main()
{
    vector<Person> people;
    int num;

    cout << "How many people do you want to enter? ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string name, dob;
        cout << "Enter name of person " << i + 1 << ": ";
        cin >> name;
        cout << "Enter date of birth of person " << i + 1 << " (format DD/MM/YYYY): ";
        cin >> dob;
        people.push_back(Person(name, dob));
    }

    string input_dob;
    cout << "Enter a date of birth to search (format DD/MM/YYYY): ";
    cin >> input_dob;

    bool found = false;
    for (const auto &person : people)
    {
        if (person.dob == input_dob)
        {
            cout << person.name << " has a matching date of birth.\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No persons found with the given date of birth.\n";
    }

    return 0;
}