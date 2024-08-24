#include<iostream>
#include<cstring>
using namespace std;

class person
{
    string name;
    string dob;

    public:


    void getdata()
    {
        cout<<"enter name:"<<endl;
        cin>>name;
       
        cout<<"enter date of birth(yy-mm-dd):"<<endl;
        cin>>dob;
    }

    void showdata() const
    {
        cout << "Name: " << name << endl;
        
    }

    string getdob() const
    {
        return dob;
    }
};

int main()
{
    int n;
    string searchdate;
    bool f;
    int i;
    

    cout<<"Enter no of persons:"<<endl;
    cin>>n;

    person p[n];

    for (i=0;i<n;i++)
    {
        cout<<"Enter details of person "<<(i+1)<<":"<<endl;
        p[i].getdata();
    }

    cout<<"Enter date of birth to search:"<<endl;
    cin>>searchdate;
    
    
    cout<<"Persons with date of birth "<<searchdate<<":"<<endl;

    f=false;

    for (i=0;i<n;i++)
    {
        if(p[i].getdob() ==searchdate)
        {
            p[i].showdata();
            f = true;

        }

        

    }

    
    if(!f)
        {
            cout<<"No person found with date of birth "<<searchdate<<endl;

        }

    return 0;




}
