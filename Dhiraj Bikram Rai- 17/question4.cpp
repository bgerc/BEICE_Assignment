#include<iostream>
using namespace std;

class Account
{
protected:
    double accountNumber;
    double balance;
public:
    virtual void getinput()
    {
        cout << " Enter the account number and balance: "<<endl;
        cin >> accountNumber >> balance;
    }
    virtual void deposit(double) = 0;
    virtual void withdraw(double) = 0;
    virtual void display() = 0;
    virtual ~Account() {}  
};

class SavingAccount : public Account
{
public:
    void deposit(double N) 
    {
        balance += N;
        cout << "  Amount successfully deposited in Saving Account."<<endl;
    }

    void withdraw(double N) 
    {
        
        if (N > balance)
            cout << " You don't have enough balance in Saving Account."<<endl;
        else
        {
            balance -= N;
            cout << " Amount successfully withdrawn from Saving Account."<<endl;
        }
    }

    void display() 
    {
        cout << " Saving Account Number: " << accountNumber<<endl;
        cout << " Balance: " << balance << endl;
    }
};

class CheckingAccount : public Account
{
public:
    void deposit(double N) 
    {
        balance += N;
        cout << " Amount successfully deposited in Checking Account."<<endl;
    }

    void withdraw(double N)
    {
        if (N > balance)
            cout << " You don't have enough balance in Checking Account."<<endl;
        else
        {
            balance -= N;
            cout << " Amount successfully withdrawn from Checking Account."<<endl;
        }
    }

    void display() 
    {
        cout << " Checking Account No.: " << accountNumber;
        cout << " Balance: " << balance << endl;
    }
};

int main()
{
    const int n = 2;
    Account* A[n];
    

    A[0] = new SavingAccount;
    A[1] = new CheckingAccount;

    cout << " Firstly enter account number and balance for Saving Account and then for Checking Account:"<<endl;
    
    for (int i = 0; i < n; i++)
    {
        A[i]->getinput();
        
        double withdrawAmount;
        cout << " Enter the amount you want to withdraw: ";
        cin >> withdrawAmount;
        A[i]->withdraw(withdrawAmount);
        
        double depositAmount;
        cout << " Enter the amount you want to deposit: ";
        cin >> depositAmount;
        A[i]->deposit(depositAmount);
        
        A[i]->display();
    }
    
  
    for (int i = 0; i < n; i++)
    {
        delete A[i];
    }
    
    return 0;
}
