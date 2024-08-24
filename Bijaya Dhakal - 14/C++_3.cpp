#include <iostream>
#include <unordered_map>
#include <string>

class Library {
private:
    struct Book {
        std::string author;
        int numberOfCopies;
    };

    std::unordered_map<std::string, Book> books;

public:
    void addBook(const std::string& bookTitle, const std::string& author, int numberOfCopies) {
        if (books.find(bookTitle) != books.end()) {
            std::cout << "Book '" << bookTitle << "' already exists in the library.\n";
        } else {
            books[bookTitle] = { author, numberOfCopies };
            std::cout << "Added '" << bookTitle << "' by " << author << " with " << numberOfCopies << " copies.\n";
        }
    }
    void issueBook(const std::string& bookTitle) {
        auto it = books.find(bookTitle);
        if (it != books.end()) {
            if (it->second.numberOfCopies > 0) {
                it->second.numberOfCopies--;
                std::cout << "Issued '" << bookTitle << "'.\n";
            } else {
                std::cout << "No copies of '" << bookTitle << "' are available.\n";
            }
        } else {
            std::cout << "Book '" << bookTitle << "' does not exist in the library.\n";
        }
    }
    void returnBook(const std::string& bookTitle) {
        auto it = books.find(bookTitle);
        if (it != books.end()) {
            it->second.numberOfCopies++;
            std::cout << "Returned '" << bookTitle << "'.\n";
        } else {
            std::cout << "Book '" << bookTitle << "' does not exist in the library.\n";
        }
    }
    void printInventory() const {
        if (books.empty()) {
            std::cout << "Library is empty.\n";
            return;
        }

        std::cout << "Library Inventory:\n";
        for (const auto& pair : books) {
            std::cout << pair.first << ": " << pair.second.author << " - " << pair.second.numberOfCopies << " copies\n";
        }
    }
};

int main() {
    Library library;
    int choice;
    std::string title, author;
    int copies;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Issue Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Print Inventory\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                std::cout << "Enter number of copies: ";
                std::cin >> copies;
                std::cin.ignore();
                library.addBook(title, author, copies);
                break;
            case 2:
                std::cout << "Enter book title to issue: ";
                std::getline(std::cin, title);
                library.issueBook(title);
                break;
            case 3:
                std::cout << "Enter book title to return: ";
                std::getline(std::cin, title);
                library.returnBook(title);
                break;
            case 4:
                library.printInventory();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
