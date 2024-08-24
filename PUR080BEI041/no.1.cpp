#include <iostream>
bool x = false;

class Person
{
private:
    std::string m_name{};
    int m_year{};
    int m_day{};
    int m_month{};
public:
     Person (std::string name, int year, int month, int day)
        : m_name{name}, m_year{year}, m_month{month}, m_day{day}
    {
    }

    friend void matchDOB (Person& p, int year, int month, int day);

    void printInfo() {
        std::cout << "Name: " << m_name <<
                     " DOB: " << m_year << "-" << m_month << "-" << m_day 
                     << std::endl;
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
    {"Steve", 2005, 03, 18},
    {"samantha", 2006, 01, 23},
    {"jeremy", 2004, 02, 04},
    {"Simon", 2002, 07, 12},
    {"Ryan", 2009, 01, 30}
};

    int year, month, day;
    std::cout << "Enter year, month and day: ";
    std::cin >> year >> month >> day;

    for (int i = 0; i < 5; i++) {
        matchDOB(p[i], year, month, day);
    }
    if (x == false) {
        std::cout << "No match found!!!" << std::endl;
    }

    return 0;
}
