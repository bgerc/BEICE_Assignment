/*Design a class Employee with id, name, and salary as data members.
Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.*/

#include<iostream>
#include<string>
using namespace std;
class Employee
{
    int id;
    string name;
    float salary;
public:
   Employee()
    {}
    void getinfo()
    {
        cout<<"Enter the ID:";
        cin>>id;
        cin.ignore();
        cout<<"Enter the name:";
        getline(cin,name);
        cout<<"Enter the salary:";
        cin>>salary;
    }
    void showinfo()
    {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
    float getsalary()
    {
        return salary;
    }
};
int main()
{
    int n,i;
    cout<<"how many employees?"<<endl;
    cin>>n;
    Employee* e = new Employee[n];
    for(i=0;i<n;i++)
    {
    cout<<"Entering data for employee"<<(i+1)<<endl;
    e[i].getinfo();
    cout<<endl;
    }
    float amount;
    cout<<"Enter the amount to be compared:";
    cin>>amount;
    cout<<"Employees having salary greater than "<<amount<<":"<<endl;
    bool found=false;
    for(i=0;i<n;i++)
    {
        if(e[i].getsalary()>amount)
        {
            e[i].showinfo();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"NO EMPLOYEE HAVE GREATER SALARY THAN"<<amount<<".";
    }
    delete[] e;
    return 0;
}
