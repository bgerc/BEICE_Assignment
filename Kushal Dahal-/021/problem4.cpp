#include <iostream>
using namespace std;

class Account 
{
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) = 0; 
    virtual void withdraw(double amount) = 0; 

    void display() 
     {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {} 
 };

class SavingAccount : public Account 
{
public:
    SavingAccount(int accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override 
    {
        balance += amount;
        cout << "Deposited " << amount << " into Saving Account." << endl;
    }

    void withdraw(double amount) override 
    {
        if (amount <= balance) 
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from Saving Account." << endl;
        } 
        else 
        {
         cout << "Insufficient funds in Saving Account." << endl;
        }
    }
 };

class CheckingAccount : public Account 
{
public:
    CheckingAccount(int accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override 
    {
        balance += amount;
        cout << "Deposited " << amount << " into Checking Account." << endl;
    }

    void withdraw(double amount) override 
    {
        double fee = 10.0; 
        if (amount + fee <= balance) {
            balance -= (amount + fee);
            cout << "Withdrew " << amount << " from Checking Account with a fee of:" << fee  << endl;
        }
         else
          {
            cout << "Insufficient funds in Checking Account." << endl;
        }
    }
 };

void performOperations(Account* acc)
 {
    int choice;
    double amount;

    do {
        cout << "\nSelect an operation:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc->deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc->withdraw(amount);
                break;

            case 3:
                acc->display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice... Please try again..." << endl;
                break;
        }
    } while (choice != 4);
}

int main() {
    int accountChoice;

    cout << "Select account to operate:\n";
    cout << "1. Saving Account\n";
    cout << "2. Checking Account\n";
    cout << "Enter your choice: ";
    cin >> accountChoice;

    Account* acc = nullptr;
    if (accountChoice == 1) {
        acc = new SavingAccount(1, 65000.0);
    } else if (accountChoice == 2) {
        acc = new CheckingAccount(2, 50000.0);
    } else {
        cout << "Invalid account choice." << endl;
        return 1;
    }
    performOperations(acc);
    delete acc;
    return 0;
}
