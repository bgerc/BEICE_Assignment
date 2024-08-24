#include<iostream>
using namespace std;
class Employee
{
    private:
    string name;
    int id;
    double salary;
    public:
    void getValue();
    void displaygreatersalary(double);

};
void Employee::getValue()
{
    cout<<"\nEnter your ID  : ";
    cin>>id;
    cout<<"Enter your Name: ";
    cin>>name;
    cout<<"Enter your Salary: ";
    cin>>salary;

}
void Employee::displaygreatersalary(double s)
{
    if(s<salary)
    {
        cout<<"--------------------------"<<endl;
        cout<<"Name:\t"<<name<<endl;
        cout<<"ID  : \t"<<id<<endl;
        cout<<"Salary: \t"<<salary<<endl;
        cout<<"--------------------------"<<endl<<endl;
       
    }


}
int main()
{
    
    int n,salary;
    cout<<"\nEnter the number of Employee: ";
    cin>>n;

    Employee *E1;
    E1=new Employee[n+1];
    for(int i=0;i<n;i++)
    {
        E1[i].getValue();
    }
    cout<<"\nEnter salary:";
    cin>>salary;
    for(int i=0;i<n;i++)
    {
        E1[i].displaygreatersalary(salary);
    }
    delete[]E1;
    return 0;
    
}