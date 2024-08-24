#include<iostream>
using namespace std;

class person
{
    int year;
    int month; 
    int day;
public:
    void getInput()
    {
        cout << "Enter the year, month, and day: ";
        cin >> year >> month >> day;
    }

    bool check(int y, int m, int d)
    {
        return (year == y && month == m && day == d);
    }

    void display()
    {
        cout << "Matched date: " << year << "/" << month << "/" << day << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of people you wish to search for: ";
    cin >> n;

    person *p = new person[n];

    for (int i = 0; i < n; i++)
    {
        p[i].getInput();
    }

    int y, m, d;
    cout << "Enter the date (year/month/day): ";
    cin >> y >> m >> d;

    bool s = false;
    for (int j = 0; j < n; j++)
    {
        if (p[j].check(y, m, d))
        {
            p[j].display();
            s = true;
        }
    }

    if (! s)
    {
        cout << "No matching date found." << endl;
    }

    delete[] p;
    return 0;
}
