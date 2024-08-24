/* Assignment
    Create a base class Account with data members accountNumber and Balance.
    Derive two classes SavingsAccount and CheckingAccount from Account. 
    Implement polymorphic behavior where the base class pointer can point to objects of derived classes. 
    Call their respective member functions to deposit and withdraw money applying specific rules for each account type.
*/



/* 
    My execution logic for the program: 
        1) Savings Account have compounded interest rate at constant rate of 4% every year, here year corresponds to 15secs of program in runtime.
        2) Savings Account balance is variable in that manner.
        3) Savings Account have a transaction limit of 5 withdrawls per year, where year corresponds the same.
        4) Checking Account does not have any compounding interest rate and have a fixed balance and can be withdrawed at any time for any time.

        For calculating program execution duration runTime() function is made.
*/



#include <iostream>
#include <cstring>
#include <chrono>
#include <cmath>
using namespace std;
#define rate 0.04

auto programStartTime = chrono::high_resolution_clock::now();

// Function to return the amount of time since the program has been running.
double runTime() {
    // Getting the current time
    auto currentTime = chrono::high_resolution_clock::now();
    // Calculate the duration in seconds
    chrono::duration<double> duration = currentTime - programStartTime;
    return duration.count();
}



class Account
{
    protected: 
        long accountNumber;
        float balance;
    public:
        Account(long acc = 0, float bal = 0.0): accountNumber(acc), balance(bal) 
        {
        }

        virtual void withdraw(float amount) = 0;
        
        virtual void deposit(float amount) = 0;

        virtual void display()
        {
            cout << "\tAccount Number: " << accountNumber << endl << "\tCurrent Balance: " << balance << endl;
        }

        virtual ~Account()
        {
        }
};
class savingsAccount:public Account
{
    int withdrawCount;
    double executionTime;
    float interest;
    int temp_balance;
    public:
        savingsAccount(long acc, float bal): Account(acc, bal), withdrawCount(0), executionTime(runTime()), interest(0.0), temp_balance(bal)
        {}

        int compoundedInterest()
        {
            double currentTime = runTime();
            // 15 secs = 1 year
            // compound interest = balance * ( 1 + rate/ 1) ^ (1 * no of years);
            // No_of_years = current time - the time when the account was created (by constructor) / 15.
            int no_of_years = static_cast<int>((currentTime - executionTime) / 15);
            cout << no_of_years;
            int temp_balance = balance;
            if (no_of_years > 0)
            {
                balance = balance * (pow(rate + 1, no_of_years));
                // Updating execution time after every compounded interest to make that time new point.
                executionTime =  executionTime + no_of_years * 15; 
                // Interest
                return (balance - temp_balance);        
            }
            return 0;
        }

        void deposit(float amount)
        {
            compoundedInterest();
            balance += amount;
            cout << "\tSuccessfully deposited NRs. " << amount << " to your savings account." << endl << "\tCurrent Balance: NRs. " << balance << endl;
        }
        void withdraw(float amount)
        {
            compoundedInterest();
            if (withdrawCount > 5)
            {
                cout << endl << "\tYou have reached your maximum limit for this year. Withdrawl Failed." << endl;
                return;
            }
            if (balance < amount)
            {
                cout << endl <<  "\t Insufficient Balance. Withdrawl Failed." << endl;
            }
            else 
            {

                balance -= amount;
                withdrawCount++;
                cout << "\tSuccessfully withdrawl NRs. " << amount << " from your savings account." << endl << "\tCurrent Balance: NRs. " << balance << endl;
            }
        }
        void display()
        {
            compoundedInterest();
            interest = balance - temp_balance;
            cout << "\tAccount Number: " << accountNumber << endl << "\tCurrent Balance: " << balance << endl << "\tTotal interest: " << interest << endl;
        }
};
class checkingAccount:public Account
{
    public:
        checkingAccount(long acc, float bal): Account(acc, bal)
        {}

        void deposit(float amount)
        {
            balance += amount;   
            cout << "\tSuccessfully deposited NRs." << amount << " to your checking account." << endl << "\tCurrent Balance: NRs. " << balance << endl;
        }
        void withdraw(float amount)
        {
            int rem = balance - amount;
            if (rem < 500)
            {
                cout << endl << "\tMinimum balance in bank should be Rs. 500" << endl;
            }
            else 
            {
                balance = rem;
                cout << endl << "\tSuccessfully withdrew NRs. " << amount  << endl;
            }   
        }

};

int main()
{
    Account *account;
    long acc;
    float bal;

    bool check = true;
    while (check)
    {
        int n = 0;
        cout << "--- Welcome to CIN Nepal Bank ---" << endl;
        cout << endl <<  "Enter your account number: ";
        cin >> acc;
        cout << "Enter your account balance: ";
        cin >> bal;
        cout << endl << "Your account type? " << endl;
        cout << "1. Savings Account" << endl;
        cout << "2. Checkings Account" << endl;
        cout << endl << "Your choice: ";
        cin >> n;
        switch (n)
        {
            case 1:
                account = new savingsAccount(acc, bal);
                check = false;
                break;
            case 2:
                account = new checkingAccount(acc, bal);
                check = false;
                break;
            default:
                cout << "Invalid Choice. Please try again." << endl;
                break;
        }
    }

    while (true)
    {
        float amount;
        cout << "1. Withdraw Money" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. View Balance" << endl;
        cout << "4. Exit" << endl;
        int n = 0;
        cout << "Your choice: ";
        cin >> n;
        switch (n)
        {
            case 1:
                cout << endl << "Enter the amount you want to withdraw: NRs. ";
                cin >> amount;
                account -> withdraw(amount);
                break;
            case 2:
                cout << endl << "Enter the amount you want to deposit: NRs. ";
                cin >> amount;
                account -> deposit(amount);
                break;
            case 3:
                account -> display();
                break;
            case 4:
                cout <<  endl << "Exitting..." << endl;
                exit(0);
            default: 
                cout << "Invalid Input. Please try again." << endl;
        }
    }
    return 0;
}
