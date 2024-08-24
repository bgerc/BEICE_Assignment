#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int day, month, year;

public:
    
    Person() : name(""), day(0), month(0), year(0) {}

    
    Person(const string &name, int day, int month, int year) 
        : name(name), day(day), month(month), year(year) {}


    void input()
    {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter date of birth (day month year): ";
        cin >> day >> month >> year;
        cin.ignore();  
    }

    
    bool hasMatchingDOB(int otherDay, int otherMonth, int otherYear) const
    {
        return (day == otherDay && month == otherMonth && year == otherYear);
    }

    
    void output() const
    {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of persons you want to record: ";
    cin >> n;
    cin.ignore();  

    if (n <= 0)
    {
        cout << "Invalid number of persons." << endl;
        return 1;
    }

    Person *persons = new Person[n];

    
    for (int i = 0; i < n; ++i)
    {
        cout << "Person " << i + 1 << ":" << endl;
        persons[i].input();
        cout << endl;
    }

    
    int filterDay, filterMonth, filterYear;
    cout << "Enter the date of birth to filter (day month year): ";
    cin >> filterDay >> filterMonth >> filterYear;

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (persons[i].hasMatchingDOB(filterDay, filterMonth, filterYear))
        {
            cout << endl;
            persons[i].output();
            count++;
        }
    }

    if (count == 0)
    {
        cout << "No persons found with the matching date of birth." << endl;
    }
    else
    {
        cout << "Total matching persons: " << count << endl;
    }

    delete[] persons;  
    return 0;
}
