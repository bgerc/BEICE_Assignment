/*Define a class Library with bookTitle, author, and numberOfCopies as data members. Implement methods to add new books, issue books,
and return books. Ensure that the number of copies is appropriately updated for each operation.*/

#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int numberOfCopies;

    Book() {}
    Book(string t, string a, int n)
    {
        title = t;
        author = a;
        numberOfCopies = n;
    }
};

class Library
{
public:
    Book books[100];
    int bookCount;

    Library()
    {
        bookCount = 0;
    }

    void addBook(string title, string author, int copies)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].title == title)
            {
                books[i].numberOfCopies += copies;
                cout << "Added " << copies << " copies of existing book." << endl;
                return;
            }
        }
        books[bookCount] = Book(title, author, copies);
        bookCount++;
        cout << "Added new book to the library." << endl;
    }

    void issueBook(string title)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].title == title)
            {
                if (books[i].numberOfCopies > 0)
                {
                    books[i].numberOfCopies--;
                    cout << "Book issued successfully. Remaining copies: " << books[i].numberOfCopies << "" << endl;
                } else
                {
                    cout << "Sorry, no copies available for this book." << endl;
                }
                return;
            }
        }
        cout << "No book found in the library with the given title." << endl;
    }

    void returnBook(string title)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].title == title)
            {
                books[i].numberOfCopies++;
                cout << "Book returned successfully. Updated number of copies: " << books[i].numberOfCopies << "" << endl;
                return;
            }
        }
        cout << "No book found in the library with the given title." << endl;
    }

    void displayBooks()
    {
        cout << "Library Inventory:" << endl;
        for (int i = 0; i < bookCount; i++)
        {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Copies: " << books[i].numberOfCopies << "" << endl;
        }
    }
};

int main()
{
    Library library;
    int choice;
    string title, author;
    int copies;

    while (true)
    {
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                library.addBook(title, author, copies);
                break;
            case 2:
                cout << "Enter book title to issue: ";
                cin.ignore();
                getline(cin, title);
                library.issueBook(title);
                break;
            case 3:
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            case 4:
                library.displayBooks();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}