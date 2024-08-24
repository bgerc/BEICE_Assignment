#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    Account(int accountNumber, double balance) 
        : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() const = 0;

    virtual ~Account() {}

protected:
    int accountNumber;
    double balance;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int accountNumber, double balance) 
        : Account(accountNumber, balance) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " into Savings Account " << accountNumber << "." << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Savings Account " << accountNumber << "." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings Account " << accountNumber << "." << endl;
        }
    }

    void display() const override {
        cout << "Savings Account " << accountNumber << ": Balance = $" << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accountNumber, double balance) 
        : Account(accountNumber, balance) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " into Checking Account " << accountNumber << "." << endl;
    }

    void withdraw(double amount) override {
        balance -= amount;
        cout << "Withdrew $" << amount << " from Checking Account " << accountNumber << "." << endl;
    }

    void display() const override {
        cout << "Checking Account " << accountNumber << ": Balance = $" << balance << endl;
    }
};

int main() {
    Account* accounts[2];

    accounts[0] = new SavingsAccount(1001, 500.0);
    accounts[1] = new CheckingAccount(2001, 300.0);

    accounts[0]->display();
    accounts[0]->deposit(100.0);
    accounts[0]->withdraw(50.0);
    accounts[0]->display();

    accounts[1]->display();
    accounts[1]->deposit(200.0);
    accounts[1]->withdraw(100.0);
    accounts[1]->display();

    for (int i = 0; i < 2; ++i) {
        delete accounts[i];
    }

    return 0;
}
