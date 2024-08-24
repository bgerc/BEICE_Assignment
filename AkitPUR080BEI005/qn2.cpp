/*Design a class employee with id,name and Salary as data members.Implement functions 
to input employee data and display employees who have a Salary greater than a user specified amount*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Employee
{
    int id;
    char name[50];
    float Salary;
    public:
    void getinfo()
    {
        cout<<"Enter the name of the employee:"<<endl;
        cin>>name;
        cout<<"Enter the id of the employee:"<<endl;
        cin>>id;
        cout<<"Enter the salary of the employee:"<<endl;
        cin>>Salary;
    }
    bool  highsalary(const int& inputsalary)
    {
        return Salary>inputsalary;
    }
    
    void showName()
    {
        cout<<"ID:"<<id<<",Name:"<<name<<",Salary:"<<Salary<<endl;
    }
    
};

int main()
{
   int e;
   cout<<"Enter the number of employees"<<endl;
   cin>>e;

    vector<Employee> salary(e);

    for(int i=0;i<e ;i++)
    {
        salary[i].getinfo();
    }

    int searchsalary;
    cout<<"Enter the threshold salary:"<<endl;
    cin>>searchsalary;

    bool found=false;
    for (int i = 0; i < e; i++) 
    {
        if (salary[i].highsalary(searchsalary))  
        {
            salary[i].showName();
            found = true;
        }
    }
   if (!found)
    {
        cout << "No employee found with salary greater than " << searchsalary << endl;
    }




return 0;
}