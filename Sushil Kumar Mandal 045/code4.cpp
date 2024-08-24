#include<iostream>
using namespace std;
class Account
{
    protected:
    int AccNo;
    int balance;
    public:
    virtual void input()
    {
        cout<<"Enter Account number: "<<endl;
        cin>>AccNo;
        cout<<"Enter Balance: "<<endl;
        cin>>balance;
    }
    virtual void output()
    {
        cout<<"The Account number is: "<<AccNo<<endl;
        cout<<"The balance is: "<<balance<<endl;
    }
    };

class SavingAccount : public Account
{
int deposit;
void input()
{
    cout<<"Enter deposit amount in the bank:"<<endl;
    cin>>deposit;
    }
     void output()
    {
        cout<<"The deposit amount is:"<<deposit<<endl;
    }
};

class CheckingAccount : public Account
 {
    int withdraw;
public:
void input()
{
    Account::input();
    cout<<"Enter Withdraw amount in the bank:"<<endl;
    cin>>withdraw;
}
void output()
{
    cout<<" Withdraw amount is: "<<withdraw<<endl;
}
     };

int main()
{
    Account *acc;
    SavingAccount SA;
    CheckingAccount CA;
    
    acc=&SA;
    acc->input();
    acc->output();

    acc=&CA;
    acc->input();
    acc->output();

    return 0;

}