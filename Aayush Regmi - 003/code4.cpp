#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountID;
    double currentBalance;

public:
    BankAccount(int id = 0, double balance = 0.0) : accountID(id), currentBalance(balance) {}

    virtual void credit(double amount) = 0;
    virtual void debit(double amount) = 0;
    virtual void showDetails() const {
        cout << "\n-----------------------------------------------------" << endl;
        cout << "Account ID: " << accountID << ", Current Balance: " << currentBalance << endl;
        cout << "-----------------------------------------------------" << endl;
    }

    virtual ~BankAccount(){};
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int id = 0, double balance = 0.0) : BankAccount(id, balance) {}

    void credit(double amount) override {
        currentBalance += amount + (amount * 0.02);
    }

    void debit(double amount) override {
        if (currentBalance >= amount) {
            currentBalance -= amount;
        } else {
            cout << "Not enough balance." << endl;
        }
    }

    void showDetails() const override {
        cout << "Savings ";
        BankAccount::showDetails();
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(int id = 0, double balance = 0.0) : BankAccount(id, balance) {}

    void credit(double amount) override {
        currentBalance += amount;
    }

    void debit(double amount) override {
        if (currentBalance < amount) {
            currentBalance -= (amount + 3500);
            cout << "Overdraft! An extra fee of Rs. 3500 has been charged." << endl;
        } else {
            currentBalance -= amount;
        }
    }

    void showDetails() const override {
        cout << "Current ";
        BankAccount::showDetails();
    }
};

int main() {
    BankAccount* accountPtr = nullptr;

    int id;
    double balance;
    cout << "\nEnter your account ID: ";
    cin >> id;
    cout << "Enter your current balance: ";
    cin >> balance;

    int accountType;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "Select account type: ";
    cin >> accountType;

    if (accountType == 1) {
        accountPtr = new SavingsAccount(id, balance);
    } else if (accountType == 2) {
        accountPtr = new CurrentAccount(id, balance);
    } else {
        cout << "Invalid selection." << endl;
        return 1;
    }

    while (true) {
        int option;
        cout << "\n1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Account Info" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1: {
            double amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            accountPtr->credit(amount);
            accountPtr->showDetails();
            break;
        }
        case 2: {
            double amount;
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            accountPtr->debit(amount);
            accountPtr->showDetails();
            break;
        }
        case 3: {
            accountPtr->showDetails();
            break;
        }
        case 4: {
            delete accountPtr;
            cout << "Exiting..." << endl;
            return 0;
        }
        default: {
            cout << "Invalid input." << endl;
        }
        }
    }

    return 0;
}
