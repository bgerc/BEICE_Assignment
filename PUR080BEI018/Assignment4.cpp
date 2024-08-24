#include <iostream>
using namespace std;


class Account {
protected:
    int accountNumber;
    double balance;

public:

    Account(int accNo, double bal) : accountNumber(accNo), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs" << amount << " to account number " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from account number " << accountNumber << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: Rs" << balance << endl;
    }

    virtual ~Account() {}
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:

    SavingsAccount(int accNo, double bal, double rate) : Account(accNo, bal), interestRate(rate) {}


    void deposit(double amount) override {
        double interest = amount * interestRate / 100;
        balance += amount + interest;
        cout << "Deposited Rs" << amount << " with Rs" << interest << " interest to savings account number " << accountNumber << endl;
    }


    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Cannot withdraw Rs" << amount << " from savings account number " << accountNumber << ". Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from savings account number " << accountNumber << endl;
        }
    }


    void displayBalance() const override {
        cout << "Savings ";
        Account::displayBalance();
    }
};


class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:

    CheckingAccount(int accNo, double bal, double overdraft) : Account(accNo, bal), overdraftLimit(overdraft) {}


    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Cannot withdraw Rs" << amount << " from checking account number " << accountNumber << ". Overdraft limit exceeded!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from checking account number " << accountNumber << endl;
        }
    }


    void displayBalance() const override {
        cout << "Checking ";
        Account::displayBalance();
    }
};

int main() {
    int accountType;
    int accNo;
    double initialBalance;
    double interestRate;
    double overdraftLimit;
    double amount;

    Account* accountPtr = nullptr;

    cout << "Welcome to the Bank Account Management System" << endl;
    cout << "Please choose account type: 1. Savings Account 2. Checking Account: ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accNo;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    if (accountType == 1) {
        cout << "Enter interest rate (%): ";
        cin >> interestRate;
        accountPtr = new SavingsAccount(accNo, initialBalance, interestRate);
    } else if (accountType == 2) {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        accountPtr = new CheckingAccount(accNo, initialBalance, overdraftLimit);
    } else {
        cout << "Invalid account type selected!" << endl;
        return 1;
    }

    char choice;
    do {
        cout << "\nChoose an operation: " << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accountPtr->deposit(amount);
                break;

            case '2':
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                accountPtr->withdraw(amount);
                break;

            case '3':
                accountPtr->displayBalance();
                break;

            case '4':
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << " Please select a CORRECT option." << endl;
                break;
        }

    } while (choice != '4');


    delete accountPtr;

    return 0;
}

