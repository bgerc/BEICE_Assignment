#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;

public:
    Account(int accountNumber, double balance = 0) : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << ". New balance is $" << balance << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << ". New balance is $" << balance << endl;
        }
    }
};

class SavingAccount : public Account
{
private:
    double interestRate;

public:
    SavingAccount(int accountNumber, double balance = 0, double interestRate = 0.05) : Account(accountNumber, balance), interestRate(interestRate) {}

    void deposit(double amount) override
    {
        Account::deposit(amount);
        double interest = amount * interestRate;
        balance += interest;
        cout << "Added $" << interest << " interest to account " << accountNumber << ". New balance is $" << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
        }
        else if (amount > 1000)
        {
            cout << "Withdrawal limit exceeded." << endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accountNumber, double balance = 0, double overdraftLimit = 1000) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override
    {
        if (amount > balance + overdraftLimit)
        {
            cout << "Overdraft limit exceeded." << endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }
};

int main()
{
    SavingAccount savingAccount(123, 1000);
    CheckingAccount checkingAccount(456, 500);

    Account *account1 = &savingAccount;
    Account *account2 = &checkingAccount;

    account1->deposit(500);
    account1->withdraw(200);

    account2->deposit(1000);
    account2->withdraw(1500);

    return 0;
}