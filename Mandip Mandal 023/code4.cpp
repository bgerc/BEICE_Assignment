// Question 4
#include <iostream>
#include <iomanip> 

using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    virtual ~Account() {} 

    virtual void deposit(double amount) = 0; 
    virtual void withdraw(double amount) = 0; 
    virtual void display() const = 0; 

    int getAccountNumber() const 
	{ 
		return accountNumber; 
	}
    double getBalance() const 
	{ 
		return balance; 
	}
};

class SavingAccount : public Account {
private:
     double interestRate = 0.03; 

public:
    SavingAccount(int accNum, double initialBalance) : Account(accNum, initialBalance) {}

    void deposit(double amount) override 
	{
        balance += amount;
        cout << "Deposited " << amount << " to Saving Account." << endl;
    }

    void withdraw(double amount) override 
	{
        if (amount > balance) 
		{
            cout << "Insufficient balance in Saving Account." << endl;
        } 
		else 
		{
            balance -= amount;
            cout << "Withdrew " << amount << " from Saving Account." << endl;
        }
    }

    void display() const override 
	{
        cout << "Saving Account Number: " << accountNumber << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
     double overdraftLimit = 500.00; 

public:
    CheckingAccount(int accNum, double initialBalance) : Account(accNum, initialBalance) {}

    void deposit(double amount) override 
	{
        balance += amount;
        cout << "Deposited " << amount << " to Checking Account." << endl;
    }

    void withdraw(double amount) override 
	{
        if (amount > (balance + overdraftLimit)) 
		{
            cout << "Exceeded overdraft limit in Checking Account." << endl;
        } 
		else 
		{
            balance -= amount;
            cout << "Withdrew " << amount << " from Checking Account." << endl;
        }
    }

    void display() const override 
	{
        cout << "Checking Account Number: " << accountNumber << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

Account* createAccount() {
    int choice;
    cout << "Enter 1 for Saving Account or 2 for Checking Account: ";
    cin >> choice;

    int accNum;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNum;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    if (choice == 1) 
	{
        return new SavingAccount(accNum, initialBalance);
    } 
	else if (choice == 2) 
	{
        return new CheckingAccount(accNum, initialBalance);
    } 
	else 
	{
        cout << "Invalid choice. Creating a default Saving Account." << endl;
        return new SavingAccount(accNum, initialBalance);
    }
}

void performOperations(Account *account) 
{
    int operation;
    double amount;

    while (true) 
	{
        cout << "\nChoose operation:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Info\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> operation;

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
                return;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}


int main() {
    Account *account = createAccount();
    performOperations(account);
    delete account;

    return 0;
}
