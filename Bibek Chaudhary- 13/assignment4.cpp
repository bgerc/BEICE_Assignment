#include <iostream>
using namespace std;


class Account {
protected:
    long int accountNumber;
    double balance;

public:
    Account(long int accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) = 0;  
    virtual void withdraw(double amount) = 0; 

    double checkBalance() const {
        return balance;
    }

    virtual void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs" << balance << endl;
    }

    virtual ~Account() {}  
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(long int accNum, double initialBalance, double rate)
        : Account(accNum, initialBalance), interestRate(rate) {}

    void deposit(double amount) override {
        if (amount >= 100) {  
            balance += amount;
            cout << "Savings Account: Amount deposited successfully. New balance: $" << balance << endl;
        } else {
            cout << "Savings Account: Deposit must be at least $100." << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount <= balance * 0.5) {  // Example condition: Can only withdraw up to 50% of balance
            balance -= amount;
            cout << "Savings Account: Amount withdrawn successfully. New balance: $" << balance << endl;
        } else {
            cout << "Savings Account: Cannot withdraw more than 50% of balance." << endl;
        }
    }

    void displayAccountDetails() const override {
        Account::displayAccountDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(long int accNum, double initialBalance, double fee)
        : Account(accNum, initialBalance), transactionFee(fee) {}

    void deposit(double amount) override {
        if (amount > 0) {  
            balance += amount;
            cout << "Checking Account: Amount deposited successfully. New balance: $" << balance << endl;
        } else {
            cout << "Checking Account: Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) override {
        double totalAmount = amount + transactionFee;
        if (totalAmount <= balance) {  
            balance -= totalAmount;
            cout << "Checking Account: Amount withdrawn successfully. New balance: $" << balance << endl;
        } else {
            cout << "Checking Account: Insufficient funds to cover withdrawal and transaction fee." << endl;
        }
    }

    void displayAccountDetails() const override {
        Account::displayAccountDetails();
        cout << "Transaction Fee: $" << transactionFee << endl;
    }
};

int main() {
    
    Account* account1 = new SavingsAccount(123456789, 1000.0, 5.0);
    Account* account2 = new CheckingAccount(987654321, 1500.0, 2.0);

    //  polymorphic behavior with SavingsAccount
    account1->displayAccountDetails();
    account1->deposit(150);  
    account1->withdraw(400);

    cout << "\n";

    // polymorphic behavior with CheckingAccount
    account2->displayAccountDetails();
    account2->deposit(50); 
    account2->withdraw(500); 

    cout << "\n";

    
    delete account1;
    delete account2;

    return 0;
}

