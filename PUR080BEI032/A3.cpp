#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class library
{
    char bookTitle[20][20];
    char author[20][20];
    int noCopy[20];
    //for invidual books
    int no_of_books;
    int count=0;

    char burrowed_Book[25][25];
    int amt_burrowed[25];
    public:
    void input()
    {
        cout<<"Enter the number of books to enter: ";
        cin>>no_of_books;
        for(int i=0;i<no_of_books;i++)
        {
            cout<<"Enter Book title:"<<endl;
            cin>>bookTitle[i];
            cout<<"Enter Author name: "<<endl;
            cin>>author[i];
            cout<<"Enter number of copies: "<<endl;
            cin>>noCopy[i];
        }
    }
    void display()
    {
        for(int i=0;i<no_of_books;i++)
        {
            cout<<"Book title is: "<<bookTitle[i]<<endl;
            cout<<"Author is: "<<author[i]<<endl;
            cout<<"No of copies is: "<<noCopy[i]<<endl;
        }
    }

  void issue()
  {
    char name[25];
    display();
    cout<<"Enter the book to burrow: ";
    cin>>name;
    for(int i=0;i<no_of_books;i++)
    {
        if(strcmp(name,bookTitle[i])==0)
        {
            strcpy(burrowed_Book[count],bookTitle[i]);
            cout<<"Enter the amount of books to burrow: ";
            cin>>amt_burrowed[count];

            noCopy[i]-=amt_burrowed[count];
            count++;
        }
    } 
  }
  void issue_display()
  {
    cout<<"Burrowed books: "<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"Name: "<<burrowed_Book[i]<<endl;
        cout<<"Amount: "<<amt_burrowed[i]<<endl;
    }
  }
  void ret_book()
  {
    char name[25];
    int ret_amt;
    cout<<"Enter the book to return: ";
    cin>>name;
    for(int i=0;i<count;i++)
    {
        if(strcmp(name,burrowed_Book[i])==0)
        {
            cout<<"Enter the amount to return: ";
            cin>>ret_amt;
            amt_burrowed[i]-=ret_amt;
            noCopy[i]+=ret_amt;
        }
    }
  }

};

int main()
{
    library l;
    int n;
    while(1)
    {
        cout<<"1. New Book"<<endl;
        cout<<"2. Display Available books"<<endl;
        cout<<"3. Issue Book"<<endl;
        cout<<"4. Display burrowed books"<<endl;
        cout<<"5. Return Book."<<endl;
        cout<<"6. Exit "<<endl;

        cout<<"Enter choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                system("cls");
               l.input();
                break; 
            }
            case 2:
            {
                system("cls");
                l.display();
                char c;
                cout<<"continue: ";
                cin>>c;
                break;
            }
            case 3:
            {
                system("cls");
                l.issue();
                break;
            }
            case 4:
            {
                system("cls");
                l.issue_display();
                break;
            }
            case 5:
            {
                system("cls");
                l.issue_display();
                l.ret_book();
                break;
            }
            default:
            {
                exit(0);
            }
            
        }
    }
    return 0;
}