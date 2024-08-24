#include<iostream>
using namespace std;
class Account
{
	protected:
    double accountNumber;
    double balance;
    public:
        void getinput()
        {
            cout<<"\nEnter the account number and balance of that account";
            cin>>accountNumber>>balance;
        }
        virtual void deposit (double)=0;
        virtual void withdraw (double)=0;
        virtual void display()=0;
};
class SavingAccount:public Account
{
   
    public:
        void getinput()
        {
            cout<<"\nenter your balance and account number";
            cin>>accountNumber>>balance;
        }
        void deposit(double N)
        {
            balance=balance+N;
            cout<<"\nAmount successfully deposited";
        }
        void withdraw(double N)
        {
            if(N>300000)
            cout<<"\nYou cannot withdraw such amount of money from this account";
            else if(N>balance)
            cout<<"\nYou dont have enough balance";
            else
            {
                balance=balance-N;
                cout<<"\nAmount successfully withdrawl";
            }
        }
          void display()
        {
            cout<<"\nAccount no.:\t"<<accountNumber;
            cout<<"\nBalance:\t"<<balance;
        }


};
class CheckingAccount: public Account
{
    
    public:
        void getinput()
        {
            cout<<"\nenter your balance and account number";
            cin>>accountNumber>>balance;
        }
        void deposit(double N)
        {
            balance=balance+N;
            cout<<"\nAmount successfully deposited";

        }
        void withdraw(double N)
        {
            if(N>balance)
            cout<<"\nYou dont enough balance";
            else{
            balance=balance-N;
             cout<<"\nAmount successfully withdrawl";
        }
        }    
        void display()
        {
            cout<<"\nAccount no.:\t"<<accountNumber;
            cout<<"\nBalance:\t"<<balance;
        }
};
int main()
{
	int n=2;
    Account *A[n];
    A[0] = new SavingAccount;
    A[1]=new CheckingAccount;
    cout<<"\nFirstly enter account number and balance of saving account and then of checking account";
    for(int i=0;i<n;i++)
    {
         A[i]->getinput();
        double N;
        cout<<"\nThe amount you want to withdraw";
        cin>>N;
        A[i]->withdraw(N);
        double Ni;
        cout<<"\nThe amount you want to deposit";
        cin>>Ni;
        A[i]->deposit(Ni);
        A[i]->display();
    }
    int i;
    for( i=0;i<n;i++)
    {
    delete A[i];}
    return 0;
}