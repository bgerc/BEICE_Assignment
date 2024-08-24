#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    double balance;

public:
    Account(const std::string& accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual ~Account() {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    void display() const {
        std::cout << "Account Number: " << accountNumber << "\nBalance: " << balance << std::endl;
    }

    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(const std::string& accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << " into Savings Account.\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew " << amount << " from Savings Account.\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << " into Checking Account.\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew " << amount << " from Checking Account.\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    }
};

void performOperations(Account* account) {
    int choice;
    double amount;

    do {
        std::cout << "\nChoose operation:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Display Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account->deposit(amount);
                break;

            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account->withdraw(amount);
                break;

            case 3:
                account->display();
                break;

            case 4:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    Account* savings = new SavingsAccount("12345", 1000.0);
    Account* checking = new CheckingAccount("67890", 500.0);

    int choice;

    do {
        std::cout << "\nSelect account type:\n";
        std::cout << "1. Savings Account\n";
        std::cout << "2. Checking Account\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                performOperations(savings);
                break;

            case 2:
                performOperations(checking);
                break;

            case 3:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    delete savings;
    delete checking;

    return 0;
}
