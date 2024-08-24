#include<iostream>
using namespace std;

class employee
{
    int id;
    char name[20];
    int sal;
    public:
    void input()
    {
cout<<"Enter id of the employee:"<<endl;
cin>>id;
cout<<"Enter the name of the employee: "<<endl;
cin>>name;
cout<<"Enter the salary of an empployee: "<<endl;
cin>>sal;
    }
    bool operator > (employee e)
    {
        if(sal>e.sal)
        {
            return true;
        }
        else
        return false;
    }
    void display()
    {
        cout<<"The id is:"<<id<<endl;
        cout<<"Name is:" <<name<<endl;
        cout<<"Salary is:"<<sal<<endl;
    }
    };

    int main()
    {
        employee e1,e2;
        e1.input();
        e2.input();
        if(e1>e2) e1.display();
            // cout<<"The salary is:"<<endl;
            // e1.display();
        return 0;

    }
