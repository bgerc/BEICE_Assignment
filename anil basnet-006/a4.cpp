/*Create a base class Account with data members account Number and balance

Derive two classes SavingsAccount and CheckingAccount from Account Implement polymorphic behavior where the base class pointer can point to objects of derived classes, and call their respective member functions to deposit and withdraw money, applying specific rules for each account type*/

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string& accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << "\n";
    }

    virtual void withdraw(double amount) = 0; 

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << "\n";
    }

    virtual ~Account() = default; 
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNum, double bal, double rate) : Account(accNum, bal), interestRate(rate) {}

    void deposit(double amount) override {
        balance += amount + (amount * interestRate / 100);
        cout << "Deposited: " << amount << " with interest, New Balance: " << balance << "\n";
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << "\n";
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void display() const override {
        cout << "Savings Account - ";
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double bal, double limit) : Account(accNum, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << "\n";
        } else {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void display() const override {
        cout << "Checking Account - ";
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }
};

int main() {
    Account* accounts[2];
    accounts[0] = new SavingsAccount("SA123", 1000.0, 5.0);
    accounts[1] = new CheckingAccount("CA456", 500.0, 200.0);

    for (int i = 0; i < 2; ++i) {
        accounts[i]->display();
        accounts[i]->deposit(100);
        accounts[i]->withdraw(200);
        accounts[i]->display();
        cout << "\n";
    }

    for (int i = 0; i < 2; ++i) {
        delete accounts[i];
    }

    return 0;
}
