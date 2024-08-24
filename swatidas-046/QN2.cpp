#include <iostream>
using namespace std;

class employee
{
    int id;
    char name[30];
    double salary;
    public:
    void inputData()
    {
    cout<< "Enter id , name and salary "<<endl;
    cin>>id>> name>>salary;
    }
    void display()
    {
    cout<<" ID "<<id<<" Name "<<name<<" Salary  "<<salary;
    }
    double getSal()
    {
        return salary;
    }
};
int main()
{
    int n;
    cout<<"Enter number of employees "<<endl;
    cin>>n;
    employee *e =new employee[n] ;
    double amount;
    cout<<"Enter the amount "<<endl;
    cin>>amount;
    for(int i= 0; i<n;i++)
    {
    e[i].inputData();
    }
    cout<<"The employees with greater salary than "<<amount<<" are "<<endl;
    for(int j=0; j<n;j++)
    {
        if(e[j].getSal()>amount){
            e[j].display();
        }
    }
    delete[] e;
    return 0;
}
