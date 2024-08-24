/*Design a class Employee with id, name and salary as data members. Implement functions to input 
employee data and display employees who have a salary greater than user-defined amount.*/

#include<iostream>
using namespace std;
class employee{
    private:
    int id;
    char name[50];
    int salary;

    public:
    void getinput()
    {
        cout<<"Enter employee's details: "<<endl;
        cout<<"ID: ";
        cin>>id;
        cout<<"Name: ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"Salary: ";
        cin>>salary;
    }

    int sal()
    {
        return salary;
    }

    void show()
    {
        cout<<endl<<id<<"\t"<<name;
    }

};

int main() {
    system("cls");
    int n;
    cout<<"Enter the number of employees :";
    cin>>n;
    employee* e= new employee [n];

    for(int i=0;i<n;i++)
    {
        e[i].getinput();
    }

    int salary;
    cout<<"Enter the minimum salary: ";
    cin>>salary;

    cout<<"The person with more salary than minimum salary:";
    
    cout<<"ID "<<"\t"<<"Name ";
    for(int i=0;i<n;i++)
    {
        if(e[i].sal()>salary)
        {
            e[i].show();
        }
    }

    
    return 0;
}