#include <iostream>
#include <cstring>
using namespace std;

const int MAX_BOOKS = 100;

class Book 
{
public:
    string title;
    string author;
    int copies;

    Book() : title(""), author(""), copies(0) {}
    Book(const string& t, const string& a, int c) : title(t), author(a), copies(c) {}

    bool canIssue() const 
    {
        return copies > 0;
    }

    bool issue() 
    {
        if (canIssue()) {
            --copies;
            return true;
        }
        return false;
    }

    void returnBook() 
    {
        ++copies;
    }

    void display() const 
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies available: " << copies << endl;
    }
 };

class Library 
{
private:
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const string& title, const string& author, int copies) 
    {
        if (bookCount < MAX_BOOKS) 
        {
            books[bookCount++] = Book(title, author, copies);
            cout << "Book added successfully." << endl;
        }
         else 
         {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void issueBook(const string& title) 
    {
        for (int i = 0; i < bookCount; ++i) 
        {
            if (books[i].title == title) {
                if (books[i].issue()) {
                    cout << "Book issued successfully." << endl;
                    return;
                } 
                else 
                {
                    cout << "No copies available to issue." << endl;
                    return;
                }
            }
        }
        cout << "Book not found." << endl;
    }

    void returnBook(const string& title) 
    {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].title == title) {
                books[i].returnBook();
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void displayBooks() const 
    {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
            return;
        }
        for (int i = 0; i < bookCount; ++i) {
            books[i].display();
            cout << "---------------------" << endl;
        }
    }
 };

 int main() 
{
    Library lib;

    int choice;
    string title, author;
    int copies;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) 
        {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                lib.addBook(title, author, copies);
                break;

            case 2:
                cout << "Enter book title to issue: ";
                getline(cin, title);
                lib.issueBook(title);
                break;

            case 3:
                cout << "Enter book title to return: ";
                getline(cin, title);
                lib.returnBook(title);
                break;

            case 4:
                lib.displayBooks();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);
    return 0;
}
