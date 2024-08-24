#include<iostream>

using namespace std;

const int maxBookLibraryHold=100;

class Library
{
    string bookTitle, author;

    int numberOfCopies;

    public:
    string BOOKTITLE()
    {
        return bookTitle;
    }
    void AddNewBooks(Library [], int &);
    void IssueBook(string);
    void ReturnBook(string);
    void DisplayBooks();

};
void Library::AddNewBooks(Library lib[], int &n)
{
    cout<<endl;
    cout<<endl;
    if(n>maxBookLibraryHold)
    {
        cout << "Library is full. Cannot add more books.\n";
        return;
    }
    else
    {
        string newtitle;

        cout << "Enter the title of the book: ";
        cin >> newtitle;
        for(int i=0; i<n; i++)
        {
            if(lib[i].BOOKTITLE()==newtitle)
            {
                cout << "Book already exists in the library.\n";
                return;
            }
        }
        lib[n].bookTitle=newtitle;
        cout << "Enter the author of the book: ";
        cin >>lib[n].author;
        cout<<"Enter the number of copies: ";
        cin>>lib[n].numberOfCopies;
        cout<<"Book added successfully"<<endl;
        n++;
    }
    
}

void Library::IssueBook(string title)
{
    cout<<endl;
    cout<<endl;
    if(title==bookTitle && numberOfCopies>0)
    {
        cout<<"Book issued successfully"<<endl;
        numberOfCopies--;
       
    }
    if(numberOfCopies<0)
    {
        cout<<"not enough copy!!";
    }
    
    }
    void Library::ReturnBook(string title1)
    {
        cout<<endl;
        cout<<endl;

        if(title1==bookTitle)
        {
            cout<<"Book returned successfully"<<endl;
        
            numberOfCopies++;

        }
        else
        {
            cout<<"book not found!!!"<<endl;
        }
       
    }
    void Library::DisplayBooks()
    {
        cout<<endl;
        cout<<endl;
        cout<<"Book Title="<<bookTitle<<endl<<"Author="<<author<<endl<<"Number of copies="<<numberOfCopies<<endl;

    }

int main()
{
    Library library[maxBookLibraryHold];
    int n=0; //number of books in library
    
    while(true)
    {
        cout<<endl;
        cout<<endl;
        cout<<"1.Add New Books"<<endl;
        cout<<"2.Issue Book"<<endl;
        cout<<"3.Return Book"<<endl;
        cout<<"4.Display Books"<<endl;
        cout<<"5.Exit"<<endl;
        int choice;
        cout<<endl;
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                library[n].AddNewBooks(library, n);
                break;
            }
            case 2:
            {
                string title;
                cout<<"enter the title of book you want issue: "<<endl;
                cin>> title;
                for (int i = 0; i < n; i++)
                {
                     library[i].IssueBook(title);
                }  
                break;
            }
            case 3:
            {
                string title1;
                cout<<"enter the title of book you want return: "<<endl;
                cin>>title1;
                for(int i=0;i<n;i++)
                {
                    library[i].ReturnBook(title1);
                }
                
                break;
            }
            case 4:
            {
                for(int i=0;i<n;i++)
                {
                    library[i].DisplayBooks();
                }                
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                cout<<"invalid input !!!!!!!!!!";
            }

    }
}
}


