#include <iostream>
using namespace std;
class person
{
    char name[30];
    int year;
    int month;
    int day;

public:
    void getinput()
    {
        cout << "\nEnter the person's name and date of birth";
        cin >> name >> year >> month >> day;
        if (day > 30)
        {
            month = month + 1;
            day = day - 30;
        }
        if (month > 12)
        {
            year = year + 1;
            month = month - 12;
        }
    }
    void display()
    {
        cout << "\nName:\t" << name << "\nDate of birth" << year << "/" << month << "/" << day;
    }
    friend int search(person, int, int, int);
};
int search(person P, int y, int m, int d)
{

    if (P.year == y)
    {
        if (P.month == m)
        {
            if (P.day == d)
            {
                P.display();
                return 1;
            }
        }
    }
}
int main()
{
    person *p;
    int n;
    cout << "\nplease enter the number of person";
    cin >> n;
    p = new person[n];
    for (int i = 0; i < n; i++)
    {
        p[i].getinput();
    }
    cout << "\nEnter the date of birth you want to search for year/month/day";
    int y, m, d;
    cin >> y >> m >> d;
    int R;
    for (int j = 0; j < n; j++)
    {
        R = search(p[j], y, m, d);
    }
    if (R != 1)
    {
        cout << "\nData not found";
    }
    delete[] p;
    return 0;
}