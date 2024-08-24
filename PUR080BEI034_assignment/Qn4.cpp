#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string accNum;
    double balance;

public:
    Account(string acc, double bal) : accNum(acc), balance(bal) {}
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void display() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account
{
    double interestRate;

public:
    SavingsAccount(string acc, double bal, double intRate) : Account(acc, bal), interestRate(intRate) {}

    void deposit()
    {
        double temp = 0;
        cout << "Enter the amount to deposit in Savings Account : ";
        cin >> temp;
        balance += temp;
        cout << "Rs." << temp << " has been deposited in your account." << endl;
    }

    void withdraw()
    {
        double temp = 0;
        cout << "Enter the amount to withdraw from Savings Account : ";
        cin >> temp;
        if (temp <= balance)
        {
            balance -= temp;
            cout << "Rs." << temp << " has been withdrawn from your account." << endl;
        }
        else
        {
            cout <<"Insufficient balance." << endl;
        }
    }

    void display()
    {
        cout << "Savings Account Number : " << accNum << endl;
        cout << "Balance : " << balance << endl;
        cout << "Interest Rate : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account
{
    double overLimit; 

public:
    CheckingAccount(string acc, double bal, double OL) : Account(acc, bal), overLimit(OL) {}

    void deposit()
    {
        double temp = 0;
        cout << "Enter the amount to deposit in Checking Account : ";
        cin >> temp;
        balance += temp;

        cout << "Rs." << temp << " has been deposited in your account." << endl;
    }

    void withdraw()
    {
        double temp = 0;
        cout << "Enter the amount to withdraw from Checking Account : ";
        cin >> temp;
        if (temp >= (balance + overLimit))
        {
            cout << "Overdraft limit exceeded." << endl;
        }
        else
        {
            balance -= temp;
            cout << "Rs." << temp << " has been withdrawn from your account." << endl;
        }
    }

    void display()
    {
        cout << "Checking Account Number : " << accNum << endl;
        cout << "Balance : " << balance << endl;
        cout << "Overdraft Limit : " << overLimit << endl;
    }
};

int main()
{
    Account *account = nullptr;
    string accNum;
    double balance, interestRate, overLimit;

    int choice, accountType;
    bool exit = false;

    while (!exit)
    {
        cout << "Account Type " << endl;
        cout << " 1. Savings Account \n 2. Checking Account\n 3. Exit " << endl;
        cout << "Select Account Type : ";
        cin >> accountType;
        cout << endl;

        if (accountType == 3)
        {
            cout << "Exiting..." << endl;
            exit = true;
            continue;
        }

        if (cin.fail() || accountType < 1 || accountType > 3)
        {
            cout << "Invalid input. Please select a valid option." << endl;
            continue;
        }
        if (accountType == 1 && dynamic_cast<SavingsAccount *>(account) == nullptr)
        {
            cout << "Enter Account Number : ";
            cin >> accNum;
            cout << "Enter Initial Balance : ";
            cin >> balance;
            cout << "Enter Interest Rate: ";
            cin >> interestRate;
            account = new SavingsAccount(accNum, balance, interestRate);
        }
        else if (accountType == 2 && dynamic_cast<CheckingAccount *>(account) == nullptr)
        {
            cout << "Enter Account Number : ";
            cin >> accNum;
            cout << "Enter Initial Balance : ";
            cin >> balance;
            cout << "Enter Overdraft Limit: ";
            cin >> overLimit;
            account = new CheckingAccount(accNum, balance, overLimit);
        }
 
        bool backToAccountType = false;

        while (!backToAccountType && !exit)
        {
            cout << "\nSelect Operations " << endl;
            cout << " 1. Deposit" << endl;
            cout << "2. Withdraw"<<endl;
            cout << "3. Display"<<endl;
            cout << "4. Back to Menu"<<endl;
            cout << "5. Exit"<<endl;
            cout << "Enter your choice : ";
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                account->deposit();
                break;
            case 2:
                account->withdraw();
                break;
            case 3:
                account->display();
                break;
            case 4:
                backToAccountType = true;
                break;
            case 5:
                cout << "Exiting..." << endl;
                cout << "Thank you for using our services." << endl;
                exit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    delete account;

    return 0;
}