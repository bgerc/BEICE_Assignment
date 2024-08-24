#include <iostream>
#include <limits>  // For numeric limits
using namespace std;

class Account {
protected:
    double balance;
    int accountNumber;

public:
    Account(double initialBalance = 0.0, int accNumber = 0)
        : balance(initialBalance), accountNumber(accNumber) {}

    virtual double getBalance() const {
        return balance;
    }

    virtual int getAccountNumber() const {
        return accountNumber;
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    virtual ~Account() {}

    virtual void getData() {
        cout << "Enter account number: ";
        while (!(cin >> accountNumber)) {
            cout << "Invalid input. Please enter a valid account number: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
        
        cout << "Enter initial balance: ";
        while (!(cin >> balance)) {
            cout << "Invalid input. Please enter a valid initial balance: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }
};

class SavingsAccount : public Account {
private:
    double withdrawalLimit;

public:
    SavingsAccount(double initialBalance = 0.0, int accNumber = 0, double withdrawalLimit = 0.0)
        : Account(initialBalance, accNumber), withdrawalLimit(withdrawalLimit) {}

    void withdraw(double amount) override {
        if (amount <= withdrawalLimit && amount <= balance) {
            Account::withdraw(amount);
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Withdrawal limit exceeded." << endl;
        }
    }

    void getData() override {
        Account::getData();
        cout << "Enter withdrawal limit: ";
        while (!(cin >> withdrawalLimit)) {
            cout << "Invalid input. Please enter a valid withdrawal limit: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftFee;

public:
    CheckingAccount(double initialBalance = 0.0, int accNumber = 0, double overdraftFee = 0.0)
        : Account(initialBalance, accNumber), overdraftFee(overdraftFee) {}

    void withdraw(double amount) override {
        if (amount <= getBalance()) {
            Account::withdraw(amount);
        } else {
            cout << "Overdraft fee applied." << endl;
            if (amount + overdraftFee <= getBalance()) {
                Account::withdraw(amount + overdraftFee);
            } else {
                cout << "Insufficient funds including overdraft fee." << endl;
            }
        }
    }

    void getData() override {
        Account::getData();
        cout << "Enter overdraft fee: ";
        while (!(cin >> overdraftFee)) {
            cout << "Invalid input. Please enter a valid overdraft fee: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
};

void withdrawFromAccount(Account& account, double amount) {
    account.withdraw(amount);
}

int main() {
    Account* account = nullptr;
    int choice;
    double amount;

    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display Balances\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        switch (choice) {
            case 1:
                delete account; // Free previously allocated memory
                account = new SavingsAccount();
                account->getData();
                cout << "Savings Account created successfully." << endl;
                break;

            case 2:
                delete account; // Free previously allocated memory
                account = new CheckingAccount();
                account->getData();
                cout << "Checking Account created successfully." << endl;
                break;

            case 3:
                if (account) {
                    cout << "Enter amount to deposit: ";
                    while (!(cin >> amount) || amount <= 0) {
                        cout << "Invalid input. Please enter a positive amount to deposit: ";
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    }
                    account->deposit(amount);
                    cout << "Deposited " << amount << " into the account." << endl;
                } else {
                    cout << "No account available to deposit money into." << endl;
                }
                break;

            case 4:
                if (account) {
                    cout << "Enter amount to withdraw: ";
                    while (!(cin >> amount) || amount <= 0) {
                        cout << "Invalid input. Please enter a positive amount to withdraw: ";
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    }
                    withdrawFromAccount(*account, amount);
                } else {
                    cout << "No account available to withdraw money from." << endl;
                }
                break;

            case 5:
                if (account) {
                    cout << "Account Number: " << account->getAccountNumber() << endl;
                    cout << "Account Balance: " << account->getBalance() << endl;
                } else {
                    cout << "No account available." << endl;
                }
                break;

            case 6:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
        }

    } while (choice != 6);

    delete account; 

    return 0;
}
