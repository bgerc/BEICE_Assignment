#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;
    string dateOfBirth;

public:
    Person() 
    {
        //
    }
    Person(string nm, string dob)
    {
        name = nm;
        dateOfBirth = dob;
    }

    string getdata() 
    {
        return name;
    }

    string showdata() 
    {
        return dateOfBirth;
    }
};

int main()
{
    int n;
    cout << "Enter the number of people:";
    cin >> n;

    Person* people = new Person[n];

    for (int i = 0; i<n; i++)
    {
        string name, dob;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter date of birth: ";
        cin >> dob;
        people[i] = Person(name, dob);
    }
    string DOB;
    cout << "DOB to filter: " << endl;
    cin >> DOB;

    bool found = false;
    cout << "Matched Date of Birth: " << DOB << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        if (people[i].showdata() == DOB)
        {
            cout << people[i].getdata() << endl;
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