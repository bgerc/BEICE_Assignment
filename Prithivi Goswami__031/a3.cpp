#include <iostream>
#include <cstring>
using namespace std;

class Library {
    char author[30];
    int no_of_copies;
    int final_no_of_copies;
    char booktitle[30];

public:
    void add_newbook() {
        cout << "\nEnter the book title: ";
        cin.ignore();
        cin.getline(booktitle, 30);
        cout << "Enter the author: ";
        cin.getline(author, 30);
        cout << "Enter the number of copies: ";
        cin >> no_of_copies;
        final_no_of_copies = no_of_copies;
    }

    const char* getBookTitle() const { return booktitle; }
    int getFinalCopies() const { return final_no_of_copies; }
    void decrementCopies() { final_no_of_copies--; }
    void incrementCopies() { final_no_of_copies++; }

    friend bool issue_book(Library &L, const char *N);
    friend bool return_book(Library &L, const char *N);
};

bool issue_book(Library &L, const char *N) {
    if (strcmp(L.booktitle, N) == 0) {
        if (L.final_no_of_copies > 0) {
            L.decrementCopies();
            cout << "\nThe book is issued. Remaining copies: " << L.final_no_of_copies << endl;
            return true;
        } else {
            cout << "No copies left to issue.\n";
            return false;
        }
    }
    return false;
}

bool return_book(Library &L, const char *N) {
    if (strcmp(N, L.booktitle) == 0) {
        if (L.final_no_of_copies < L.no_of_copies) {
            L.incrementCopies();
            cout << "\nYour book is returned. Total copies: " << L.final_no_of_copies << endl;
            return true;
        } else {
            cout << "All copies of this book are already returned.\n";
            return false;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "\nEnter the number of books: ";
    cin >> n;

    Library *l = new Library[n];

    for (int i = 0; i < n; i++) {
        l[i].add_newbook();
    }

    int c;
    while (true) {
        cout << "\nPlease enter 1 for issuing a book, 2 for returning a book, and 0 to exit: ";
        cin >> c;
        if (c == 0) break;

        switch (c) {
            case 1: {
                char N[30];
                cout << "\nEnter the book you want to issue: ";
                cin.ignore();
                cin.getline(N, 30);

                bool issued = false;
                for (int i = 0; i < n; i++) {
                    if (issue_book(l[i], N)) {
                        issued = true;
                        break;
                    }
                }
                if (!issued) {
                    cout << "\nThis book is not in the library or no copies are left.\n";
                }
                break;
            }
            case 2: {
                char N[30];
                cout << "\nEnter the book you want to return: ";
                cin.ignore();
                cin.getline(N, 30);

                bool returned = false;
                for (int i = 0; i < n; i++) {
                    if (return_book(l[i], N)) {
                        returned = true;
                        break;
                    }
                }
                if (!returned) {
                    cout << "\nThis book is not from this library or all copies are already returned.\n";
                }
                break;
            }
            default:
                cout << "Invalid option. Please enter 1, 2, or 0.\n";
                break;
        }
    }

    delete[] l;
    return 0;
}
