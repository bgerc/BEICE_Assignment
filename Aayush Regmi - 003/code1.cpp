//Assignment 1
#include<iostream>
#include<string>
using namespace std;

class person
{
    string name,DOB;
    public: 
    person(const string& n='\0' , const string& dob='\0')
    {
        name=n;
        DOB=dob;
    }
    string get_name() const
    {
        return name;
    }
    string get_date() const
    {
        return DOB;
    }
};

int main()
{
    const int Max_persons=100;
    person people[Max_persons];

    int n;
    cout<<"Enter the number of person: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name,dob;
        cout<<"Enter name of person " <<i+1<<":"<<endl;
        cin>>name;

        cout<<"Enter date of birth for person "<<i+1<<":"<<endl;
        cin>>dob;
        people[i]=person(name,dob);
    }
    string user_date;
    cout<<"Enter date of birth (YYYY-MM-DD) :";
    cin>>user_date;
    
    bool found = false;
    
    for(int i=0;i<n;i++)
    {
        if(people[i].get_date() == user_date)
        {
            cout<<people[i].get_name();
            found = true;
        }
        
        if(!found)
        {
            cout<<"No match found.";
        }
        
        return 0;
    }
}