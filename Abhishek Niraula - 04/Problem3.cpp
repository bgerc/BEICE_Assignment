/* Assignment
    
    Define a class Library with bookTitle, author and numberOfCopies as data members. 
    Implement methods to add new books, issue books and return books.
    Ensure that the number of copeis is appropriately update for each operation.
*/

#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

// For true data hiding a new class is created.
class Book
{
    char bookTitle[100];
    char author[100];
    unsigned int numberOfCopies;
    unsigned int issueCount;
    public:
        Book()
        {
            bookTitle[0] = '\0';
            author[0] = '\0';
            numberOfCopies = 0;
            issueCount = 0;
        }

        Book(char title[], char auth[], int copies){
            strcpy(bookTitle, title);
            strcpy(author, auth);
            numberOfCopies = copies;
            issueCount = 0;
        }

        void addCopies(int copies) 
        {
            numberOfCopies += copies;
        }

        void issueBook() {
            if (numberOfCopies > 0) {
                numberOfCopies--;
                issueCount++;
                cout << "\tBook issued successfully." << endl;
            }
            else
            {
                cout << "\tNot enough copies. Issue Failed." << endl;
            }
            cout << endl << "Redirecting to home page..." << endl;
        }

        void returnBook() {
            numberOfCopies++;
            issueCount--;
            cout << "\tReturned book successfully." << endl;
            cout << endl << "Redirecting to home page..." << endl;
        }

        void displayBook() {
            cout << endl <<"\tTitle: " << bookTitle << endl << "\tAuthor: " << author << endl << "\tCopies: " << numberOfCopies << endl;
        }
        
        void displayIssue() {
            cout << endl <<"\tTitle: " << bookTitle << endl << "\tAuthor: " << author << endl << "\tTotal Number of Copies Issued: " << issueCount << endl;
        }

        bool exists(char title[]) {
            return (strcmp(bookTitle, title) == 0);
        }
        int issues()
        {
            return issueCount;
        }
        ~Book()
        {}
};

class Library
{
    // Total Number of books in a library.
    
    Book *books;
    unsigned int book_count;
    unsigned int total_issue_count;

    public:
        Library()
        {
            books = nullptr;
            book_count = 0;
            total_issue_count = 0;
        }
        int add_book()
        {
            char name[100], auth[100];
            int num;
            cout << "\tEnter the name of book: ";
            cin.ignore();
            cin.getline(name, 100);
            cout << "\tEnter " << name << "'s author: ";
            cin.getline(auth, 100);
            cout << "\tEnter number of copies you want to register: ";
            cin >> num;
            for (int i = 0; i < book_count; i++)
            {
                if (books[i].exists(name))
                {
                    char c;
                    cout << "\tThe entered book already exists." << endl << "Do you want to register additional copies of " << name << "?(Y/N)" << endl;
                    cin >> c;
                    if (c == 'Y' || c == 'y')
                    {
                        books[i].addCopies(num);
                        return 0;
                    }
                    else 
                    {
                        cout << endl << "Redirecting to home page..." << endl;
                        return 0;
                    }
                }
            }
            // This part of code is referenced from CHATGPT for dynamic memory allocation.
            // A new temporary variable is created with 1 extra space and all of the books data is copied to it and one additional data is place which is then copied to original books pointer.
            // Dynamic Memory Allocation
            Book *temp = new Book[book_count + 1];
            for (int i = 0; i < book_count; i++)
            {
                temp[i] = books[i];
            }
            temp[book_count] = Book(name, auth, num);
            delete[] books;
            books = temp;
            book_count++;
            cout << "\tAdded books successfully." << endl;
            cout << endl << "Redirecting to home page..." << endl;
            return 0;
        }

        void issue_book()
        {
            char name[100];
            int num;
            cout << endl << "\tEnter the name of book you want to issue: ";
            cin.ignore();
            cin.getline(name, 100);
            for (int i = 0; i < book_count; i++)
            {
                if (books[i].exists(name))
                {
                    total_issue_count++;
                    books[i].issueBook();    
                    return;
                }
            }
            cout << "\tNo such book in library." << endl;
            cout << endl << "Redirecting to home page..." << endl;
            return;
        }
        void return_book() {
            char name[100];
            cout << "\tEnter the name of book you want to return: ";
            cin.ignore();
            cin.getline(name, 100);
            if (total_issue_count > 0)
            {
                for (int i = 0; i < book_count; ++i) {
                    if (books[i].exists(name)) {
                        books[i].returnBook();
                        return;
                    }
                }
            }
            else {
                cout << "\tNo current issues in library." << endl;
            }
            
            cout << "\t \"" << name << "\" have no record of being issued from library." << endl;
            cout << endl <<  "Redirecting to home page..." << endl;
            return;
        }
        void display_library() {
            if (book_count == 0)
            {
                cout << "\tThere are no books in library." << endl;
                cout << endl << "Redirecting to home page..." << endl;
            }
            else
            {
                cout << "Available Books." << endl << endl;
                for (int i = 0; i < book_count; i++) {
                    cout << endl << "\t" << i + 1 << endl;
                    books[i].displayBook();
                }
            }
            
        }
        void view_issue()
        {
            int flag = 0;
            for (int i = 0; i < book_count; i++)
            {
                if (books[i].issues() > 0)
                {
                    books[i].displayIssue();
                    flag++;
                }
            }
            if (flag == 0)
            {
                cout << "\tNo current issues from library." << endl;
            }
        }
        ~Library()
        {
            delete[] books;
        }
};
int main()
{
    Library  library;
    int n;

    while (true)
    {
        cout << endl << "Press any key" <<  endl;
        char c = _getch();
        cout << "Welcome to IOE Purwanchal Library" << endl << endl;

        cout << "----Available Operations----" << endl;
        cout << "1. See available books in library" << endl;
        cout << "2. Add New Books" << endl;
        cout << "3. Issue Books" << endl;
        cout << "4. Return Books" << endl;
        cout << "5. View Current Issues" << endl;
        cout << "6. Exit" << endl;
        cin.ignore();
        cout << endl << "Enter your choice: ";
        cin >> n;
        cout << endl;
        switch(n)
        {
            case 1:
                library.display_library();
                break;
            case 2: 
                library.add_book();
                break;
            case 3:
                library.issue_book();
                break;
            case 4:
                library.return_book();
                break;
            case 5:
                library.view_issue();
                break;
            case 6:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid Choice. Please try again OR Press 5 to exit."<< endl;           
        }
    }
    

}