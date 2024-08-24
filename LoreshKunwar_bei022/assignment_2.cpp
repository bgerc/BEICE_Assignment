#include<iostream>
using namespace std;
class employee
{
    int id;
    char name[30];
    float salary;
    public:
        void getinput()
        {
            cout<<"\nEnter the employee's id,name and salary";
            cin>>id>>name>>salary;
        }
        void display()
        {
            cout<<"\nID:\t"<<id<<"\nName:\t"<<name<<"\nSalary:\t"<<salary;
        }
        friend int search(employee,float);
};
int search (employee E,float sal)
{
    if(E.salary>sal)
    {
        E.display();
        return 1;
    }
    
}
int main()
{
    employee *e;
    int n;
    cout<<"\n enter the number of employee";
    cin>>n;
    e=new employee[n];
    for(int i=0;i<n;i++)
    {
        e[i].getinput();
    }
    float sal;
    cout<<"\nEnter the salary above which you need to search for";
    cin>>sal;
    int R;
    for(int i=0;i<n;i++)
    {
        R=search(e[i],sal);
    }
    if(R!=1)
    {
        cout<<"\n No data found";
    }
    return 0;
}