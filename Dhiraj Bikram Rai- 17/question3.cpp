#include<iostream>
#include<cstring>

using namespace std;

const int MaxBook = 100;

class Library
{
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    string getBookTitle()
    {
        return bookTitle;
    }

    void AddNewBooks(Library lib[], int &n)
    {
        if(n >= MaxBook)
        {
            cout << "Library is full. Cannot add more books.\n";
            return;
        }
        
        string newtitle;
        cout << "Enter the title of the book: ";
       cin >>newtitle;
        for(int i = 0; i < n; i++)
        {
            if(lib[i].getBookTitle() == newtitle)
            {
                cout << "Book already exists in the library.\n";
                return;
            }
        }

        lib[n].bookTitle = newtitle;
        cout << "Enter the author of the book: ";
        cin >>author;
        cout << "Enter the number of copies: ";
        cin >> lib[n].numberOfCopies;
        cout << "Book added successfully." << endl;
        n++;
    }

    void IssueBook(string title)
    {
        if(title == bookTitle)
        {
            if(numberOfCopies > 0)
            {
                cout << "Book issued successfully." << endl;
                numberOfCopies--;
            }
            else
            {
                cout << "Not enough copies available!" << endl;
            }
        }
    }

    void ReturnBook(string title)
    {
        if(title == bookTitle)
        {
            cout << "Book returned successfully." << endl;
            numberOfCopies++;
        }
    }

    void DisplayBooks()
    {
        cout << "Book Title: " << bookTitle << endl
             << "Author: " << author << endl
             << "Number of Copies: " << numberOfCopies << endl;
    }
};

int main()
{
    Library l[MaxBook];
    int n = 0; 
    
    while(true)
    {
        cout << "1. Add New Books" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                l[n].AddNewBooks(l, n);
                break;
            }
            case 2:
            {
                string title;
                cout << "Enter the title of the book you want to issue: ";
                 
                cin>>title;
                bool found = false;
                for(int i = 0; i < n; i++)
                {
                    l[i].IssueBook(title);
                    if(l[i].getBookTitle() == title) 
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Book not found in the library." << endl;
                }
                break;
            }
            case 3:
            {
                string title;
                cout << "Enter the title of the book you want to return: ";
              cin>>title;
                bool found = false;
                for(int i = 0; i < n; i++)
                {
                    l[i].ReturnBook(title);
                    if(l[i].getBookTitle() == title)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Book not found in the library." << endl;
                }
                break;
            }
            case 4:
            {
                for(int i = 0; i < n; i++)
                {
                    l[i].DisplayBooks();
                }
                break;
            }
            case 5:
            {
                return 0; 
            }
            default:
            {
                cout << "Invalid input!!! (Please try again)." << endl;
            }
        }
    }
    return 0;
}
