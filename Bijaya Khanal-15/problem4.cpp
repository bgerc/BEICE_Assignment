
#include<iostream>
using namespace std;
class Account
{
    protected:
    int AccountNumber;
    double balance;
    public:
    Account(int AccNo=0, double balnc=0.0):AccountNumber(AccNo),balance(balnc){}
    virtual void deposit(double amt)=0;
    virtual void withdraw(double amt)=0;
    virtual void display()=0;
    {
        cout << "Account Number: " << AccountNumber << ", Balance: " << balance << endl;
    }
};
class SavingAccount: public Account
{
    private:
    public:
    SavingAccount(int accNo=0, double balnc=0):Account(accNo,balnc){}
    void deposit(double);
    void withdraw(double);

};
void SavingAccount::deposit(double amt)
{
    balance=balance+amt+(amt*0.02);
}

void SavingAccount::withdraw(double amt)
{
    if(balance>=amt)
    {
        balance-=amt;
    }
    else
    {
        cout<<"Insufficient balance"<<endl;
    }
}

class CheckingAccount: public Account
{
    private:
    public:
    CheckingAccount(int accNo=0, double balnc=0):Account(accNo,balnc) {}
    void deposit(double);
    void withdraw(double);
};
void CheckingAccount::deposit(double amt)
{
    balance=balance+amt;
}
void CheckingAccount::withdraw(double amt)
{
    if(balance<amt)
    {
        balance-=(amt+3500);
        cout<<"since you have Insufficient balance you are charged rs-3500 overdraft"<<endl;
    }
    else
    {
        balance-=amt;
    }
}
int main()
{
    Account *Acc;
    
    int accNo;
    float balnc;
    cout<<"Enter the your account: "<<endl;
    cin>>accNo;
    cout<<"Enter balance: "<<endl;
    cin>>balnc;
    int n;

    cout<<"1.Saving Account: "<<endl;
    cout<<"2.Checking Account: "<<endl;
    cout<<"Enter choice: ";
    cin>>n;
    if(n==1)
    {
        
        SavingAccount s1(accNo,balnc);
        Acc=&s1;
        //Acc=new SavingAccount(accNo,balnc);
    }
    else if(n==2)
    {
        CheckingAccount c1(accNo,balnc);
        Acc=&c1;

        //Acc=new CheckingAccount(accNo,balnc);
    }
    else
    {
        cout<<"Invalid choice"<<endl;
    }
    
            cout<<endl;
            cout<<"1.Deposit"<<endl;
            cout<<"2.withdraw"<<endl;
            int i;
            cout<<"Enter choice: ";
            cin>>i;
            switch(i)
            {
                case 1:
                {
                    double amt;
                    cout<<"Enter amount u want to deposit:"<<endl;
                    cin>>amt;
                    Acc->deposit(amt);
                    Acc->display();
                    break;
                }
                case 2:
                {
                    double amt;
                    cout<<"Enter amount u want to withdram:"<<endl;
                    cin>>amt;
                    Acc->withdraw(amt);
                    Acc->display();
                    break;
                }
                default:
                {
                    cout<<"Invaild input!!"<<endl;
                }
    }

    return 0;
}


