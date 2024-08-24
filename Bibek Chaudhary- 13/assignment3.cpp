#include<iostream>
using namespace std;

class Library{
	char bookTitle[25];
	char author[25];
	int numofCopies=0;
	int copies;
	public:
		void addNewBook(){
			cout<<"Enter the name of the book "<<endl;
			cin>>bookTitle;
			cout<<"Enter the author of the book "<<endl;
			cin>>author;
			cout<<"Enter the number of copies of the book "<<endl;
			cin>>copies;
			numofCopies+=copies;
			
		}
		void issueBook(){
			int issuebook;
			cout<<"Enter the name of the book "<<endl;
			cin>>bookTitle;
			cout<<"Enter the author of the book "<<endl;
			cin>>author;
			cout<<"Enter the number of book issued"<<endl;
			cin>>issuebook;
			if(issuebook>numofCopies){
				cout<<"Not available";
			}
			else{
				cout<<"Your books has been issued";
			}
			numofCopies=numofCopies-issuebook;
			
		}
			void returnBook(){
			int returnbook;
			cout<<"Enter the name of the book "<<endl;
			cin>>bookTitle;
			cout<<"Enter the author of the book "<<endl;
			cin>>author;
			cout<<"Enter the number of book returned"<<endl;
			cin>>returnbook;
			cout<<"Your books has been returned";
			numofCopies=numofCopies+returnbook;
			
		}
		void display()
		{
			
			cout<<"the number of copies is"<<numofCopies;
		}
};

int main(){
	int x;
	do{
	
	
	cout<<"enter the value of x"<<endl;
	cout<<"1.addnewbook"<<endl;
    cout<<"2.issuebook"<<endl;
    cout<<"3.returnbook"<<endl;
    cout<<"4.exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>x;

	Library l;
	switch(x){
		case 1:
			l.addNewBook();
			break;
		case 2:
			l.issueBook();
			break;
		case 3:
			l.returnBook();
			break;
			case 4:
				cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
			
	}
	l.display();
}
while(x != 4);
	
	return 0;
	
}


