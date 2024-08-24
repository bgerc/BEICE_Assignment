#include<iostream>
#include<string>

using namespace std;
class person{
    string dob;
    string name;
    public:
          person()
    {
        name=" ";
        dob=" ";
    }
    person(string dateofbirth, string personname)
    {
        dob=dateofbirth;
        name=personname;
    }
    void setname(string personname)
    {
        name=personname;
    }

    void setdateofbirth(string dateofbirth)
    {
        dob=dateofbirth;
    }
   string getdateofbirth()
   {
    return dob;
   }
   string getname()
   {
    return name;
   }


};
 void searchdateofbirth(person persons[],string searchdob,int count)
    {
        bool found=false;
        for(int i=0;i<count;i++)
        {
            if(persons[i].getdateofbirth()==searchdob)
            {
                cout<<"people withe same date as given date"<<endl;
                cout<<"name:"<<persons[i].getname()<<endl;
                found==true;

            }
        }
        if(found)
        {
            cout<<"person with that birth date not found"<<endl;
        }


    }
int main()
{
    person persons[100];
    int count=0;
    string personname;
    string dateofbirth;
    string searchdob;
    while(count<100)
    {
        cout<<"enter the name(or type 'done' to end and search name)"<<endl;
        getline(cin,personname);
        if(personname=="done")break;
        cout<<"enter the date of birth(yyyy-mm-dd)"<<endl;
        getline(cin,dateofbirth);
        persons[count].setname(personname);
        persons[count].setdateofbirth(dateofbirth);
        count ++;
    }
    cout<<"enter the date od birth to search(yyyy-mm-dd)"<<endl;
    getline(cin,searchdob);
    searchdateofbirth( persons,searchdob,count);
return 0;
}
