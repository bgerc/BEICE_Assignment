#include <iostream>
#include <string.h>

class Library {
public:
    char bookTitle[50];
    char author[50];
    int numberOfCopies;

    Library(const char* bookTitle, const char* author, int numberOfCopies) {
        strcpy(this->bookTitle, bookTitle);
        strcpy(this->author, author);
        this->numberOfCopies = numberOfCopies;
    }

    void addBook(int copies) {
        numberOfCopies += copies;
    }

    void issueBook(int copies) {
        if (numberOfCopies >= copies) {
            numberOfCopies -= copies;
        } else {
            std::cout << "Not enough copies available!" << std::endl;
        }
    }

    void returnBook(int copies) {
        numberOfCopies += copies;
    }
};

int main() {
    Library book1("Those Nine Days", "Tirthankar Khatiwada", 5);

    book1.addBook(2);
    std::cout << "Number of copies after adding: " << book1.numberOfCopies << std::endl;

    book1.issueBook(3);
    std::cout << "Number of copies after issuing: " << book1.numberOfCopies << std::endl;

    book1.returnBook(1);
    std::cout << "Number of copies after returning: " << book1.numberOfCopies << std::endl;

    return 0;
}
