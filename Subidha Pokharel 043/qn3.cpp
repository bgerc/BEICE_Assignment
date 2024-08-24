#include <iostream>
#include <string>
using namespace std;

class Library
{
private:
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    Library(string bookTitle, string author, int numberOfCopies) : bookTitle(bookTitle), author(author), numberOfCopies(numberOfCopies) {}

    void addBook(int copies)
    {
        numberOfCopies += copies;
        cout << copies << " copies of " << bookTitle << " by " << author << " added to the library. Total copies: " << numberOfCopies << endl;
    }

    bool issueBook()
    {
        if (numberOfCopies > 0)
        {
            numberOfCopies--;
            cout << bookTitle << " by " << author << " issued. Remaining copies: " << numberOfCopies << endl;
            return true;
        }
        else
        {
            cout << "No copies of " << bookTitle << " by " << author << " available." << endl;
            return false;
        }
    }

    void returnBook()
    {
        numberOfCopies++;
        cout << bookTitle << " by " << author << " returned. Total copies: " << numberOfCopies << endl;
    }
};

int main()
{
    Library library("The Great Gatsby", "F. Scott Fitzgerald", 10);

    library.addBook(5);
    library.issueBook();
    library.returnBook();

    return 0;
}