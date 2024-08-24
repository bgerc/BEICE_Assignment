#include <iostream>
#include <cstring>

using namespace std;

class employee
{
int emp_id,emp_salary;
string emp_name;
public:
void get()
{
cout << "enter the employee id:" << endl;
cin >> emp_id;
cout << "enter the employee name:" << endl;
cin >> emp_name;
repeat:
cout << "enter the employee salary:" << endl;
cin >> emp_salary;
if (emp_salary<25000)
{
cout << "=================================" << endl;
cout << "salary must be greater than 25000" << endl;
cout << "=================================" << endl;
goto repeat;
}
}
void put()
{
cout << " employee id:"<<emp_id << endl;
cout << "employee name:" <<emp_name<< endl;
cout << "employee salary:" << emp_salary<< endl;
}
};
int main()
{
employee e1;
e1.get();
cout <<  endl;
e1.put();
return 0;
}