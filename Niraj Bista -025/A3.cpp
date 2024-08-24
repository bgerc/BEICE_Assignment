#include<iostream>
#include<cstring>
#define MAX 25
using namespace std;

class Library
{
    char bookTitle[MAX][MAX];
    char author[MAX][MAX];
    int number_of_copies[MAX];
    int n,count=0;

    bool check=false;
    public:
    void add_book()
    {
        char temp_book[MAX];
        char temp_author[MAX];
        int temp_copies;
        int check_count=0;
  
        cout<<"Enter the number of books to add: ";
        do
        {
            cin>>n;
        }while(n<=0);
        cout<<"Enter the detail of each book: "<<endl;
        count+=n;
        for(int i=count-n;i<count;i++)
        {
            cout<<"Name of the book: ";
            cin.ignore();
            cin.getline(temp_book,MAX);
            check=false;

            //cheecking whether that book already exist
            for(int j=0;j<count;j++)
            {
                //if book altready exist it can add it
                if(strcmp(bookTitle[j],temp_book)==0)
                {
                    cout<<"Enter the number of copies: ";
                    cin>>temp_copies;
                    number_of_copies[j]+=temp_copies;
                    check=true;
                    check_count+=1;
                    
                    break;
                }
            }
            if(!check)
            {
                //if it doesnt detect nay book check is false
                strcpy(bookTitle[i],temp_book);
                cout<<"Author of the book: ";
                // cin.ignore();
                cin.getline(author[i],MAX);
                cout<<"Number of copies to enter: ";
                cin>>number_of_copies[i]; 
            } 
        }
        if(check)
        {
            //if it detects the book already existing, it delete the extra count for repeated book
            count-=check_count;
        }

    }
    void display()
    {
        if(count==0) cout<<"Empty"<<endl;
        cout<<"----------------------------------------"<<endl;
        for(int i=0;i<count;i++)
        {
            cout<<"Book ("<<i+1<<"): "<<endl;
            cout<<"Name of the book: "<<bookTitle[i]<<endl;
            cout<<"Author: "<<author[i]<<endl;
            cout<<"Total number of copies available: "<<number_of_copies[i]<<endl;
            cout<<"-------------------------------------------"<<endl;
        }
        char check;
        cout<<"Continue? [y/n]: ";
        cin>>check;
    }
    void issue()
    {
        char temp_char[MAX];
        int temp_copies;
        display();
        cout<<"Enter the name of Book to burrow: ";
        cin.ignore();
        cin.getline(temp_char,MAX);
        for(int i=0;i<count;i++)
        {
            if(strcmp(temp_char,bookTitle[i])==0)
            {
                cout<<"Enter the amount to burrow: ";
                cin>>temp_copies;
                if(temp_copies<=0 || temp_copies>number_of_copies[i]) throw(temp_copies);
                number_of_copies[i]-=temp_copies;

                cout<<"Succesfully Burrowed"<<endl;
            }
            else continue;
        }
    }
    void ret_book()
    {
        char temp[MAX];
        int temp_copies;
        display();
        cout<<"Enter the book to return :";
        cin.ignore();
        cin.getline(temp,MAX);
        for(int i=0;i<count;i++)
        {
            if(strcmp(temp,bookTitle[i])==0)
            {
                cout<<"Enter the amount to return: ";
                cin>>temp_copies;
                if(temp_copies<0 || temp_copies>number_of_copies[i]) throw (temp_copies);
                number_of_copies[i]+=temp_copies;
                cout<<"Return successfully"<<endl;
            }
        }
    }
};
int main()
{
    Library l;
    while(true)
    {
        int cho;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"               OPERATION TO PERFORM                     "<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"1.ADD BOOK"<<endl;
        cout<<"2.SHOW AVAILABLE BOOKS"<<endl;
        cout<<"3.ISSUE A BOOK"<<endl;
        cout<<"4.RETURN BOOK"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"Enter the choice: ";
        cin>>cho;
        system("clear");
        switch (cho)
        {
        case 1:
        {
            l.add_book();
            break;
        }
        case 2:
        {
            l.display();
            break;
        }
        case 3:
        {
            try
            {
                l.issue();
            }catch(int)
            {
                cout<<"LESS OR MORE BOOKS THAN SPECIFIED"<<endl;
            }
            break;
        }
        case 4:
        {
            try
            {
                l.ret_book();
            }catch(int) 
            {
                cout<<"LESS OR MORE BOOKS"<<endl;
            }
            break;
        }
        default:
            exit(0);
            break;
        }
    }
    return 0;
}