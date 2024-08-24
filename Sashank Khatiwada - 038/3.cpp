#include <iostream>

using namespace std;


class Library
{
    int numberofcopies;
    string booktitle;
    string author;
    int bookcount;
   
    

    public:
    Library() : bookcount(0) {}

    

    void addbook()
    {
    
        cout<<"Enter book title:"<<endl;
        cin>>booktitle;

        cout<<"Enter author name:"<<endl;
        cin>>author;

        cout<<"Enter no of copies:"<<endl;
        cin>>numberofcopies;

        bookcount++;
    }

    void issuebook()
    {
    
        bool bookfound;
        int issuedcopies;
       


        cout<<"Enter book title:"<<endl;
        cin>>booktitle;

        cout<<"Enter author name:"<<endl;
        cin>>author;

        cout<<"Enter no of copies to be issued:"<<endl;
        cin>>issuedcopies;

        bookfound=false;
        for(int i=0;i<bookcount;i++)
        {
        
            if (numberofcopies >= issuedcopies) 
            {
            
                    numberofcopies -= issuedcopies;
                    cout << "Book issued successfully." << endl;
            }
            else
            {
                cout << "Not enough copies available to issue." << endl;

            
               bookfound=true;
               break;
            }
        }

        
        if (!bookfound) 
        {
            cout << "Book not found in the library." << endl;
        }
    }
    

    void returnbook()
    {
        bool bookfound;
        int returnedcopies;


        cout<<"Enter book title:"<<endl;
        cin>>booktitle;

        cout<<"Enter author name:"<<endl;
        cin>>author;

        cout<<"Enter  no of copies returned :"<<endl;
        cin>>returnedcopies;

        bookfound=false;

        for(int i=0;i<bookcount;i++)
        {
            numberofcopies += returnedcopies;
            cout << "Book returned successfully." << endl;
            bookfound = true;
            break;
        }

       
        if (!bookfound) 
        {
            cout << "Book not found in the library." << endl;
        }
    }

    void displaybook() const
    {
        cout << "Books available in the library:" << endl;
        for (int i=0;i<bookcount;i++)
        {
            cout<<"Title:"<<booktitle[i]<<endl;
            cout<<"Author:"<<author[i]<<endl;
            cout<<"Copies:"<<numberofcopies<<endl;
        }
    }   

};    


int main()
{
    Library lib;
    int choice;

    while (true) 
    {
        cout << "Library Menu:"<<endl;
        cout << "1. Add Book"<<endl;
        cout << "2. Issue Book"<<endl;
        cout << "3. Return Book"<<endl;
        cout << "4. Display Books"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        
        cin >> choice;

        switch (choice)
        {
            case 1:
                lib.addbook();
                break;
            case 2:
                lib.issuebook();
                break;
            case 3:
                lib.returnbook();
                break;
            case 4:
                lib.displaybook();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}