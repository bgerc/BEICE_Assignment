/*Create a class person with name and date of birth as data members. Ask the user to enter a date of 
birth and print all persons name with a matched date of birth.*/

#include<iostream>
using namespace std;
class person
{
    private:
    char name[100];
    int db;

    public:
    void getinput()
    {
        cin.ignore();
        cout<<"Enter the person's name: ";
        cin.getline(name,100);
        cout<<"Enter date of birth (in AD): ";
        cin>>db;
    }
    int dob()
    {
        return db;
    }
    void show()
    {
        cout<<endl<<"Name: "<<name;
    }

};

int main() {
    system("cls");
    int n;
    cout<<"Enter the number of person: ";
    cin>>n;
    person* p = new person[n];

    for(int i=0;i<n;i++)
    {
        p[i].getinput();
    }

    int dob;
    cout<<"Enter the date of birth you want to see details :";
    cin>>dob;

    cout<<"The person/people with matched dob is/are :";
    for (int i=0;i<n;i++)
    {
        if(p[i].dob()==dob)
        {
            p[i].show();
        }
    }
    delete [] p;
    return 0;
}