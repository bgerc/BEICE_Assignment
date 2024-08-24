/* Define a class Library with bookTitle, author, and numberOfCopies as data members.
 Implement methods to add new books, issue books, and return books. 
 Ensure that the number of copies is appropriately updated for each operation.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Library 
{
private:
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    void getinfo() 
    {
        cout << "Enter the book title: ";
        getline(cin, bookTitle);
        cout << "Enter the name of the author: ";
        getline(cin, author);
        cout << "Enter the number of copies of the book: ";
        cin >> numberOfCopies;
        cin.ignore();
    }

    void displayBook() const 
    {
        cout << "Book Title: " << bookTitle << "\n";
        cout << "Author: " << author << "\n";
        cout << "Number of Copies: " << numberOfCopies << "\n";
    }

    bool compareTitle(const string& title) const 
    {
        return bookTitle == title;
    }

    void add_newbooks(int additionalCopies) 
    {
        numberOfCopies += additionalCopies;
        cout << additionalCopies << " copies added. Total copies: " << numberOfCopies << "\n";
    }

    void issuebooks() 
    {
        if (numberOfCopies > 0) 
        {
            numberOfCopies--;
            cout << "Book issued successfully. Copies left: " << numberOfCopies << "\n";
        } else
       
        {
            cout << "Book out of stock.\n";
        }
    }

    void returnbooks() 
    {
        numberOfCopies++;
        cout << "Book returned successfully. Copies available: " << numberOfCopies << "\n";
    }
};

int main() 
{
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    cin.ignore();

    vector<Library> books(n);

    for (int i = 0; i < n; i++) 
    {
        cout << "\nEnter details for book " << i + 1 << ":\n";
        books[i].getinfo();
    }

    string command;
    while (true) 
    {
        cout << "\nEnter a command (display, add, issue, return, exit): ";
        getline(cin, command);

        if (command == "exit") 
        {
            break;
        } else if (command == "display") 
        {
            for (int i = 0; i < n; i++) 
            {
                cout << "\nBook " << i + 1 << " details:\n";
                books[i].displayBook();
            }
        } 
        else if (command == "add") 
        {
            cout << "Enter the title of the book to add copies: ";
            string title;
            getline(cin, title);
            for (int i = 0; i < n; i++) {
                if (books[i].compareTitle(title)) {
                    int copies;
                    cout << "Enter the number of copies to add: ";
                    cin >> copies;
                    cin.ignore();
                    books[i].add_newbooks(copies);
                    break;
                }
            }
        } 
        else if (command == "issue") 
        {
            cout << "Enter the title of the book to issue: ";
            string title;
            getline(cin, title);
            for (int i = 0; i < n; i++)
           {
                if (books[i].compareTitle(title)) 
                {
                    books[i].issuebooks();
                    break;
                }
            }
        } 
        else if (command == "return") 
        {
            cout << "Enter the title of the book to return: ";
            string title;
            getline(cin, title);
            for (int i = 0; i < n; i++) 
            {
                if (books[i].compareTitle(title)) 
                {
                    books[i].returnbooks();
                    break;
                }
            }
        } else {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
