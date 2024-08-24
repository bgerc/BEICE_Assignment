/*Define a class Library with booktitle ,author and numberofcopies as data members .Implement methods to add new books ,issue books and return books.Ensure that the number of copies is appropiately updated for each operation*/

#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int copies;

    Book(const std::string& title, const std::string& author, int copies)
        : title(title), author(author), copies(copies) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, int copies) {
        books.emplace_back(title, author, copies);
    }

    void issueBook(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && book.copies > 0) {
                book.copies--;
                std::cout << "Book '" << book.title << "' issued successfully." << std::endl;
                return; // Added return statement to exit the method after issuing the book
            }
        }
    
        std::cout << "Book '" << title << "' is not available." << std::endl;
    }

    void returnBook(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title) {
                book.copies++;
                std::cout << "Book '" << book.title << "' returned successfully." << std::endl;
                return;
            }
        }
        std::cout << "Book '" << title << "' is not valid." << std::endl;
    }

    void displayBooks() {
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            std::cout << "Title: " << book.title << ", Author: " << book.author << ", Copies: " << book.copies << std::endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    int numBooks;
    std::string title; // Declare the 'title' variable

    std::cout << "Welcome to the Library Management System!" << std::endl;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add new books\n";
        std::cout << "2. Issue a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Display books in the library\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the number of books you want to add: ";
                std::cin >> numBooks;
                for (int i = 0; i < numBooks; i++) {
                    std::string title, author;
                    int copies;
                    std::cout << "Enter the details of book " << i + 1 << ":\n";
                    std::cout << "Title: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Author: ";
                    std::getline(std::cin, author);
                    std::cout << "Number of copies: ";
                    std::cin >> copies;
                    library.addBook(title, author, copies);
                }
                break;
            case 2:
                std::cout << "Enter the title of the book you want to issue: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.issueBook(title);
                break;
            case 3:
                std::cout << "Enter the title of the book you want to return: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.returnBook(title);
                break;
            case 4:
                library.displayBooks();
                break;
            case 0:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}