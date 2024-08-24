#include<iostream>
using namespace std;
class PERRSON
{
    private:
    string name;
    int year,month,day;
    public:
    void getdata();
    void displaydatawithmatcheddob(int, int, int);

};
void PERRSON::getdata()
{
    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<<"Enter your date of birth(DD:MM:YY)"<<endl;
    cin>>day>>month>>year;

}
void PERRSON::displaydatawithmatcheddob(int d,int m, int y)
{
    if(d==day&&m==month&&y==year)
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Date of Birth: "<<day<<"/"<<month<<"/"<<year<<endl;
    }

}
int main()
{

    int n,day,month,year;
    cout<<"Enter the number of persons: "<<endl;
    cin>>n;
    PERRSON *p1;
    p1=new PERRSON[n+1];
    for(int i=0;i<n;i++)
    {
        p1[i].getdata();
    }
    cout<<"Enter the date of birth(DD:MM:YY):"<<endl;
    cin>>day>>month>>year;
    for(int i=0;i<n;i++)
    {
        p1[i].displaydatawithmatcheddob(day, month, year);
    }
    delete[]p1;
    return 0;

}
