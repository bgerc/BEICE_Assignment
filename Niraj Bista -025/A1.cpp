#include<iostream>
#include<stdlib.h>
using namespace std;

class person
{ 
    char name[50];
    int age;
    int year,month,day;
    public:
    void in()
    {
        cout<<"Enter the name of the person: ";
        cin.ignore();
        cin.getline(name,50);
        cout << "Age: ";
        cin >> age;
        cout << "Date of Birth:" << endl<<"Year: ";
        cin>>year;
        cout << "Month: " ;
        cin>>month;
        cout<<"Date: ";
        cin >>day;
    }
    void show()
    {
        
        cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"Date of BIrth:";
        cout<<year<<"/"<<month<<"/"<<day<<endl;
    }
    bool operator==(person &p)
    {
        if( (year==p.year) && ( month==p.month) && (day==p.day))
        {
            return true;
        }
        else return false;
    }
};
int main()
{
    int n,count=0;
    cout<<"Enter the no of person to enter: ";
    cin>>n;
    person *p=new person[n];
    person *same_dob=new person[n];
    
    cout<<"Enter the detail of each person: "<<endl;
    for(int i=0;i<n;i++)
    {
        p[i].in();
    }

    same_dob[count++]=p[0];

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i]==p[j])
            {
                //same_dob[count++]=p[i];
                same_dob[count++]=p[j];
            }
        }
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"                SOME DOB                   "<<endl;
    cout<<"--------------------------------------------"<<endl;
    if(count==1)
    {
        system("clear");
        cout<<"No perosn with same data type: "<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }
    else
    {
        system("clear");
        cout<<"Same dob: "<<endl;
        for(int i=0;i<count;i++)
        {
        same_dob[i].show();
        }
    }
    delete[] p;
    delete[] same_dob;
    return 0;
}