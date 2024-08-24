#include <iostream>
using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;

public:
    Account() : balance{0} {}

    void setAccountNumber();
    void display();
    virtual void deposit() = 0;
    virtual void withdraw() = 0;

  
};

class SavingsAccount : public Account
{
public:
    void deposit() {
        cout << "Enter deposit amount: ";
        double deposit;
        cin >> deposit;
        balance += deposit;
    }

    void withdraw() {
        cout << "Enter withdraw amount: ";
        double withdraw;
        cin >> withdraw;
        if(withdraw <= balance) {
            balance -= withdraw;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    void deposit() {
        cout << "Enter deposit amount: ";
        double deposit;
        cin >> deposit;
        balance += deposit;
    }

    void withdraw() {
        cout << "Enter withdraw amount: ";
        double withdraw;
        cin >> withdraw;
        if(withdraw <= balance) {
            balance -= withdraw;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }
};

int main()
{   
    Account *aptr;

    int account;
    cout << "Account types:\n";
    cout << "1. Savings Account\n2. Checking Account\nEnter choice: ";
    cin >> account;

    if(account == 1) {
        aptr = new SavingsAccount;
    } else if (account == 2) {
        aptr = new CheckingAccount;
    } else {
        cout << "Invalid choice." << endl;
    }

    aptr -> setAccountNumber();
    aptr ->display();

    int choice;
    do {
        cout << "Choose: \n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                aptr -> deposit();
                break;
            case 2:
                aptr -> withdraw();
                break;
            case 3:
                aptr -> display();
                break;
            case 4:
                cout << "Exited!!";
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while(choice != 4);

    

    return 0;
}
void Account::setAccountNumber() {
        cout << "Enter account number: ";
        cin >> accountNumber;
    }
void Account::display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
