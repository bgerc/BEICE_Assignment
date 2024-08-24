#include <iostream>
#include <string>
using namespace std;

class Library {
public:
    
    string bookTitle;
    string author;
    int numberOfCopies;

    
    Library(string title,string author, int copies) {
        bookTitle = title;
        this->author = author;
        numberOfCopies = copies;
    }

    
    void addBook(int copies) {
        numberOfCopies += copies;
        cout << "Added " << copies << " copies of " << bookTitle << "\n";
    }

    bool issueBook() {
        if (numberOfCopies > 0) {
            numberOfCopies--;
            cout << "Issued a copy of " << bookTitle << "\n";
            return true;
        } else {
            cout << "No copies available of " << bookTitle << "\n";
            return false;
        }
    }

    void returnBook() {
        numberOfCopies++;
        cout << "Returned a copy of " << bookTitle << "\n";
    }
};

int main() {
    Library book1("The Lord of the Rings", "J.R.R. Tolkien", 5);

    book1.issueBook();
    book1.addBook(2);
    book1.issueBook();
    book1.returnBook();

    return 0;
}