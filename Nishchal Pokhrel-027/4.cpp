#include <iostream>
using namespace std;

class Account
{
protected:
    double balance;
    int accountNumber;

public:
    Account(double initialBalance, int accNumber) : balance(initialBalance), accountNumber(accNumber)
    {
    }

    virtual double getBalance() const
    {
        return balance;
    }

    virtual int getAccountNumber() const
    {
        return accountNumber;
    }

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }

    virtual ~Account() {}

    virtual void getData()
    {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter initial balance: ";
        cin >> balance;
    }
};

class SavingsAccount : public Account
{
private:
    double withdrawalLimit;

public:
    SavingsAccount(double initialBalance = 0, int accNumber = 0, double withdrawalLimit = 0) : Account(initialBalance, accNumber), withdrawalLimit(withdrawalLimit)
    {
    }

    void withdraw(double amount) override
    {
        if (amount <= withdrawalLimit)
        {
            Account::withdraw(amount);
        }
        else
        {
            cout << "Withdrawal limit exceeded." << endl;
        }
    }

    void getData() override
    {
        Account::getData();
        cout << "Enter withdrawal limit: ";
        cin >> withdrawalLimit;
    }
};

class CheckingAccount : public Account
{
private:
    double overdraftFee;

public:
    CheckingAccount(double initialBalance = 0, int accNumber = 0, double overdraftFee = 0) : Account(initialBalance, accNumber), overdraftFee(overdraftFee) {}

    void withdraw(double amount) override
    {
        if (amount <= getBalance())
        {
            Account::withdraw(amount);
        }
        else
        {
            cout << "Overdraft fee applied." << endl;
            Account::withdraw(amount + overdraftFee);
        }
    }

    void getData() override
    {
        Account::getData();
        cout << "Enter overdraft fee: ";
        cin >> overdraftFee;
    }
};

void withdrawFromAccount(Account &account, double amount)
{
    account.withdraw(amount);
}

int main()
{
    Account *account = nullptr;
    int choice;
    double amountToWithdraw;

    do
    {

        cout << "\nBank Account Menu:\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display Balances\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            delete account;
            account = new SavingsAccount();
            account->getData();
            cout << "Savings Account created successfully." << endl;
            break;

        case 2:

            delete account;
            account = new CheckingAccount();
            account->getData();
            cout << "Checking Account created successfully." << endl;
            break;

        case 3:

            if (account)
            {
                cout << "Enter amount to deposit: ";
                cin >> amountToWithdraw;
                account->deposit(amountToWithdraw);
                cout << "Deposited " << amountToWithdraw << " into the account." << endl;
            }
            else
            {
                cout << "No account available to deposit money into." << endl;
            }
            break;

        case 4:

            if (account)
            {
                cout << "Enter amount to withdraw: ";
                cin >> amountToWithdraw;
                withdrawFromAccount(*account, amountToWithdraw);
            }
            else
            {
                cout << "No account available to withdraw money from." << endl;
            }
            break;

        case 5:

            if (account)
            {
                cout << "Account Number: " << account->getAccountNumber() << endl;
                cout << "Account Balance: " << account->getBalance() << endl;
            }
            else
            {
                cout << "No account available." << endl;
            }
            break;

        case 6:
            // Exit
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            break;
        }

    } while (choice != 6);

    delete account;

    return 0;
}
