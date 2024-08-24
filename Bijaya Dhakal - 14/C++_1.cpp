#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    int i;
    string name;
    string dob;
};

int main() {
    Person persons[12];

    persons[0].name = "Bijay Dhakal";
    persons[0].dob = "2000-03-25";
    persons[1].name = "Hari Rai";
    persons[1].dob = "2001-01-12";
    persons[2].name = "Rahul Shrestha";
    persons[2].dob = "2002-09-08";
    persons[3].name = "Tirthankar Khatiwada";
    persons[3].dob = "2003-05-20";
    persons[4].name = "Kamal Dhakal";
    persons[4].dob = "2004-11-15";
    persons[5].name = "Kalpana Roila";
    persons[5].dob = "2005-07-10";
    persons[6].name = "Sushant Yadav";
    persons[6].dob = "2006-04-18";
    persons[7].name = "Bishab Shakya";
    persons[7].dob = "2007-08-30";
    persons[8].name = "Suraj Jaiswal";
    persons[8].dob = "2008-12-05";
    persons[9].name = "Samman Khanal";
    persons[9].dob = "2009-10-22";
    persons[10].name = "Prasoon Dahal";
    persons[10].dob = "2010-06-28";
    persons[11].name = "Anmol Katwal";
    persons[11].dob = "2011-09-14";

    string input_dob;
    cout << "Enter a birth date (YYYY-MM-DD): ";
    cin >> input_dob;

    for (int i = 0; i <=12; i++) {
        if (persons[i].dob == input_dob) {
            cout << "Person's name: " << persons[i].name << endl;
            break;
        }
    }
return 0;
}
