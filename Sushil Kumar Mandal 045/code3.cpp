#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    // Default constructor
    Library() : bookTitle(""), author(""), numberOfCopies(0) {}

    // Constructor with parameters
    Library(const string& title, const string& auth, int copies)
        : bookTitle(title), author(auth), numberOfCopies(copies) {}

    // Method to add new books
    void addBooks(int copies) {
        if (copies > 0) {
            numberOfCopies += copies;
            cout << copies << " copies of '" << bookTitle << "' have been added." << endl;
        } else {
            cout << "Invalid number of copies to add." << endl;
        }
    }

    // Method to issue books
    void issueBook(int copies) {
        if (copies > 0 && numberOfCopies >= copies) {
            numberOfCopies -= copies;
            cout << copies << " copies of '" << bookTitle << "' have been issued." << endl;
        } else {
            cout << "Not enough copies available to issue." << endl;
        }
    }

    // Method to return books
    void returnBook(int copies) {
        if (copies > 0) {
            numberOfCopies += copies;
            cout << copies << " copies of '" << bookTitle << "' have been returned." << endl;
        } else {
            cout << "Invalid number of copies to return." << endl;
        }
    }

    // Method to display book details
    void displayBookInfo() const {
        cout << "Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << numberOfCopies << endl;
    }
};

int main() 
{
    string title, author;
    int copies;
    int choice;
    Library book;

    while (true) {
        cout << "1. Enter book details" << endl;
        cout << "2. Display book information" << endl;
        cout << "3. Add copies of the book" << endl;
        cout << "4. Issue copies of the book" << endl;
        cout << "5. Return copies of the book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Input book details
                cout << "Enter book title: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, title);

                cout << "Enter book author: ";
                getline(cin, author);

                cout << "Enter number of copies: ";
                cin >> copies;

                // Create a Library object using user input
                book = Library(title, author, copies);
                break;

            case 2:
                // Display book information
                book.displayBookInfo();
                break;

            case 3:
                // Add books
                int additionalCopies;
                cout << "Enter number of additional copies to add: ";
                cin >> additionalCopies;
                book.addBooks(additionalCopies);
                book.displayBookInfo();
                break;

            case 4:
                // Issue books
                int issueCopies;
                cout << "Enter number of copies to issue: ";
                cin >> issueCopies;
                book.issueBook(issueCopies);
                book.displayBookInfo();
                break;

            case 5:
                // Return books
                int returnCopies;
                cout << "Enter number of copies to return: ";
                cin >> returnCopies;
                book.returnBook(returnCopies);
                book.displayBookInfo();
                break;

            case 6:
                // Exit
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}