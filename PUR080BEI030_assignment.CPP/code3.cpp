#include <iostream>
#include <string>
#include <limits> // for numeric_limits
using namespace std;

class Library
{
    string bookTitle, author;
    int numberOfCopies;

public:
    Library(string b = "", string a = "", int n = 0)
        : bookTitle(b), author(a), numberOfCopies(n) {}

    void addnew()
    {
        // the cin.ignore() clear only the next newline character.......
        // whereas, the below code clears the entire input buffer upto next newline

        // using cin.ignore(); sometimes cause infinite code running
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the Title of the Book : ";
        getline(cin, bookTitle);
        cout << "Enter the name of the author : ";
        getline(cin, author);
        cout << "Enter number of copies of the book : ";
        cin >> numberOfCopies;
        cout << endl;
    }

    void availableBooks() const
    {
        cout << "Title : " << bookTitle << ",  Author : " << author
             << ",  Copies : " << numberOfCopies << endl;
    }

    // to store and manipulate the bookTitle in the code
    string getBookTitle() const
    {
        return bookTitle;
    }

    int getNumberOfCopies() const
    {
        return numberOfCopies;
    }

    void issueBook(const string &title, int &copies)
    {
        if (title == bookTitle)
        {
            if (numberOfCopies >= copies)
            {
                numberOfCopies -= copies;
                cout << copies << " copies of " << bookTitle
                     << " book issued successfully." << endl;
            }
            else
            {
                cout << "Not enough copies available." << endl;
            }
        }
    }

    void returnBook(const string &title, int copies)
    {
        if (title == bookTitle)
        {
            numberOfCopies += copies;
            cout << copies << " copies " << "of " << title
                 << " book returned successfully." << endl;
        }
    }
};

int main()
{
    cout << "\nWelcome to Library" << endl;

    int n;
    cout << "\nEnter the Total number of books available : ";
    cin >> n;
    cout << endl;

    Library *Lib = new Library[n];

    // adding new books at starting of the code.
    for (int i = 0; i < n; i++)
    {
        cout << "For Book " << i + 1 << endl;
        Lib[i].addnew();
    }

    int choice;
    do
    {
        cout << endl;
        cout << " Library Menu " << endl;
        cout << "1. Add new book" << endl;
        cout << "2. See available books" << endl;
        cout << "3. Issue a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;

        // there is no option to remove the book as the given question does not ask for it

        switch (choice)
        {
        case (1): // add new book
        {
            Library newBook;
            newBook.addnew();

            // for new book, need extra one space
            Library *temp = new Library[n + 1];
            for (int i = 0; i < n; i++)
            {
                temp[i] = Lib[i];
            }
            temp[n] = newBook;
            delete[] Lib;
            Lib = temp;
            n++;
        }
        break;

        case (2): // see available books
        {
            if (n > 0)
            {
                int SN = 1;
                cout << "Available Books" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << SN << ". ";
                    Lib[i].availableBooks();
                    SN++;
                }
            }
            else
            {
                cout << "No books available." << endl;
            }
        }
        break;

        case (3): // issue a book
        {
            string title;
            int copies;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the Title of the book you want to issue : ";
            getline(cin, title);
            cout << "Enter the number of copies you want to issue : ";
            cin >> copies;

            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (Lib[i].getBookTitle() == title)
                {
                    Lib[i].issueBook(title, copies);
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "Book not found." << endl;
            }
        }
        break;

        case (4): // Return a book
        {
            string title;
            int copies;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the Title of the book you want to return : ";
            getline(cin, title);
            cout << "Enter the number of copies you want to return : ";
            cin >> copies;

            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (Lib[i].getBookTitle() == title)
                {
                    Lib[i].returnBook(title, copies);

                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                cout << "Book not found." << endl;
            }
        }
        break;

        case 5: // Exit
            cout << "Thank You for using." << endl;
            break;

        default:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    delete[] Lib;
    return 0;
}