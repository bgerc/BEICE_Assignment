#include<iostream>
#include<string>
using namespace std;

class Person
{
    char name[30];
    string dob;
    public:
    void getName()
    {
        cout<<"Enter name of person: ";
        cin>>name;
    }
    void getDOB()
    {
        cout<<"Enter date of birth (DD/MM/YYYY): ";
        cin>>dob;
    }
    bool checkDOB(string d)
    {
        if(dob==d)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void displayName()
    {
        cout<<name<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter number of persons: ";
    cin>>n;

    Person *p=new Person[n];
    for(int i=0;i<n;i++)
    {
        p[i].getName();
        p[i].getDOB();
    }
    string date;
    cout<<"Enter date of birth to search";
    cin>>date;
    int count=0;
    cout<<"The persons with this date of birth are: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(p[i].checkDOB(date))
        {
            p[i].displayName();
            count++;
        }
    }
    if(count==0)
    {
        cout<<"No person found with this date of birth"<<endl;
    }
    delete []p;
    return 0;
}