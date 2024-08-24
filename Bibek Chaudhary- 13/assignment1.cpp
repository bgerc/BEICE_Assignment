#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    string dob; 
public:
   
    void setData(string n, string d) {
        name = n;
        dob = d;
    }

    
    string getDOB() {
        return dob;
    }

    
    void display() {
        cout << "Name: " << name << ", Date of Birth: " << dob << endl;
    }
};

int main() {
    int n;
    string name, dob, searchDob;

    cout << "Enter the number of persons: ";
    cin >> n;
    cin.ignore();  

    Person people[100];  

    
    for (int i = 0; i < n; i++) {
        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter date of birth of person " << i + 1 << " (DD/MM/YYYY): ";
        getline(cin, dob);
        people[i].setData(name, dob);
    }

    
    cout << "\nEnter date of birth to search for (DD/MM/YYYY): ";
    getline(cin, searchDob);

   
    cout << "\nPersons with date of birth " << searchDob << ":\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (people[i].getDOB() == searchDob) {
            people[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "No person found with the date of birth " << searchDob << endl;
    }

    return 0;
}

