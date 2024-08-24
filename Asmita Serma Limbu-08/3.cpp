#include <iostream>
#include <string>

using namespace std;

class Library {
    string booktitle;
    string author;
    int noofbooks;

public:
    Library(string name, string aur, int copies) {
        booktitle = name;
        author = aur;
        noofbooks = copies;
    }

    void addBooks(int copies) {
        noofbooks += copies;
        cout << copies << " copies of \"" << booktitle << "\" were added." << endl;
    }

    bool issueBooks() {
        if (noofbooks > 0) {
            noofbooks--;
            cout << "\"" << booktitle << "\" successfully issued." << endl;
            return true;
        } else {
            cout << "Book not available." << endl;
            return false;
        }
    }

    void returnBook() {
        noofbooks++;
        cout << "\"" << booktitle << "\" returned successfully." << endl;
    }

    void displayBooks() {
        cout << "Book title: " << booktitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of books: " << noofbooks << endl;
    }
};

int main() {
    string title, aur;
    int books;

    cout << "Enter the name of the book: ";
    getline(cin, title);
    cout << "Enter the author: ";
    getline(cin, aur);
    cout << "Enter the number of books: ";
    cin >> books;

    Library b1(title, aur, books);

    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add books\n";
        cout << "2. Issue book\n";
        cout << "3. Return book\n";
        cout << "4. Display information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int numberofbooks;
                cout << "Enter the number of books to add: ";
                cin >> numberofbooks;
                b1.addBooks(numberofbooks);
                break;
            }
            case 2: {
                b1.issueBooks();
                break;
            }
            case 3: {
                b1.returnBook();
                break;
            }
            case 4: {
                b1.displayBooks();
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}