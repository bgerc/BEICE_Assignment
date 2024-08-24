#include <iostream>
#include <cstring>
using namespace std;

class PERSON {
private:
    string name;
    int year;
    int month;
    int day;

public:
    PERSON() : name(""), day(0), month(0), year(0) {}

    void getdata()
     {
        cout << "Enter your name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter your date of birth (DD MM YYYY): ";
        cin >> day >> month >> year;

        if (year < 1900) 
        {
            cout << "Invalid year... Please try again..." << endl;
            day = month = year = 0; 
        } 
        else if (month < 1 || month > 12) 
        {
            cout << "Invalid month... Please try again..." << endl;
            day = month = year = 0; 
        } else if (day < 1 || day > 31) 
        {
            cout << "Invalid day... Please try again..." << endl;
            day = month = year = 0; 
        }
    }

    bool isMatchingDOB(int d, int m, int y) const 
    {
        return (d == day && m == month && y == year);
    }

    void displaydata()  
    {
        if (day != 0 && month != 0 && year != 0) 
        { 
            cout << "Name: " << name << endl;
            cout << "Date of Birth: " << day << "/" << month << "/" << year << endl;
        }
    }
};

int main() 
{
    int n, day, month, year;
    cout << "Enter the no of persons: ";
    cin >> n;

    PERSON* p = new PERSON[n];

    for (int i = 0; i < n; i++) {
        p[i].getdata();
    }

    cout << "Enter the date of birth to match (DD MM YYYY): ";
    cin >> day >> month >> year;

    if (year < 1900) 
    {
        cout << "Invalid year... Please try again..." << endl;
    } else if (month < 1 || month > 12) {
        cout << "Invalid month... Please try again..." << endl;
    } else if (day < 1 || day > 31) {
        cout << "Invalid day... Please try again..." << endl;
    } else {
        bool matchFound = false;
        for (int i = 0; i < n; i++) {
            if (p[i].isMatchingDOB(day, month, year)) {
                p[i].displaydata();
                matchFound = true;
            }
        }
        if (!matchFound) {
            cout << "No person has the date of birth " << day << "/" << month << "/" << year << "." << endl;
        }
    }

    delete[] p;
    return 0;
}
