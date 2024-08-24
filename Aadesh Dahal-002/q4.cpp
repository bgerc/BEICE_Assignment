/*Create a base class Account with data members accountNumber and balance. Derive two classes 
SavingsAccount and CheckingAccount from Account. Implement polymorphic behaviour where the base class 
pointer can point to the objects of derived classes, and call their respective member functions to 
deposit and withdraw money, applying specific rules for each account type.*/

#include<iostream>
using namespace std;

class Account
{
    protected:

    long int accountNumber;
    long int balance;

    public:

    virtual void add_account()
    {
        system("cls");
        cout<<"Enter the following details: "<<endl;
        cout<<"Account number: ";
        cin>>accountNumber;
        cout<<"Balance: ";
        cin>>balance;
    }

    virtual void deposit_money()=0;
    virtual void withdraw_money()=0;
    virtual void show_balance()=0;

    int acc_num()
    {
        return accountNumber;
    }
};

class SavingsAccount:public Account
{
    public:
    void deposit_money ()
    {
        system ("cls");
        int cash;
        cout<<"Depositing money!!!"<<endl;
        cout<<"Balance: ";
        cin>>cash;
        balance += cash;
    }
    void withdraw_money ()
    {
        system ("cls");
        int cash;
        cout<<"Withdrawing money!!!"<<endl;
        cout<<"Balance: ";
        cin>>cash;
        if(balance>=cash)
        {
            balance-=cash;
        }
        else
        {
            cout<<"Not enough cash!!!";
        }
    }
        
    void show_balance () 
    {
        system ("cls");
        cout << "Account number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

};

class CheckingAccount:public Account
{
    public:
    void deposit_money ()
    {
        system ("cls");
        int cash;
        cout<<"Depositing money!!!"<<endl;
        cout<<"Balance: ";
        cin>>cash;
        balance += cash;
    }
    void withdraw_money ()
    {
        system ("cls");
        int cash;
        cout<<"Withdrawing money!!!"<<endl;
        cout<<"Balance: ";
        cin>>cash;
        if(balance>=cash)
        {
            balance-=cash;
        }
        else
        {
            cout<<"Not enough cash!!!";
        }
    }
        
    void show_balance () 
    {
        system ("cls");
        cout << "Account number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    
};

int main() 
{
    Account** account=nullptr;
    Account** temp= nullptr;
    SavingsAccount* sa= nullptr;
    CheckingAccount* ca= nullptr;
    int account_count = 0;
    long int acc_num;
    while(true){
    cout<<"Enter your choice of operation: "<<endl;
    cout<<"a.Add savings account"<<endl;
    cout<<"b.Add checking account"<<endl;
    cout<<"c.Withdraw account"<<endl;
    cout<<"d.Desposit account"<<endl;
    cout<<"e.Show balance"<<endl;
    cout<<"f.exit"<<endl;
    char choice;
    cout<<"Enter choice: ";
    cin>>choice;

    switch (choice)
    {
        default:
        cout<<"Enter correct option!!!"<<endl;
        break;

        case 'f':
        cout<<"Exited sucessfully!!!"<<endl;
        for(int i=0;i<account_count;i++)
        {
            delete account[i];
        }
        delete []account;
        return 0;
        break;

    case 'a':
    sa = new SavingsAccount();
    sa->add_account();
    temp = new Account*[account_count+1];
    for(int i=0;i<account_count;i++)
    {
        temp[i]=account[i];
    }
    temp[account_count]=sa;
    delete []account;
    account=temp;
    account_count++;
        break;

    case 'b':
    ca = new CheckingAccount();
    ca->add_account();
    temp = new Account*[account_count+1];
    for(int i=0;i<account_count;i++)
    {
        temp[i]=account[i];
    }
    temp[account_count]=ca;
    delete []account;
    account=temp;
    account_count++;
        break;
        case 'c':
        case 'd':
        case 'e':
        
        cout<<"Enter account number:";
        cin>>acc_num;
        bool found;
        for(int i=0;i<account_count;i++)
        {
            if(account[i]->acc_num()==acc_num)
            {
                cout<<"Welcome!!!"<<endl;
                found= true;
                switch (choice)
                {
                case 'c':
                account[i]->withdraw_money();
                    break;

                case 'd':
                account[i]->deposit_money();
                break;

                case 'e':
                account[i]->show_balance();
                break;
                }

            }
            break;

        }
        if(!found)
        {
            cout<<"Account not found!!!";
        }

    }
    }
}

