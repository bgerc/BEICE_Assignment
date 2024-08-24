#include<iostream>
bool isTrue=false;
bool isMatchFound=false;
using namespace std;
class PERSON
{
    string name;
    int year;
    int month;
    int day;
    public:
    PERSON(string name="Variant", int year=2002,int month=5,int day=15)
    {
        this->name=name;
        this->year=year;
        this->month=month;
        this->day=day;
    }
    void compare(int,int,int);
    void showData(int);
};
int main()
{
    string name;
    int index,year,month,day;
    cout<<" Enter No of data you want to enter: ";
    cin>>index;
    PERSON* P=new PERSON[index];
    cout<<"Enter Data for :\n";
    for (int i=0;i<index;i++)
    {
        cout<<"\nPerson "<<i+1<<":\n";
        cout<<"Name : ";
        cin.ignore();
        cin>>name;
        cout<<"Birth Year : ";
        cin>>year;
        cout<<"Birth MOnth : ";
        cin>>month;
        cout<<"Birth Day : ";
        cin>>day;
        P[i]=PERSON(name,year,month,day);
        
    }
    cout<<"Enter Date of birth to be filterd(YYYY MM DD) : ";
    cin>>year>>month>>day;
    for(int i=0;i<index;i++)
    {
        P[i].compare(year,month,day);
        if(isMatchFound)
        {
            cout<<"Match Found !!!\n";
            P[i].showData(i);
        }
        if(!isTrue)
        {
            cout<<"OOPS!!! No Match Found -_-\n";
        }
        
    }

}
void PERSON::showData(int index)
    {
        cout<<"PERSON "<<index+1<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Year : "<<year<<endl;
        cout<<"Month : "<<month<<endl;
        cout<<"Day : "<<day<<endl;
    }
void PERSON::compare(int year,int month,int day)
    {
        if(this->year==year && this->month==month && this->day==day )
        {
            isMatchFound=true;
            isTrue=true;
        }
        else
        {
            isMatchFound=false;

        }
    }
