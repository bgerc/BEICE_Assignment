#include<iostream>
using namespace std;
class Employee
{
    private:
    string name;
    int id;
    double salary;
    public:
    void getdata();
    void displaydatawithgreatersalary(double);

};
void Employee::getdata()
{
    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<<"Enter your ID  : "<<endl;
    cin>>id;
    cout<<"Enter your salary: "<<endl;
    cin>>salary;

}
void Employee::displaydatawithgreatersalary(double s)
{
    if(s<salary)
    {
        cout<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID  : "<<id<<endl;
        cout<<"salary: "<<salary<<endl;

        cout<<endl<<endl;
    }


}
int main()
{
    
    int n,salary;
    cout<<"Enter the number of Employee: "<<endl;
    cin>>n;
    Employee *E1;
    E1=new Employee[n+1];
    for(int i=0;i<n;i++)
    {
        E1[i].getdata();
    }
    cout<<"Enter salary:"<<endl;
    cin>>salary;
    for(int i=0;i<n;i++)
    {
        E1[i].displaydatawithgreatersalary(salary);
    }
    delete[]E1;
    return 0;
    
}