#include <iostream>
#include <string>
using namespace std;
class Library {
private:
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    Library(string title, string auth, int copies) 
        : bookTitle(title), author(auth), numberOfCopies(copies) {}

    void addBooks(int additionalCopies) {
        numberOfCopies += additionalCopies;
    }

    bool issueBook() {
        if (numberOfCopies > 0) {
            numberOfCopies--;
            return true;
        }
        return false;
    }

    void returnBook() {
        numberOfCopies++;
    }

    void displayInfo() const {
      cout << "Title: " << bookTitle << "\n";
      cout << "Author: " << author << "\n";
      cout << "Number of Copies: " << numberOfCopies << "\n";
    }
};

int main() {
    Library book("Effective C++", "Scott Meyers", 5);

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