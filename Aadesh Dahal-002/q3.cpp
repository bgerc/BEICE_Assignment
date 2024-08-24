/*Define a class Library  with bookTitle, author and numberofCopies as data members. Implement 
methods to add new books, issue books and return books. Ensure that the number of copies is
appropriately  uploaded for each operation.*/

#include<iostream>
#include<cstring>
using namespace std;
class library
{
    private:
    char bookTitle[100];
    char author[100];
    int numberofcopies;

    public:
    void addbooks()
    {
        cout<<"Add new books!!!"<<endl;
        cout<<"Enter book details :"<<endl;
        cout<<"Book title: ";
        cin.ignore();
        cin.getline(bookTitle,100);
        cout<<"Author: ";
        cin.getline(author,100);
        cout<<"Number of copies: ";
        cin>>numberofcopies;
        cout<<endl;
        system("cls");
    }


    void issuebooks()
    {
        char b_title[50];
        char b_author[50];
        cout<<"ISSUE BOOKS"<<endl;
        cout<<"Enter book details you want to isssue:"<<endl;
        cout<<"Book title: ";
        cin.ignore();
        cin.getline(b_title,100);
        cout<<"Author: ";
        cin.getline(b_author,100);
        if(strcmp(strlwr(b_title),strlwr(bookTitle))==0&&strcmp(strlwr(b_author),strlwr(author))==0)
        {
        if (numberofcopies>0)
        {
        numberofcopies-=1;
        cout<<"BOOK ISSUED SUCCESSFULLY!!"<<endl;
        }
        else
        {
            cout<<"NOT ENOUGH COPIES!!!"<<endl;
        }
        }
        else{
            cout<<"NO BOOK FOUND!!!"<<endl;
        }

    }
    void returnbooks()
    {
    
        char b_title[50];
        char b_author[50];
        cout<<"RETURN BOOKS"<<endl;
        cout<<"Enter book details you want to return:"<<endl;
        cout<<"Book title: ";
        cin.ignore();
        cin.getline(b_title,100);
        cout<<"Author: ";
        cin.getline(b_author,100);
        if(strcmp(strlwr(b_title),strlwr(bookTitle))==0&&strcmp(strlwr(b_author),strlwr(author))==0)
        {
        numberofcopies+=1;
        cout<<"BOOK RETURNED SUCESSFULLY!!"<<endl;
        }
        else{
            cout<<"NO BOOK FOUND!!!"<<endl;
        }
    }

    void detailofbook()
    {
        cout<<bookTitle<<"\t\t"<<author<<"\t\t"<<numberofcopies<<endl;
    }
};

int main() {
    int bookcount=0;
    int option;
 
    library* l=nullptr;
    library* temp;
 
    char ch;
    while(true){
    cout<<endl<<"Enter the operation you want to perform:"<<endl;
    cout<<"a.Adding new books"<<endl<<"b.Issue books"<<endl<<"c.Return book"<<endl<<"d.Details of the book"<<endl<<"e.Exit"<<endl;
    cout<<"Enter code:";
    cin>>ch;
    system("cls");

    switch (ch)
    {

    case 'a':
    cout<<endl;
    temp = new library [bookcount+1];
    for(int i=0;i<bookcount;i++)
    {
        temp[i]=l[i];
    }
    delete[] l;
    l=temp;
    l[bookcount].addbooks();
    bookcount++;
        break;

    case 'b':
     cout<<endl;
     cout<<"Enter which book you want to issue: "<<endl;
     for(int i=0;i<bookcount;i++)
     {
        cout<<i+1<<".";
        l[i].detailofbook();
     }
        cout<<"Book code: ";
        cin>>option;
        l[option-1].issuebooks();

        break;

    case 'c':
     cout<<endl;
     cout<<"Enter which book you want to return: "<<endl;
     for(int i=0;i<bookcount;i++)
     {
        cout<<i+1<<".";
        l[i].detailofbook();
     }
        cout<<"Book code: ";
        cin>>option;
        l[option-1].returnbooks();
        break;

    case 'd':
    cout<<endl;
        cout<<"BOOK DETAILS!!!"<<endl;
        cout<<"Title: "<<"\t\t""Author :"<<"\t"<<"Number of copies: "<<endl;
       for(int i=0;i<bookcount;i++)
        {
        cout<<i+1<<".";
        l[i].detailofbook();
        }
        break;
    
    case 'e':
    cout<<endl;
    delete[] l;
    return 0;


    default:
    cout<<"Invalid option!!!"<<endl;
    break;
    }
    }
    return main();
}