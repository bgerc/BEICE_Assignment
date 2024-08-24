// Question no 2

#include<iostream>
using namespace std;

class Employee{
	private:
		int id;
		string name;
		int salary;
	public:
		void getInfo();
		void display(int);
};

void Employee::getInfo()
{
	cout << "Enter the id: "<< endl;
	cin >> id;
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the salary: ";
	cin >> salary;
}

void Employee::display(int s) 
{
	if (s<salary)
	{
		cout << "Id: " << id << endl;
		cout << "Name: "<< name << endl;
		cout << "Salary: " << salary;
	}
}

int main()
{
	int n,baseSalary;
	cout << "Enter the number of employees: "<< endl;
	cin >> n;
	Employee *e;
	e = new Employee[n];
	for (int i=0; i<n; ++i)
	{
		e[i].getInfo();
	}
	
	cout << "Enter the minimum salary to display: " << endl;
	cin >> baseSalary;
	
	for (int i=0; i<n; ++i)
	{
		e[i].display(baseSalary);
	}
	
	delete[]e;
	return 0;
}