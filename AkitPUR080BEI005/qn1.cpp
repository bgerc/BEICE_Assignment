/*create a class person with name and date of birth as data members.Ask the user to enter 
a date of birth and print all persons  name with matched date of birth*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class person
 {
    string name;
    string dob;
public:
    void getinfo() 
    {
        cout << "Enter the name of the person: ";
        getline(cin, name);
        cout << "Enter the date of birth (in the format YYYY/ MM/ DD): ";
        getline(cin, dob);
    }

    bool matchDob(const string& inputDob)
    {
        return dob == inputDob;
    }

    void showName() 
    {
        cout << name << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    cin.ignore();  // Clear the newline character from the input buffer

    vector<person> people(n);  // Create a vector of n Person objects

    for (int i = 0; i < n; i++) 
    {
        people[i].getinfo();  // Input information for each Person object
    }

    string searchDob;
    cout << "Enter the date of birth to search (in the format YYYY/ MM/ DD): ";
    getline(cin, searchDob);

    cout << "People with the date of birth " << searchDob << " are:" << endl;

    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (people[i].matchDob(searchDob)) 
        {
            people[i].showName();
            found = true;
        }
    }

    if (!found) 
    {
        cout << "No one with that date of birth found." << endl;
    }

    return 0;
}
