#include <iostream>

class Account {
public:
    int accountNumber;
    double balance;

    Account(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    virtual void display() const {
        std::cout << "Account Number: " << accountNumber << ", Balance: " << balance << std::endl;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int accountNumber, double balance) : Account(accountNumber, balance) {}

    void deposit(double amount) override {
        balance += amount + (amount * 0.02); 
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accountNumber, double balance) : Account(accountNumber, balance) {}

    void withdraw(double amount) override {
        if (balance >= amount + 1.0) { 
            balance -= (amount + 1.0);
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }
};

void performTransaction(Account* account, double depositAmount, double withdrawAmount) {
    account->deposit(depositAmount);
    account->withdraw(withdrawAmount);
    account->display();
}

int main() {
    SavingsAccount savings(1001, 500.0);
    CheckingAccount checking(1002, 1000.0);

    performTransaction(&savings, 100.0, 50.0);
    performTransaction(&checking, 200.0, 150.0);

    return 0;
}
