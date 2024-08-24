#include <iostream>
#include <string.h>
using namespace std;

class employee
{
  int id;
  string name;
  double salary;

  public:
  void getdata()
  {
    cout<<"enter the data of employee"<<endl;
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter salary"<<endl;
    cin>>salary;
    cout<<"enter employee id"<<endl;
    cin>>id;
  }

  void display()
  {
    cout<<"employee name"<<name<<endl;
    cout<<"enter salary"<<salary<<endl;
    cout<<"enter id"<<id<<endl;
  }

bool hashighersalarythan(double threshold)
{
       return salary>threshold;
}
};

int main()
{
    int n,i;
    cout<<"enter number";
    cin>>n;

    employee emp[n];

    for(i=0; i<n; i++)
    {
        cout<<"enter the details of employee"<<i +1<<":"<<endl;
        emp[i].getdata();
    }
    double threshold;
    cout<<"enter the  minimum salary to display";
    cin>>threshold;

    cout<<"employee with salary greater than threshold is"<<threshold<<endl;
     
    for(i=0; i<n; i++)
    {
        if(emp[i].hashighersalarythan(threshold))
        {
            emp[i].display();
            cout<<endl;
        }
    }
    return 0;
}