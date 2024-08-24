#include <iostream>
using namespace std;
class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    virtual void display() const {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds or invalid amount.\n";
        }
    }

    void display() const override {
        cout << "Savings Account\n";
        Account::display();
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds or invalid amount.\n";
        }
    }

    void display() const override {
        cout << "Checking Account\n";
        Account::display();
    }
};

int main() {
    Account* accounts[2];
    accounts[0] = new SavingsAccount("24680", 1000.00);
    accounts[1] = new CheckingAccount("13579",500.00);

    for (int i = 0; i < 2; ++i) {
        accounts[i]->display();
        accounts[i]->deposit(200.00);
        accounts[i]->withdraw(100.00);
        accounts[i]->display();
        delete accounts[i];
    }

    return 0;
}