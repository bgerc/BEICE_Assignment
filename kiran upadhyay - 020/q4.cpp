#include <iostream>
#include <iomanip> 

using namespace std;


class Account {
protected:
    string accountNumber;
    double balance;

public:
 
    Account(const string& accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual ~Account() {}

    virtual void deposit(double amount) = 0;

    virtual void withdraw(double amount) = 0;

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: rs" << fixed << setprecision(2) << balance << endl;
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:

    SavingsAccount(const string& accNum, double bal, double rate)
        : Account(accNum, bal), interestRate(rate) {}

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: rs" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: rs" << amount << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal." << endl;
        }
    }

    void display() const override {
        Account::display();
        cout << "Interest Rate: " << fixed << setprecision(2) << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
   
    CheckingAccount(const string& accNum, double bal, double limit)
        : Account(accNum, bal), overdraftLimit(limit) {}

 
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: rs" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }


    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew: rs" << amount << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal." << endl;
        }
    }

    void display() const override {
        Account::display();
        cout << "Overdraft Limit: rs" << fixed << setprecision(2) << overdraftLimit << endl;
    }
};

int main() {

    Account* account1 = new SavingsAccount("A12345", 5000.00, 2.5);
    Account* account2 = new CheckingAccount("B67890", 1500.00, 500.00);

    cout << "Savings Account Details:" << endl;
    account1->display();
    cout << endl;

    cout << "Checking Account Details:" << endl;
    account2->display();
    cout << endl;

    account1->deposit(5000.00);
    account1->withdraw(1500.00);
    account1->display();
    cout << endl;

    account2->deposit(1000.00);
    account2->withdraw(2000.00);
    account2->display();
    cout << endl;

    
    delete account1;
    delete account2;

    return 0;
}
