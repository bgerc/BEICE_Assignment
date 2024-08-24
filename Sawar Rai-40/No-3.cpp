#include <iostream>
#include <string>

using namespace std;

const int maxBookLibraryHold = 100;

class Library 
{
    string bookTitle, author;
    int numberOfCopies;

public:
    string BOOKTITLE() 
    {
        return bookTitle;
    }

    void AddNewBooks(Library[], int&);
    void IssueBook(string);
    void ReturnBook(string);
    void DisplayBooks();
};

void Library::AddNewBooks(Library lib[], int& n) 
{
    cout << endl;
    if (n >= maxBookLibraryHold) {
        cout << "Library is full. Cannot add more books.\n";
        return;
    } else {
        string newtitle;
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, newtitle);
        for (int i = 0; i < n; i++) {
            if (lib[i].BOOKTITLE() == newtitle) 
            {
                cout<<"-------------------------------"<<endl;
                cout << "Book already exists in the library.\n";
                cout<<"-------------------------------"<<endl;
                return;
            }
        }
        lib[n].bookTitle = newtitle;
        cout << "Enter the author of the book: ";
        getline(cin, lib[n].author);
        cout << "Enter the number of copies: ";
        cin >> lib[n].numberOfCopies;
        cout<<"__________________________"<<endl;
        cout << "|Book added successfully.|\n";
        cout<<"--------------------------"<<endl;
        n++;
    }
}

void Library::IssueBook(string title) {
    if (title == bookTitle) {
        if (numberOfCopies > 0) {
            cout<<"__________________________"<<endl;
            cout << "Book issued successfully.\n";
            cout<<"-------------------------------"<<endl;
            numberOfCopies--;
        } else {
            cout<<"__________________________"<<endl;
            cout << "Not enough copies!\n";
            cout<<"-------------------------------"<<endl;
        }
    }
}

void Library::ReturnBook(string title1) {
    if (title1 == bookTitle) {
        cout<<"__________________________"<<endl;
        cout << "Book returned successfully.\n";
        cout<<"---------------------------"<<endl;
        numberOfCopies++;
    }
}

void Library::DisplayBooks() 
{
    cout << "Book Title: " << bookTitle << "\tAuthor: " << author<< "\tNumber of copies: " << numberOfCopies << endl;
}

int main() {
    Library library[maxBookLibraryHold];
    int n = 0; 

    while (true) {
        cout << "1. Add New Books" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"No books yet,Add before issuing!!!(Check Display Book)"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                library[n].AddNewBooks(library, n);
                break;
            }
            case 2: {
                string title;
                cout << "Enter the title of the book you want to issue: ";
                cin.ignore();
                getline(cin, title);
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (library[i].BOOKTITLE() == title) {
                        library[i].IssueBook(title);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                   cout<<"__________________________________"<<endl;
                    cout << "Book not found in the library.\n";
                      cout<<"-------------------------------"<<endl;
                }
                break;
            }
            case 3: {
                string title1;
                cout << "Enter the title of the book you want to return: ";
                cin.ignore();
                getline(cin, title1);
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (library[i].BOOKTITLE() == title1) {
                        library[i].ReturnBook(title1);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                   cout<<"_______________________________"<<endl;
                    cout << "Book not found in the library.\n";
                    cout<<"-------------------------------"<<endl;
                }
                break;
            }
            case 4: {
                for (int i = 0; i < n; i++) {
                    library[i].DisplayBooks();
                }
                break;
            }
            case 5: {
                return 0;
            }
            default: {
               cout<<"___________________"<<endl;
                cout << "Invalid input!!!!!" << endl;
                cout<<"-------------------"<<endl;
            }
        }
    }
    return 0;
}
