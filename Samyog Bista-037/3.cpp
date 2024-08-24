/*
Define a class Library with bookTitle, author and numberOfCopies as data members. 
 Implement methods to add new books, issue books and return books.
 Ensure that the number of copeis is appropriately update for each operation.
*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100; 

class Library {
private:
    string bookTitles[MAX_BOOKS];
    string authors[MAX_BOOKS];
    int numberOfCopies[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const string& bookTitle, const string& author, int numberOfCopies) 
	{
        for (int i = 0; i < bookCount; ++i) 
		{
            if (bookTitles[i] == bookTitle) 
			{
                cout << "Book already exists. Updating the number of copies.\n";
                this->numberOfCopies[i] += numberOfCopies;
                return;
            }
        }

        if (bookCount < MAX_BOOKS) 
		{
            bookTitles[bookCount] = bookTitle;
            authors[bookCount] = author;
            this->numberOfCopies[bookCount] = numberOfCopies;
            ++bookCount;
            cout << "Book added successfully.\n";
        } 
		else 
		{
            cout << "Library is full. Cannot add more books.\n";
        }
    }

    void issueBook(const string& bookTitle) 
	{
        for (int i = 0; i < bookCount; ++i) 
		{
            if (bookTitles[i] == bookTitle) 
			{
                if (numberOfCopies[i] > 0) 
				{
                    --numberOfCopies[i];
                    cout << "Book issued successfully.\n";
                } 
				else 
				{
                    cout << "No copies available to issue.\n";
                }
                return;
            }
        }
        cout << "Book not found in the library.\n";
    }

    void returnBook(const string& bookTitle) 
	{
        for (int i = 0; i < bookCount; ++i) 
		{
            if (bookTitles[i] == bookTitle) 
			{
                ++numberOfCopies[i];
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found in the library.\n";
    }

    void displayBooks() 
	{
        if (bookCount == 0) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "Books in the library:\n";
        for (int i = 0; i < bookCount; ++i) {
            cout << "Title: " << bookTitles[i] << ", Author: " << authors[i] << ", Copies: " << numberOfCopies[i] << '\n';
        }
    }
};

int main() {
    Library myLibrary;
    int choice;
    string title, author;
    int copies;

    do {
        cout << "\nLibrary System Menu:\n";
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
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                cin.ignore(); 
                myLibrary.addBook(title, author, copies);
                break;

            case 2:
                cout << "Enter book title to issue: ";
                getline(cin, title);
                myLibrary.issueBook(title);
                break;

            case 3:
                cout << "Enter book title to return: ";
                getline(cin, title);
                myLibrary.returnBook(title);
                break;

            case 4:
                myLibrary.displayBooks();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}