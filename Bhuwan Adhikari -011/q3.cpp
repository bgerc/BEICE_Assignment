#include <iostream>
#include <string>

using namespace std;

class Library {
public:
    Library(const string& bookTitle = "", const string& author = "", int numOfCopies = 0)
        : bookTitle(bookTitle), author(author), numOfCopies(numOfCopies) {}

    void addNewBook(int additionalCopies) {
        numOfCopies += additionalCopies;
        cout << "Added " << additionalCopies << " copies of '" << bookTitle << "'." << endl;
    }

    void issueBook() {
        if (numOfCopies > 0) {
            numOfCopies--;
            cout << "Issued one copy of '" << bookTitle << "'. Remaining copies: " << numOfCopies << endl;
        } else {
            cout << "No copies of '" << bookTitle << "' available to issue." << endl;
        }
    }

    void returnBook() {
        numOfCopies++;
        cout << "Returned one copy of '" << bookTitle << "'. Total copies: " << numOfCopies << endl;
    }

    void displayBookInfo() const {
        cout << "Title: " << bookTitle << ", Author: " << author << ", Copies: " << numOfCopies << endl;
    }

private:
    string bookTitle;
    string author;
    int numOfCopies;
};

int main() {
    Library book("C++ Programming", "bhuwan adhikari", 10);

    book.displayBookInfo();

    book.issueBook();
    book.issueBook();
    
    book.returnBook();

    book.addNewBook(5);

    book.displayBookInfo();

    return 0;
}
