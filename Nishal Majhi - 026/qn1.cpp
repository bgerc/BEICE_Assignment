#include<iostream>
using namespace std;

class Person{
	private:
		string name;
		int year, month, day;
	public:
		void getInfo();
		void displayMatchedData(int, int , int); 
};

void Person::getInfo()
{
	cout << "Enter the name: "<< endl;
	cin >> name;
	cout << "Enter the date of birth(MM-DD-YYYY): "<< endl;
	cin >> month >> day >> year;
}

void Person::displayMatchedData(int m, int d, int y)
{
	if (m==month && d==day && y==year)
	{
		cout << "Name: "<< name << endl;
		cout << "Date of Birth: "<< month << "-"<< day<< "-"<< year;
	}
}

int main()
{	
	int n,month,day,year;
	cout << "Enter the number of persons: "<< endl;
	cin >> n;
	Person *p1;
	p1 = new Person[n];
	for(int i=0; i<n; ++i)
	{
		p1[i].getInfo();
	}
	cout << "Enter the date of birth(MM-DD-YYYY) which you want to search: "<< endl;
	cin >> month >> day >> year;
	
	for(int i=0; i<n;++i)
	{
		p1[i].displayMatchedData(month,day,year);
	}
	delete[]p1;
	return 0;
 } 
 
