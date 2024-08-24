/*Create a base class Account with data members and CheckingAccount from Account.Derive two classes SavingAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of derived classes and call their respective member function to deposit and withdraw money ,applying specific rules for each account type*/

#include <iostream>
#include <iomanip>
#include <memory>
#include <limits>

using namespace std;

// Abstract base class for Account
class Account {
protected:
    double balance;

public:
    Account(double initial_balance) : balance(initial_balance) {}

    // Pure virtual functions for deposit, withdraw, and display
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() const = 0;

    virtual ~Account() {} // Virtual destructor
};

// Derived class for SavingAccount with minimum balance requirement
class SavingAccount : public Account {
private:
    static constexpr double MINIMUM_BALANCE = 100.0;

public:
    SavingAccount(double initial_balance) : Account(initial_balance) {
        if (initial_balance < MINIMUM_BALANCE) {
            cout << "Initial balance is less than the required minimum of $" << MINIMUM_BALANCE << ". Setting balance to $" << MINIMUM_BALANCE << ".\n";
            balance = MINIMUM_BALANCE;
        }
    }

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into Savings Account.\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(double amount) override {
        if (amount > 0) {
            if ((balance - amount) >= MINIMUM_BALANCE) {
                balance -= amount;
                cout << "Withdrew " << amount << " from Savings Account.\n";
            } else {
                cout << "Insufficient balance. Withdrawal would reduce balance below the minimum required balance of $" << MINIMUM_BALANCE << ".\n";
            }
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void display() const override {
        cout << "Savings Account Balance: $" << fixed << setprecision(2) << balance << '\n';
    }
};

// Derived class for CheckingAccount with overdraft feature
class CheckingAccount : public Account {
private:
    double transactionFee;
    double overdraftLimit;

public:
    CheckingAccount(double initial_balance, double fee, double overdraft) 
        : Account(initial_balance), transactionFee(fee), overdraftLimit(overdraft) {}

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into Checking Account.\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(double amount) override {
        double totalDeduction = amount + transactionFee;
        if (amount > 0 && totalDeduction <= (balance + overdraftLimit)) {
            balance -= totalDeduction;
            cout << "Withdrew " << amount << " from Checking Account with a fee of $" << transactionFee << ".\n";
        } else {
            cout << "Insufficient funds or exceeds overdraft limit.\n";
        }
    }

    void display() const override {
        cout << "Checking Account Balance: $" << fixed << setprecision(2) << balance << '\n';
        cout << "Overdraft Limit: $" << fixed << setprecision(2) << overdraftLimit << '\n';
    }
};

// Function to handle account actions
void handleAccountActions(unique_ptr<Account>& account) {
    int action;
    double amount;
    int invalidCount = 0;

    while (true) {
        cout << "\nSelect action:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter choice (1-4): ";
        cin >> action;

        if(cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            if (++invalidCount >= 3) {
                cout << "Too many invalid attempts. Returning to Main Menu.\n";
                return;
            }
            continue;
        }

        switch (action) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if(cin.fail() || amount <= 0) {
                    cout << "Invalid amount. Please enter a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                account->deposit(amount);
                invalidCount = 0;
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if(cin.fail() || amount <= 0) {
                    cout << "Invalid amount. Please enter a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                account->withdraw(amount);
                invalidCount = 0;
                break;

            case 3:
                account->display();
                invalidCount = 0;
                break;

            case 4:
                return;

            default:
                cout << "Invalid action. Please choose again.\n";
                if (++invalidCount >= 3) {
                    cout << "Too many invalid attempts. Returning to Main Menu.\n";
                    return;
                }
                break;
        }
    }
}

// Main function to drive the program
int main() {
    unique_ptr<Account> currentAccount = nullptr;
    int choice;
    double initial_balance;
    double fee;
    double overdraft;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Exit\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 3.\n";
            continue;
        }

        switch (choice) {
            case 1:
                if (currentAccount) {
                    currentAccount.reset(); // Clean up existing account
                }
                cout << "Enter initial balance for Savings Account: ";
                cin >> initial_balance;
                if(cin.fail() || initial_balance < 0) {
                    cout << "Invalid initial balance. Please enter a non-negative number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                currentAccount = make_unique<SavingAccount>(initial_balance);
                handleAccountActions(currentAccount);
                break;

            case 2:
                if (currentAccount) {
                    currentAccount.reset(); // Clean up existing account
                }
                cout << "Enter initial balance for Checking Account: ";
                cin >> initial_balance;
                cout << "Enter transaction fee for Checking Account: ";
                cin >> fee;
                cout << "Enter overdraft limit for Checking Account: ";
                cin >> overdraft;

                if(cin.fail() || initial_balance < 0 || fee < 0 || overdraft < 0) {
                    cout << "Invalid input. Please ensure all values are non-negative numbers.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                currentAccount = make_unique<CheckingAccount>(initial_balance, fee, overdraft);
                handleAccountActions(currentAccount);
                break;

            case 3:
                return 0; // Exit the program

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
