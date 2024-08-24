/* Assignment
    
    Create a class person with name and date of birth as data members. 
    Ask the user to enter a date of birth and print all persons name with a matched date of birth.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


class Person
{
    char *name;
    int year;
    int month;
    int day;
    public:
        Person()
        {}
        Person(char *a, int y, int m, int d) 
        {
            name = new char[strlen(a) + 1];
            strcpy(name, a);
            year = y;
            month = m;
            day = d;
        }
        bool Compare(int y, int m, int d)
        {
            if (year == y && month == m && day == d)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void output()
        {
            cout << "Name: " << name << endl << "Date of Birth(YYYY:MM:DD): " << setw(4) << setfill('0') << year % 10000 << "::" << setw(2) << setfill('0') << month % 100 << "::" << setw(2) << setfill('0') << day % 100 << endl;
        }
        ~Person()
        {
            delete[] name;
        }
};

int main()
{
    int n;
    cout << "Enter the number of person's you want to record: " << endl;
    cin >> n;
    Person *p = new Person[n];
    char name[100];
    int year, month, day;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ") Enter name: ";
        cin.ignore();
        cin.getline(name, 100);
        cout << "   Enter " << name << "'s year of birth: ";
        cin >> year;
        cout << "   Enter " << name << "'s month of birth: ";
        cin >> month;
        cout << "   Enter " << name << "'s day of birth: ";
        cin >> day;
        p[i] = Person(name, year, month, day);
        cout << endl;
    }
    cout << endl << endl;
    cout << "Enter the date of birth you want to filter(YY:MM:DD): ";
    cin >> year >> month >> day;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].Compare(year, month, day))
        {
            cout << endl << endl;
            p[i].output();
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No matching date.";
    }
    else 
    {
        cout << "Total filter: " << count;
    }
    delete [] p;
    return 0;
}