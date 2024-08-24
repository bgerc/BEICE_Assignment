#include <iostream>
using namespace std;
bool x = false;

class Person
{
private:
    string m_name{};
    int m_year{};
    int m_day{};
    int m_month{};
public:
     Person (string name, int year, int month, int day)
        : m_name{name}, m_year{year}, m_month{month}, m_day{day}
    {
    }

    friend void matchDOB (Person& p, int year, int month, int day);

    void printInfo() {
        cout << "Name: " << m_name <<
                     " DOB: " << m_year << "-" << m_month << "-" << m_day 
                     << endl;
    }
};

void matchDOB (Person& p, int year, int month, int day) {
    if (year == p.m_year && month == p.m_month && day == p.m_day) {
        p.printInfo();
        x = true;
    }
}

int main()
{
    Person p[5] = {
    {"john", 2005, 03, 12},
    {"rita", 2004, 02, 15},
    {"shiru", 2004, 02, 10},
    {"Samy", 2003, 04, 5},
    {"nancy", 2003, 03, 7}
};
    int year, month, day;
    cout << "Enter year, month and day: ";
    cin >> year >> month >> day;

    for (int i = 0; i < 5; i++) {
        matchDOB(p[i], year, month, day);
    }
    if (x == false) {
        cout << "No match found!" << endl;
    }
    return 0;
}
