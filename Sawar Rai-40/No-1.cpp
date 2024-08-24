#include <iostream>
#include <string>
using namespace std;

class person {
    string name;
    int year;
    int month;
    int day;

public:
    void getValue() 
    {
        cout << "\nEnter the person's name: ";
        cin >> name;
        cout << "Enter the date of birth (year month day): ";
        cin >> year >> month >> day;
    }

    void print() const 
    {
        cout<<"\n-----------------------------------------"<<endl;
        cout << "Name:\t" << name << "\nD.O.B:\t" << year << "/" << month << "/" << day << endl;
        cout<<"-----------------------------------------"<<endl;
    }

    friend int search(const person&, int, int, int);
};

int search(const person& P, int y, int m, int d) {
    if (P.year == y && P.month == m && P.day == d) {
        P.print();
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cout << "\nEnter the number of persons: ";
    cin >> n;

    person* p = new person[n];
    for (int i = 0; i < n; i++) {
        p[i].getValue();
    }

    cout << "\nEnter the date of birth you want to search for (year month day): ";
    int y, m, d;
    cin >> y >> m >> d;

    bool found = false;
    for (int j = 0; j < n; j++) {
        if (search(p[j], y, m, d)) {
            found = true;
         
        }
    }
    if (!found) {
        cout << "\nGiven D.O.B is not found!" << endl;
    }

    delete[] p;
    return 0;
}
