#include<iostream>
using namespace std;


class Employee
{
    int id;
    char name[30];
    float salary;
    public:
    void getEmplyeeData()
    {
        cout<<"Enter employee id: ";
        cin>>id;
        cout<<"Enter employee name: ";
        cin>>name;
        cout<<"Enter employee salary: ";
        cin>>salary;
    }
    void displayEmployee()
    {
        cout<<endl<<"Name: "<<name<<endl;
        cout<<"id: "<<id<<endl;
    }
    float returnSalary()
    {
        return salary;
    }
};

int main()
{
    Employee e[100];
    int n;
    cout<<"How many employees? ";
    cin>>n;
    cout<<"Enter the employee details: "<<endl;
    for(int i=0;i<n;i++)
        e[i].getEmplyeeData();
    float check;
    cout<<"Enter salary to check: ";
    cin>>check;
    float salary;
    cout<<"The details are: ";
    for(int i=0;i<n;i++)
    {
        salary=e[i].returnSalary();
        if(salary>check)
        e[i].displayEmployee();
    }
    
    return 0;
}