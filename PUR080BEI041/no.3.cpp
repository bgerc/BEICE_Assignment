#include <iostream>
#include <string>

class Library {
private:
    std::string bookTitle;
    std::string author;
    int numberOfCopies;

public:
    Library(std::string title, std::string auth, int copies) 
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
        std::cout << "Title: " << bookTitle << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Number of Copies: " << numberOfCopies << "\n";
    }
};

int main() {
    Library book("Effective C++", "Scott Meyers", 5);

    book.displayInfo();

    if (book.issueBook()) {
        std::cout << "Book issued successfully.\n";
    } else {
        std::cout << "No copies available to issue.\n";
    }

    book.returnBook();
    std::cout << "Book returned successfully.\n";

    book.addBooks(3);
    std::cout << "Books added successfully.\n";

    book.displayInfo();

    return 0;
}
