#include <iostream>
#include <stdexcept>
#define MAX 25
using namespace std;

class ACCOUNT {
protected:
    int account_Number[MAX];
    float Balance[MAX];

public:
    ACCOUNT() {
        for (int i = 0; i < MAX; ++i) {
            account_Number[i] = i + 1;
            Balance[i] = 0.0;
        }
    }
    virtual void deposit(int) = 0;
    virtual void withdraw(int) = 0;
    virtual void checkBalance(int) = 0;
};

class CHECKING_ACCOUNT : public ACCOUNT {
public:
    void deposit(int i) override {
        float depositAmount;
        cout << "-----------------------------------------" << endl;
        cout << "                DEPOSIT                  " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        Balance[i] += depositAmount;
        cout << "Deposit successful. New balance: " << Balance[i] << endl;
    }

    void withdraw(int i) override {
        float withdrawAmount;
        cout << "-----------------------------------------" << endl;
        cout << "                 WITHDRAW                 " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawAmount;
        try {
            if (withdrawAmount > Balance[i])
                throw withdrawAmount;
            Balance[i] -= withdrawAmount;
            cout << "Withdraw successful. New balance: " << Balance[i] << endl;
        } catch (float bal) {
            cout << "Insufficient balance" << endl;
        }
    }

    void checkBalance(int i) override {
        cout << "-----------------------------------------" << endl;
        cout << "         BALANCE IN CHECKING ACC.        " << endl;
        cout << "------------------------------------------" << endl;
        cout << "CURRENT BALANCE: " << Balance[i] << endl;
        cout << "------------------------------------------" << endl;
    }
};

class SAVING_ACCOUNT : public ACCOUNT {
public:
    void deposit(int i) override {
        float saving_deposit;
        cout << "-----------------------------------------" << endl;
        cout << "                DEPOSIT                  " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter the amount to deposit: ";
        cin >> saving_deposit;
        Balance[i] += saving_deposit;
        cout << "Deposit successful. New balance: " << Balance[i] << endl;
    }

    void withdraw(int i) override {
        float saving_withdraw;
        cout << "-----------------------------------------" << endl;
        cout << "                 WITHDRAW                 " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter the amount to withdraw: ";
        cin >> saving_withdraw;
        try {
            if (saving_withdraw > Balance[i]) throw saving_withdraw;
            Balance[i] -= saving_withdraw;
            cout << "Withdraw successful. New balance: " << Balance[i] << endl;
        } catch (float bal) {
            cout << "Insufficient balance" << endl;
        }
    }

    void checkBalance(int i) override {
        cout << "-----------------------------------------" << endl;
        cout << "                BALANCE                  " << endl;
        cout << "------------------------------------------" << endl;
        cout << "CURRENT BALANCE: " << Balance[i] << endl;
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    ACCOUNT* acc;
    SAVING_ACCOUNT sa;
    CHECKING_ACCOUNT ca;

    acc = &ca;
    acc->deposit(0);
    acc->withdraw(0);
    acc->checkBalance(0);

    acc = &sa;
    acc->deposit(1);
    acc->withdraw(1);
    acc->checkBalance(1);

    return 0;
}
