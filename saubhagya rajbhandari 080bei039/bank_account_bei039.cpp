#include <iostream>
#include <string>
#include <limits> // for numeric_limits
using namespace std;

class Account
{
protected:
    string accountnum;
    double balance;

public:
    Account(string acc, double bal) : accountnum(acc), balance(bal) {}
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void display() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account
{
    double interrate;

public:
    SavingsAccount(string acc, double bal, double intRate) : Account(acc, bal), interrate(intRate) {}

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
            cout << "Insufficient balance.please try again." << endl;
        }
    }

    void display()
    {
        cout << "Savings Account Number : " << accountnum << endl;
        cout << "Balance : " << balance << endl;
        cout << "Interest Rate : " << interrate << "%" << endl;
    }
};

class CheckingAccount : public Account
{
    double overlim;
                     

public:
    CheckingAccount(string acc, double bal, double OL) : Account(acc, bal), overlim(OL) {}

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
        if (temp >= (balance + overlim))
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
        cout << "Checking Account Number : " << accountnum << endl;
        cout << "Balance : " << balance << endl;
        cout << "Overdraft Limit : " << overlim << endl;
    }
};

int main()
{
    Account *account = nullptr;
    string accountnum;
    double balance, interrate, overlim;

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
            cout << "exit." << endl;
            exit = true;
            continue;
        }

       
       

       
        if (accountType == 1 && dynamic_cast<SavingsAccount *>(account) == nullptr)
        {
            cout << "Enter Account Number : ";
            cin >> accountnum;
            cout << "Enter Initial Balance : ";
            cin >> balance;
            cout << "Enter Interest Rate: ";
            cin >> interrate;
            account = new SavingsAccount(accountnum, balance, interrate);
        }
        else if (accountType == 2 && dynamic_cast<CheckingAccount *>(account) == nullptr)
        {
            cout << "Enter Account Number : ";
            cin >> accountnum;
            cout << "Enter Initial Balance : ";
            cin >> balance;
            cout << "Enter Overdraft Limit: ";
            cin >> overlim;
            account = new CheckingAccount(accountnum, balance, overlim);
        }

        bool backToAccountType = false;
       

        while (!backToAccountType && !exit)
        {
            cout << "\nSelect Operations " << endl;
            cout << " 1. Deposit \n 2. Withdraw \n 3. Display \n 4. Back to Menu \n 5. Exit " << endl;
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
                // if there is a invalid input of some alphabets, the program runs in infinte loop,
                // which can be a problem, that's why below code is used.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid operation. Try again." << endl;
                break;
            }
        }
    }

    delete account;

    return 0;
}