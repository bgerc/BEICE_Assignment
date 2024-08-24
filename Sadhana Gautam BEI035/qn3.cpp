#include <iostream>
#include <string>
using namespace std;

class Library
{
    string book_Title;
    string author;
    int no_of_copies;

    public:
    Library(string title, string auth, int copies) 
        : book_Title(title), author(auth), no_of_copies(copies) {}

    void addBooks(int additionalCopies) {
        no_of_copies += additionalCopies;
    }

    bool issueBook() {
        if (no_of_copies > 0) {
            no_of_copies--;
            return true;
        }
        return false;
    }

    void returnBook() {
        no_of_copies++;
    }

    void displayInfo() const {
        cout << "Title: " << book_Title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Number of Copies: " << no_of_copies << "\n";
    }
};

int main() {
    Library book("Digital Electronics" , "William H. Gothmann" , 4);

    book.displayInfo();

    if (book.issueBook()) {
        cout << "Book issued successfully.\n";
    } else {
        cout << "No copies available to issue.\n";
    }

    book.returnBook();
    cout << "Book returned successfully.\n";

    book.addBooks(3);
    cout << "Books added successfully.\n";

    book.displayInfo();

    return 0;

    }