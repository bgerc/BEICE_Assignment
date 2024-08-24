#include <iostream>
#include <string>
using namespace std;

class person
{
    string name;
    int year, month, day;

public:
    person(string n = "", int y = 0, int m = 0, int d = 0)
        : name(n), year(y), month(m), day(d) {}

    void input()
    {
        cin.ignore();
        cout << "Enter name : ";
        getline(cin, name);
        cout << "For Date of Birth " << endl;
        cout << "Enter Year : ";
        cin >> year;
        cout << "Enter Month : ";
        cin >> month;
        cout << "Enter Day : ";
        cin >> day;
        cout << endl;
    }

    bool CheckDOB(int &y, int &m, int &d) const
    {
        return (year == y && month == m && day == d);
    }

    void output() const
    {
        cout << name << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of people : ";
    cin >> n;
    cout << endl;

    person *people = new person[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the details for Person : " << i + 1 << endl;
        people[i].input();
    }

    int y, m, d;
    cout << "Enter the date of birth to search " << endl;
    cout << "Enter Year : ";
    cin >> y;
    cout << "Enter Month : ";
    cin >> m;
    cout << "Enter Day : ";
    cin >> d;

    cout << "\nLists of persons with matched date of birth " << endl;
    int SN = 1;
    bool match = false;
    for (int i = 0; i < n; i++)
    {
        if (people[i].CheckDOB(y, m, d))
        {
            cout << SN << ". ";
            people[i].output();
            SN++;
            match = true;
        }
    }
    if (!match)
    {
        cout << "No match found." << endl;
    }

    delete[] people;
    return 0;
}