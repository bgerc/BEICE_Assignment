/*Create a class person with name and date of birth as data members.
Ask the user to enter a date of birth and print all persons name with a matched date of birth.*/

#include<iostream>
#include<string>
using namespace std;
class person
{
    string name;
    string dateofBirth;//yyyy-mm-dd
public:
    person ()
    {}
    person (string Name,string Dob)
    {
       name=Name;
       dateofBirth=Dob;
    }

     void display()
     {

         cout<<"Name="<<name <<" "<< "Date of Birth="<<dateofBirth<<endl;
     }
     string getdob()
     {
         return dateofBirth;
     }

};
int main()
{
    int i,n=4;
     person p[n] = {
        person("Ram ", "2004-04-21"),
        person("Shyao", "2005-04-21"),
        person("Khanal", "2005-04-28"),
        person("M5", "2004-04-21")
    };

    string dob;
    cout<<"Enter date of birth in(yyyy-mm-dd):";
    cin>>dob;
     cout<<"The matching information is:"<<endl;
    bool found=false;
    for(i=0;i<n;i++)
    {
        if(p[i].getdob()==dob)
        {
            p[i].display();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"no matching date of birth";
    }
    return 0;
}
