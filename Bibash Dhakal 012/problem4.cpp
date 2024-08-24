/*Create a base classes Account with data members accountNumber and balalnce. Derive two classes SavingAccount and
CheckingAccount from Account. Implement polymorphic behaviour where the base classpointer can point to objects of 
derived classes, and call their respective member functions to deposit and withdraw money,applying secific rules for
each account type.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
protected:
    string accountNumber;
    string accountName;
    double balance;

public:
    Account(string number, string name, double initialBalance) : accountNumber(number), accountName(name), balance(initialBalance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    string getAccountNumber() const { return accountNumber; }
    string getAccountName() const { return accountName; }
    double getBalance() const { return balance; }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(string number, string name, double initialBalance) : Account(number, name, initialBalance) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Rs." << amount << " to Savings Account" << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= 1000)
        {
            balance -= amount;
            cout << "Withdrawn Rs." << amount << " from Savings Account" << endl;
        } else
        {
            cout << "Insufficient funds. Minimum balance of Rs.1000 required." << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(string number, string name, double initialBalance)
        : Account(number, name, initialBalance) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Rs." << amount << " to Checking Account" << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= 1000)
        {
            balance -= amount;
            cout << "Withdrawn Rs." << amount << " from Checking Account" << endl;
        } else
        {
            cout << "Insufficient funds. Minimum balance of Rs.1000 required." << endl;
        }
    }
};

void displayMenu()
{
    cout << "Bank Account Menu:" << endl;
    cout << "1. Add Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Display Account Information" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    vector<Account*> accounts;

    while (true)
    {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string number, name;
                double initialBalance;
                int accountType;

                cout << "Enter account number: ";
                cin >> number;
                cin.ignore();
                cout << "Enter account name: ";
                getline(cin, name);
                cout << "Enter initial balance (minimum Rs.1000): Rs.";
                cin >> initialBalance;

                if (initialBalance < 1000)
                {
                    cout << "Initial balance must be at least Rs.1000." << endl;
                    break;
                }

                cout << "Enter account type (1 for Savings, 2 for Checking): ";
                cin >> accountType;

                if (accountType == 1)
                {
                    accounts.push_back(new SavingsAccount(number, name, initialBalance));
                } else if (accountType == 2)
                {
                    accounts.push_back(new CheckingAccount(number, name, initialBalance));
                } else
                {
                    cout << "Invalid account type." << endl;
                }
                break;
            }
            case 2:
            {
                string number;
                double amount;
                cout << "Enter account number: ";
                cin >> number;
                cout << "Enter amount to deposit: Rs.";
                cin >> amount;

                bool found = false;
                for (Account* account : accounts)
                {
                    if (account->getAccountNumber() == number)
                    {
                        account->deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Account number not matched." << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                }
                break;
            }
            case 3:
            {
                string number;
                double amount;
                cout << "Enter account number: ";
                cin >> number;
                cout << "Enter amount to withdraw: Rs.";
                cin >> amount;

                bool found = false;
                for (Account* account : accounts)
                {
                    if (account->getAccountNumber() == number)
                    {
                        account->withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Account number not matched." << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                }
                break;
            }
            case 4:
            {
                for (Account* account : accounts)
                {
                    cout << "Account Number: " << account->getAccountNumber() << endl;
                    cout << "Account Name: " << account->getAccountName() << endl;
                    cout << "Balance: Rs." << account->getBalance() << endl;
                    cout << endl;
                }
                break;
            }
            case 5:
                for (Account* account : accounts)
                {
                    delete account;
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}