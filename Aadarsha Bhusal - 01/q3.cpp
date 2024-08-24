#include <iostream>
int g_n;

class Library
{
private:
    std::string m_bookTitle[100];
    std::string m_author[100];
    int m_numberOfCopies[100];

public:
    void addBook() {
        std::cout << "Enter number of different books to add: ";
        std::cin >> g_n;
        for(int i = 0; i < g_n; i++) {
            std::cout << "Book title: ";
            std::cin >> m_bookTitle[i];
            std::cout << " Author name: ";
            std::cin >> m_author[i];
            std::cout << " No. of copies: ";
            std::cin >> m_numberOfCopies[i];
        }
    }
    
    void issueBook() {
        for (int i = 0; i < g_n; i++) {
            std::cout << i+1 << ". " << m_bookTitle[i] << " by " << 
            m_author[i] << " No. of copies: " << m_numberOfCopies[i] << "\n";
        }

        int option;
        std::cout << "Enter option: ";
        std::cin >> option;

        if (option > 0 && option <= g_n) {
            std::cout << "Book issued!!\n";
            m_numberOfCopies[option - 1]--;
        } else {
            std::cout << "Invalid option\n";
        }
    }

    void returnBook() {
        for (int i = 0; i < g_n; i++) {
            std::cout << i+1 << ". " << m_bookTitle[i] << " by " << 
            m_author[i] << " No. of copies: " << m_numberOfCopies[i] << "\n";
        }

        int option;
        std::cout << "Enter option: ";
        std::cin >> option;

        if (option > 0 && option <= g_n) {
            std::cout << "Book returned!!";
            m_numberOfCopies[option - 1]++;
        } else {
            std::cout << "Invalid option!\n";
        }
    }
};


int main()
{
    Library lib;
    int option;

    do {
        std::cout << "1. Add Book\n";
        std::cout << "2. Issue Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Exit\n";

        std::cout << "Enter option:  ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.issueBook();
            break;
        case 3:
            lib.returnBook();
            break;
        case 4:
            std::cout << "Exited!!\n";
            break;
        default:
            std::cout << "Wrong option, try again!!\n";
        }

    } while (option != 4);


    return 0;
}