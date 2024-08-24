#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

public:
    Book() : title(""), author(""), copies(0) {}

    Book(string t, string a, int c) : title(t), author(a), copies(c) {}

    void display()
    {
        cout << "Title: " << title << ", Author: " << author << ", Copies: " << copies << endl;
    }

    void issue()
    {
        if (copies > 0) {
            copies--;
            cout << "Book issued successfully!" << endl;
        } else {
            cout << "No copies left to issue!" << endl;
        }
    }


    void returnBook() {
        copies++;
        cout << "Book returned successfully!" << endl;
    }

    string getTitle()
     {
        return title;
    }

    void setDetails(const string& t, const string& a, int c) {
        title = t;
        author = a;
        copies = c;
    }
};

class Library {
private:
    Book* catalog;
    int bookCount;
    int capacity;

    void resizeCatalog() {
        int newCapacity = capacity * 2;
        Book* newCatalog = new Book[newCapacity];
        for (int i = 0; i < bookCount; ++i) {
            newCatalog[i] = catalog[i];
        }
        delete[] catalog;
        catalog = newCatalog;
        capacity = newCapacity;
    }

public:

    Library(int initialCapacity = 2) : bookCount(0), capacity(initialCapacity) {
        catalog = new Book[capacity];
    }


    ~Library() {
        delete[] catalog;
    }


    void addBook() {
        if (bookCount == capacity) {
            resizeCatalog();
        }
        string title, author;
        int copies;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> copies;

        catalog[bookCount].setDetails(title, author, copies);
        bookCount++;
        cout << "Book added successfully!" << endl;
    }


    void listBooks() const {
        if (bookCount == 0) {
            cout << "No books available." << endl;
        } else {
            for (int i = 0; i < bookCount; ++i) {
                catalog[i].display();
            }
        }
    }


    void issueBook() {
        string title;
        cout << "Enter the title of the book to issue: ";
        cin.ignore();
        getline(cin, title);

        for (int i = 0; i < bookCount; ++i) {
            if (catalog[i].getTitle() == title) {
                catalog[i].issue();
                return;
            }
        }
        cout << "Book not found." << endl;
    }

        void returnBook() {
        string title;
        cout << "Enter the title of the book to return: ";
        cin.ignore();
        getline(cin, title);

        for (int i = 0; i < bookCount; ++i) {
            if (catalog[i].getTitle() == title) {
                catalog[i].returnBook();
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library lib;
    char choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                lib.addBook();
                break;
            case '2':
                lib.listBooks();
                break;
            case '3':
                lib.issueBook();
                break;
            case '4':
                lib.returnBook();
                break;
            case '5':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
