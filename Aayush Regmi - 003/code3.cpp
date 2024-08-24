#include<iostream>
#include<cstring>
#define MAX_BOOKS 25
using namespace std;

class BookLibrary
{
    char bookTitles[MAX_BOOKS][MAX_BOOKS];
    char authors[MAX_BOOKS][MAX_BOOKS];
    int copies[MAX_BOOKS];
    int borrowedCopies[MAX_BOOKS] = {0}; // Array to track borrowed copies
    int totalBooks = 0;
    int bookCount = 0;

    bool bookExists = false;
public:
    void addBooks()
    {
        char newBook[MAX_BOOKS];
        char newAuthor[MAX_BOOKS];
        int newCopies;
        int existingBookCount = 0;
  
        cout << "Enter the number of books to add: ";
        do
        {
            cin >> totalBooks;
        } while(totalBooks <= 0);

        cout << "Enter the details of each book: " << endl;
        bookCount += totalBooks;

        for(int i = bookCount - totalBooks; i < bookCount; i++)
        {
            cout << "Book title: ";
            cin.ignore();
            cin.getline(newBook, MAX_BOOKS);
            bookExists = false;

            // Checking if the book already exists
            for(int j = 0; j < bookCount; j++)
            {
                // If the book already exists, add copies to it
                if(strcmp(bookTitles[j], newBook) == 0)
                {
                    cout << "Enter the number of copies: ";
                    cin >> newCopies;
                    copies[j] += newCopies;
                    bookExists = true;
                    existingBookCount++;
                    break;
                }
            }

            if(!bookExists)
            {
                // If the book doesn't exist, add a new entry
                strcpy(bookTitles[i], newBook);
                cout << "Author of the book: ";
                cin.getline(authors[i], MAX_BOOKS);
                cout << "Number of copies: ";
                cin >> copies[i]; 
            } 
        }

        if(bookExists)
        {
            // Adjust the book count for repeated books
            bookCount -= existingBookCount;
        }
    }

    void showBooks()
    {
        if(bookCount == 0) 
        {
            cout << "No books available." << endl;
            return;
        }

        cout << "----------------------------------------" << endl;
        for(int i = 0; i < bookCount; i++)
        {
            cout << "Book (" << i + 1 << "): " << endl;
            cout << "Title: " << bookTitles[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Total copies: " << copies[i] << endl;
            cout << "-------------------------------------------" << endl;
        }
        char continueCheck;
        cout << "Continue? [y/n]: ";
        cin >> continueCheck;
    }

    void borrowBook()
    {
        char searchBook[MAX_BOOKS];
        int borrowAmount;
        showBooks();
        cout << "Enter the title of the book to borrow: ";
        cin.ignore();
        cin.getline(searchBook, MAX_BOOKS);

        for(int i = 0; i < bookCount; i++)
        {
            if(strcmp(searchBook, bookTitles[i]) == 0)
            {
                cout << "Enter the number of copies to borrow: ";
                cin >> borrowAmount;
                if(borrowAmount <= 0 || borrowAmount > copies[i]) throw(borrowAmount);
                copies[i] -= borrowAmount;
                borrowedCopies[i] += borrowAmount;

                cout << "Book borrowed successfully!" << endl;
                return; // Exit after borrowing a book
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook()
    {
        char returnBook[MAX_BOOKS];
        int returnAmount;
        displayBorrowedBooks();
        cout << "Enter the title of the book to return: ";
        cin.ignore();
        cin.getline(returnBook, MAX_BOOKS);

        for(int i = 0; i < bookCount; i++)
        {
            if(strcmp(returnBook, bookTitles[i]) == 0)
            {
                cout << "Enter the number of copies to return: ";
                cin >> returnAmount;
                if(returnAmount <= 0 || returnAmount > borrowedCopies[i]) throw (returnAmount);
                copies[i] += returnAmount;
                borrowedCopies[i] -= returnAmount;

                cout << "Book returned successfully!" << endl;
                return; // Exit after returning a book
            }
        }
        cout << "Book not found!" << endl;
    }

    void displayBorrowedBooks()
    {
        bool anyBorrowed = false;
        cout << "----------------------------------------" << endl;
        for(int i = 0; i < bookCount; i++)
        {
            if(borrowedCopies[i] > 0)
            {
                anyBorrowed = true;
                cout << "Book (" << i + 1 << "): " << endl;
                cout << "Title: " << bookTitles[i] << endl;
                cout << "Author: " << authors[i] << endl;
                cout << "Borrowed copies: " << borrowedCopies[i] << endl;
                cout << "-------------------------------------------" << endl;
            }
        }
        if (!anyBorrowed)
        {
            cout << "No books are currently borrowed." << endl;
        }
    }
};

int main()
{
    BookLibrary library;
    while(true)
    {
        int choice;
        cout << "--------------------------------------------------------" << endl;
        cout << "                    ACTIVITIES                          " << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "1. Add Books" << endl;
        cout << "2. Show Available Books" << endl;
        cout << "3. Borrow a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Display Borrowed Books" << endl;
        cout << "6. Exit" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("clear");

        switch (choice)
        {
        case 1:
            library.addBooks();
            break;
        case 2:
            library.showBooks();
            break;
        case 3:
            try
            {
                library.borrowBook();
            }
            catch(int)
            {
                cout << "Invalid number of books specified!" << endl;
            }
            break;
        case 4:
            try
            {
                library.returnBook();
            }
            catch(int)
            {
                cout << "Invalid number of books!" << endl;
            }
            break;
        case 5:
            library.displayBorrowedBooks();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}
