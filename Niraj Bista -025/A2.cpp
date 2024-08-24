#include<iostream>
#include<stdlib.h>
using namespace std;

class Employee
{
    char name[25];
    int id;
    float salary;
    public:
    void get()
    {
        cout<<"Enter the name of the Employee: ";
        cin.ignore();
        cin.getline(name,25);
        cout<<"ID of the employee: ";
        cin>>id;
        cout<<"Enter the salary of the employee: ";
        cin>>salary;
    }
    void show()
    {
        cout<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Salary: "<<salary<<endl;
    }
    bool operator>=(float &s)
    {
        if(salary>=s) return true;
        else return false;
    }
};
int main()
{
    int n;
    float sal;
    int count=0;
    cout<<"Enter the no of Employee: ";
    cin>>n;
     
    Employee *e=new Employee[n];
    Employee *same=new Employee[n];

    for(int i=0;i<n;i++)
    {
        e[i].get();
    }
    system("clear");
    cout<<"Enter the salary amount to find: ";
    cin>>sal;


    for(int i=0;i<n;i++)
    {
        if(e[i]>=sal)
        {
            same[count++]=e[i];
        }
        else
        {
            continue;
        }
    }

    if(count==0) cout<<"No employee with greater or equal salary to that amount "<<endl;
    else
    {
        cout<<"Employee with salary greater than specified: "<<endl;
        for(int i=0;i<count;i++)
        {
            same[i].show();
        }
    }
    return 0;
}