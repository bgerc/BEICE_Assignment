#include<iostream>
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
        } 
        else 
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

    Library books[100];

    for (int i = 0; i < n; i++) 
    {
        cout << "\nEnter details for book " << i + 1 << ":\n";
        books[i].getinfo();
    }

    string title;
    int choice;
    while(true)
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Add new book" << endl;
        cout << "2. Issue a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Display available books" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        cin.ignore();
        
        switch(choice)
        {
            case 1:
                cout << "Enter the title of the book to add copies: ";
                getline(cin, title);
                for (int i = 0; i < n; i++)
                {
                    if (books[i].compareTitle(title)) 
                    {
                        int copies;
                        cout << "Enter the number of copies to add: ";
                        cin >> copies;
                        cin.ignore();
                        books[i].add_newbooks(copies);
                        break;
                    }
                }
                break;
            
            case 2:
                cout << "Enter the title of the book to issue: ";
                getline(cin, title);
                for (int i = 0; i < n; i++)
                {
                    if (books[i].compareTitle(title)) 
                    {
                        books[i].issuebooks();
                        break;
                    }
                }
                break;
            
            case 3:
                cout << "Enter the title of the book to return: ";
                getline(cin, title);
                for (int i = 0; i < n; i++) 
                {
                    if (books[i].compareTitle(title)) 
                    {
                        books[i].returnbooks();
                        break;
                    }
                }
                break;
        
            case 4:
                for (int i = 0; i < n; i++) 
                {
                    cout << "\nBook " << i + 1 << " details:\n";
                    books[i].displayBook();
                }
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
