#include <iostream>
#include <string>
using namespace std;

#define MaxBook 100

class Library {
    int bookID;
    string bookTitle;
    string author;
public:
    int noOfCopies;
    Library(string bookTitle="Harry Potter", string author="Aadarsha Bhusal", int noOfCopies=0, int bookID=0)
    : bookTitle(bookTitle), author(author), noOfCopies(noOfCopies), bookID(bookID) {}

    void showBook() const;
    void issueBook();
    void returnBook();
    int getBookID() const { return bookID; }
};

void Library::showBook() const {
    cout << bookID << " : " << bookTitle << " By " << author << " x" << noOfCopies << endl;
}

void Library::returnBook() {
    noOfCopies++;
}

void Library::issueBook() {
    if (noOfCopies > 0) {
        noOfCopies--;
    } else {
        cout << "No copies available to issue." << endl;
    }
}

int main() {
    Library obj[MaxBook];
    int bookCount = 0;
    char D;
    int D2;

    cout << "First Feed some Books to the System!!!!\nEnter the number of books you want to add: ";
    cin >> bookCount;
    cin.ignore();

    if (bookCount > MaxBook) {
        cout << "Cannot add more than " << MaxBook << " books." << endl;
        bookCount = MaxBook;  // Limit the count to MaxBook
    }

    for (int i = 0; i < bookCount; i++) {
        string bookTitle;
        string author;
        int no;
        
        cout << "Book " << i + 1 << "\n";
        cout << "Book Name : ";
        getline(cin, bookTitle);
        cout << "Author : ";
        getline(cin, author);
        cout << "No of Copies : ";
        cin >> no;
        cin.ignore();
        
        obj[i] = Library(bookTitle, author, no, i + 1);
        cout << "Added Book " << i + 1 << " Successfully .......\n";
    }

    cout << "Do You want to perform any Library Operation?(Y?N) :";
    cin >> D;
    cin.ignore();

    if (D == 'y' || D == 'Y') {
        do {
            cout << "1: Add BOOK\n2: Issue Book\n3: Return Book\n4: Exit\n";
            cout << "What would you like to Perform: ";
            cin >> D2;
            cin.ignore();

            switch (D2) {
                case 1: {
                    if (bookCount < MaxBook) {
                        string bookTitle;
                        string author;
                        int no;
                        
                        cout << "Enter the number of books you want to add: ";
                        int numBooks;
                        cin >> numBooks;
                        cin.ignore();
                        
                        if (numBooks + bookCount > MaxBook) {
                            cout << "Cannot add more than " << MaxBook - bookCount << " books." << endl;
                            numBooks = MaxBook - bookCount;
                        }

                        for (int i = 0; i < numBooks; i++) {
                            cout << "Book " << bookCount + 1 << "\n";
                            cout << "Book Name : ";
                            getline(cin, bookTitle);
                            cout << "Author : ";
                            getline(cin, author);
                            cout << "No of Copies : ";
                            cin >> no;
                            cin.ignore();

                            obj[bookCount] = Library(bookTitle, author, no, bookCount + 1);
                            bookCount++;
                            cout << "Added Book " << bookCount << " Successfully .......\n";
                        }
                    } else {
                        cout << "Library is full. Cannot add more books.\n";
                    }
                    break;
                }
                case 2: {
                    int opt;
                    cout << "Available Books:\n";
                    for (int i = 0; i < bookCount; i++) {
                        obj[i].showBook();
                    }
                    cout << "Enter BookID You Want: ";
                    cin >> opt;
                    cin.ignore();
                    
                    bool found = false;
                    for (int i = 0; i < bookCount; i++) {
                        if (obj[i].getBookID() == opt) {
                            obj[i].issueBook();
                            cout << "Issued: ";
                            obj[i].showBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book with ID " << opt << " not found.\n";
                    }
                    break;
                }
                case 3: {
                    int opt;
                    cout << "Available Books:\n";
                    for (int i = 0; i < bookCount; i++) {
                        obj[i].showBook();
                    }
                    cout << "Enter BookID You Want to Return: ";
                    cin >> opt;
                    cin.ignore();
                    
                    bool found = false;
                    for (int i = 0; i < bookCount; i++) {
                        if (obj[i].getBookID() == opt) {
                            obj[i].returnBook();
                            cout << "Returned: ";
                            obj[i].showBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book with ID " << opt << " not found.\n";
                    }
                    break;
                }
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid option. Exiting...\n";
                    D2 = 4;
                    break;
            }

        } while (D2 != 4);
    } else {
        cout << "Program Terminated...\n";
    }

    return 0;
}
