#include <iostream>
using namespace std;

class Account {
protected:
    double accountNumber;
    double balance;

public:
    virtual void getInput() = 0;
    virtual void deposit(double) = 0;
    virtual void withdraw(double) = 0;
    virtual void display() const = 0;
    virtual ~Account() {} // Virtual destructor for proper cleanup
};

class SavingAccount : public Account {
public:
    void getInput() override {
        cout << "\nEnter your account number and balance for Saving Account: ";
        cin >> accountNumber >> balance;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "\nAmount successfully deposited";
    }

    void withdraw(double amount) override {
        if (amount > 300000) {
            cout << "\nYou cannot withdraw such a large amount from this account";
        } else if (amount > balance) {
            cout << "\nInsufficient balance";
        } else {
            balance -= amount;
            cout << "\nAmount successfully withdrawn";
        }
    }

    void display() const override {
        cout << "\nSaving Account - Account No: " << accountNumber;
        cout << "\nBalance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    void getInput() override {
        cout << "\nEnter your account number and balance for Checking Account: ";
        cin >> accountNumber >> balance;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "\nAmount successfully deposited";
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "\nInsufficient balance";
        } else {
            balance -= amount;
            cout << "\nAmount successfully withdrawn";
        }
    }

    void display() const override {
        cout << "\nChecking Account - Account No: " << accountNumber;
        cout << "\nBalance: " << balance << endl;
    }
};

int main() {
    const int n = 2;
    Account* accounts[n];
    accounts[0] = new SavingAccount;
    accounts[1] = new CheckingAccount;

    cout << "\nEnter details for Saving Account and Checking Account:";

    for (int i = 0; i < n; ++i) {
        accounts[i]->getInput();

        double amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        accounts[i]->withdraw(amount);

        cout << "\nEnter amount to deposit: ";
        cin >> amount;
        accounts[i]->deposit(amount);

        accounts[i]->display();
    }

    for (int i = 0; i < n; ++i) {
        delete accounts[i];
    }

    return 0;
}
