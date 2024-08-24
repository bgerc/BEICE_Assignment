#include <iostream>
using namespace std;

class Account {
protected:
    int AccountNumber;
    double balance;

public:
    Account(int AccNo = 0, double bal = 0.0) : AccountNumber(AccNo), balance(bal) {}

    virtual void deposit(double amt) = 0;
    virtual void withdraw(double amt) = 0;
    virtual void display() const {
        cout<<"\n-----------------------------------------------------"<<endl;
        cout << "Account Number: " << AccountNumber << ", Balance: " << balance << endl;
        cout<<"-----------------------------------------------------"<<endl;
    }

    virtual ~Account() = default;
};

class SavingAccount : public Account {
public:
    SavingAccount(int accNo = 0, double bal = 0) : Account(accNo, bal) {}

    void deposit(double amt) {
        balance += amt + (amt * 0.02);
    }

    void withdraw(double amt) {
        if (balance >= amt) {
            balance -= amt;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void display() const {
        cout << "Saving ";
        Account::display();
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo = 0, double bal = 0) : Account(accNo, bal) {}

    void deposit(double amt) {
        balance += amt;
    }

    void withdraw(double amt) {
        if (balance < amt) {
            balance -= (amt + 3500);
            cout << "Since you have insufficient balance, you are charged an overdraft fee of Rs. 3500" << endl;
        } else {
            balance -= amt;
        }
    }

    void display() const {
        cout << "Checking ";
        Account::display();
    }
};

int main() {
    Account* Acc = nullptr;

    int accNo;
    double bal;
    cout << "\nEnter your account number: ";
    cin >> accNo;
    cout << "Enter balance: ";
    cin >> bal;
    int n;

    cout << "1. Saving Account" << endl;
    cout << "2. Checking Account" << endl;
    cout << "Enter choice: ";
    cin >> n;
    if (n == 1) {
        Acc = new SavingAccount(accNo, bal);
    } else if (n == 2) {
        Acc = new CheckingAccount(accNo, bal);
    } else {
        cout << "Invalid choice" << endl;
        return 1; 
    }

    while (true) {
        int i;
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account Info" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> i;
        switch (i) {
        case 1: {
            double amt;
            cout << "Enter amount you want to deposit: ";
            cin >> amt;
            Acc->deposit(amt);
            Acc->display();
            break;
        }
        case 2: {
            double amt;
            cout << "Enter amount you want to withdraw: ";
            cin >> amt;
            Acc->withdraw(amt);
            Acc->display();
            break;
        }
        case 3: {
            Acc->display();
            break;
        }
        case 4: {
            delete Acc;
            cout << "Exiting..." << endl;
            return 0;
        }
        default: {
            cout << "Invalid input!!" << endl;
        }
        }
    }

    return 0;
}
