#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Library {
private:
    class Book {
    private:
        string title;
        string author;
        int numCopies;

    public:
        
        Book(const string& title, const string& author, int numCopies)
            : title(title), author(author), numCopies(numCopies) {}


        string getTitle() const {
            return title;
        }

        
        string getAuthor() const {
            return author;
        }

        
        int getNumCopies() const {
            return numCopies;
        }

        
        void addCopies(int num) {
            if (num > 0) {
                numCopies += num;
            } else {
                cout << "Number of copies to add should be positive." << endl;
            }
        }

        
        bool issueBook() {
            if (numCopies > 0) {
                --numCopies;
                return true;
            } else {
                cout << "No copies available to issue." << endl;
                return false;
            }
        }

        
        void returnBook() {
            ++numCopies;
        }
    };

    vector<Book> books;


    Book* findBook(const string& title, const string& author) {
        for (auto& book : books) {
            if (book.getTitle() == title && book.getAuthor() == author) {
                return &book;
            }
        }
        return nullptr;
    }

public:
    
    void addBook() {
        string title, author;
        int numCopies;
        
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> numCopies;
        cin.ignore(); 

        Book* book = findBook(title, author);
        if (book) {
            book->addCopies(numCopies);
        } else {
            books.emplace_back(title, author, numCopies);
        }
        cout << "Book added successfully." << endl;
    }

    
    void issueBook() {
        string title, author;

        cout << "Enter book title to issue: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);

        Book* book = findBook(title, author);
        if (book && book->issueBook()) {
            cout << "Book issued successfully." << endl;
        }
    }

    
    void returnBook() {
        string title, author;

        cout << "Enter book title to return: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);

        Book* book = findBook(title, author);
        if (book) {
            book->returnBook();
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle()
                 << ", Author: " << book.getAuthor()
                 << ", Copies: " << book.getNumCopies() << endl;
        }
    }


    void run() {
        int choice;
        while (true) {
            cout << "\nLibrary Management System" << endl;
            cout << "1. Add New Book" << endl;
            cout << "2. Issue Book" << endl;
            cout << "3. Return Book" << endl;
            cout << "4. Display All Books" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); 

            switch (choice) {
                case 1:
                    addBook();
                    break;

                case 2:
                    issueBook();
                    break;

                case 3:
                    returnBook();
                    break;

                case 4:
                    displayBooks();
                    break;

                case 5:
                    cout << "Exiting the system." << endl;
                    return;

                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    Library library;
    library.run();
    return 0;
}
