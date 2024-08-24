#include <iostream>

class Account
{
protected:
    std::string m_accountNumber;
    double m_balance;

public:
    Account() : m_balance{0} {}

    void setAccountNumber() {
        std::cout << "Enter account number: ";
        std::cin >> m_accountNumber;
    }

    virtual void deposit() = 0;
    virtual void withdraw() = 0;

    void display() {
        std::cout << "Account Number: " << m_accountNumber << std::endl;
        std::cout << "Balance: " << m_balance << std::endl;
    }
};

class SavingsAccount : public Account
{
public:
    void deposit() {
        std::cout << "Enter deposit amount: ";
        double deposit;
        std::cin >> deposit;
        m_balance += deposit;
    }

    void withdraw() {
        std::cout << "Enter withdraw amount: ";
        double withdraw;
        std::cin >> withdraw;
        if(withdraw <= m_balance) {
            m_balance -= withdraw;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    void deposit() {
        std::cout << "Enter deposit amount: ";
        double deposit;
        std::cin >> deposit;
        m_balance += deposit;
    }

    void withdraw() {
        std::cout << "Enter withdraw amount: ";
        double withdraw;
        std::cin >> withdraw;
        if(withdraw <= m_balance) {
            m_balance -= withdraw;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }
};

int main()
{   
    Account *aptr;

    int account;
    std::cout << "Account types:\n";
    std::cout << "1. Savings Account\n2. Checking Account\nEnter choice: ";
    std::cin >> account;

    if(account == 1) {
        aptr = new SavingsAccount;
    } else if (account == 2) {
        aptr = new CheckingAccount;
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    aptr -> setAccountNumber();
    aptr ->display();

    int choice;
    do {
        std::cout << "Choose: \n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                aptr -> deposit();
                break;
            case 2:
                aptr -> withdraw();
                break;
            case 3:
                aptr -> display();
                break;
            case 4:
                std::cout << "Exited!!";
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } while(choice != 4);

    

    return 0;
}