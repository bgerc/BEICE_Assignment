#include<iostream>
using namespace std;

class Employee{
	int id;
	char Name[24];
	float user_spy_amt=30000.0;
	float Salary;
	public:
		void getData(){
		cout<<"Enter the data of the employee"<<endl;
		cout<<"Enter the id :"<<endl;
		cin>>id;
		cout<<"Enter the name :"<<endl;
		cin>>Name;
		cout<<"Enter the salary :"<<endl;
		cin>>Salary;
		}
		void display(){
			if(Salary>user_spy_amt){
			
				cout<<"the details of the employee= :"<<endl;
				cout<<"The name of employee:"<<Name<<endl;			
				cout<<"The id of employee:"<<id<<endl;			
				cout<<"The salary of employee:"<<Salary<<endl;			
		
		}
		else{
			cout<<"the requirement doesn't meet";
		}
		
		}
};

int main(){
	Employee e;
	e.getData();
	e.display();
	return 0;
}
