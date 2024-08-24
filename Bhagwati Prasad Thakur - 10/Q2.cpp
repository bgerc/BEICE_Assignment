#include<iostream>
using namespace std;
class Employee
{
    string name;
    int id;
    float salary;
    public:
    Employee(string name="someone",int id=0,float salary=0)
    {
        this->name=name;
        this->id=id;
        this->salary=salary;
    }
    void display();
    float sendSalary();
};
int main()
{
bool isTrue=false;
string name;
int id,Index;
float salary;
cout<<"Enter No of Employe : ";
cin>>Index;
Employee* obj=new Employee[Index];
cout<<"Enter details of \n";
for(int i=0;i<Index;i++)
{
    cout<<"Employe "<<i+1<<": \n";
    cout<<"Name : ";
    cin>>name;
    cout<<"ID : ";
    cin>>id;
    cout<<"Salary : ";
    cin>>salary;
    obj[i]=Employee(name,id,salary);
}
cout<<"Enter Specified Salary : ";
cin>>salary;
for(int i=0;i<Index;i++)
{
    if(obj[i].sendSalary()>=salary)
    {
        isTrue=true;
        obj[i].display();

    }
    else isTrue=false;
}
if(!isTrue)
{
    cout<<"OOPS!!! No Match Found ";
}
}
void Employee::display()
{
    cout<<"Name : "<<name<<endl;
    cout<<"ID : XXPUR00"<<id<<"\n";
    cout<<"Salary : "<<salary<<endl;

}
float Employee::sendSalary()
{
    return salary;
}