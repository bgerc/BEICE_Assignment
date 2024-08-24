/*Create a base class Account with data members accountNumber and balance.
Derive two classes SavingsAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of derived classes,
 and call their respective member functions to deposit and withdraw money, 
 applying specific rules for each account type.*/

#include <iostream>
#include <iomanip>

using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

protected:
    Account(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

public:
    virtual ~Account() = default;

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited Nrs " << fixed << setprecision(2) << amount << " to Account #" << accountNumber << "." << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance in Account #" << accountNumber << "." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Nrs " << fixed << setprecision(2) << amount << " from Account #" << accountNumber << "." << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Nrs " << fixed << setprecision(2) << balance << endl;
    }

    double getBalance() const { return balance; }
    int getAccountNumber() const { return accountNumber; }
};

class SavingAccount : public Account 
{
private:
    static constexpr double interestRate = 0.04;

public:
    SavingAccount(int accNum, double initialBalance) : Account(accNum, initialBalance) {}

    void deposit(double amount) override 
    {
        Account::deposit(amount);
        double interest = getBalance() * interestRate;
        Account::deposit(interest);
        cout << "Interest of Nrs " << fixed << setprecision(2) << interest << " applied in Saving Account." << endl;
    }

    void display() const override 
    {
        Account::display();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

class CheckingAccount : public Account 
{
private:
    static constexpr double overdraftLimit = 500.00;

public:
    CheckingAccount(int accNum, double initialBalance) : Account(accNum, initialBalance) {}

    void withdraw(double amount) override 
    {
        if (amount > (getBalance() + overdraftLimit)) 
        {
            cout << "Exceeded overdraft limit in Checking Account #" << getAccountNumber() << "." << endl;
        } else 
        {
            Account::withdraw(amount);
        }
    }

    void display() const override 
    {
        Account::display();
        cout << "Overdraft Limit: Nrs " << overdraftLimit << endl;
    }
};

Account* createAccount() 
{
    int choice;
    int accNum;
    double initialBalance;

    cout << "Enter 1 for Saving Account or 2 for Checking Account: ";
    cin >> choice;

    cout << "Enter account number: ";
    cin >> accNum;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    switch (choice) 
    {
        case 1:
            return new SavingAccount(accNum, initialBalance);
        case 2:
            return new CheckingAccount(accNum, initialBalance);
        default:
            cout << "Invalid choice. Creating a default Saving Account." << endl;
            return new SavingAccount(accNum, initialBalance);
    }
}

void performOperations(Account* account) 
{
    bool running = true;

    while (running) 
    {
        cout << "\nChoose operation:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Info\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        int operation;
        cin >> operation;

        double amount;

        switch (operation) 
        {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                break;

            case 3:
                account->display();
                break;

            case 4:
                cout << "Exiting operations." << endl;
                running = false;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

int main() 
{
    Account* account = createAccount();
    performOperations(account);
    delete account;

    return 0;
}

