#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
private:
string owner;
int balance;  
public:
BankAccount(string owner)
{
    this->owner=owner;
    this->balance=0;
}

BankAccount(string owner, int balance)
{
    this->owner=owner;
    if(balance>0)
    {
        this->balance=balance;
    }
    else
    {
        cout<<"Balance must be greater than 0"<<endl;
    }

}

void deposit(int amount)
{
if(amount>=0)
{
    balance+=amount;
}
else
{
    cout<<"Amount must be greater than 0"<<endl;
}
}

void withdraw(int amount)
{
if(amount>=0)
{
    balance=balance-amount;
}
else
{
    cout<<"Amount must be greater than 0"<<endl;
}
}

string getOwner() const
{
return owner;
}

int getBalance() const
{
return balance;
}    
};


int main()
{ 
    BankAccount name("Amy Santiago");
    cout<<"Name of Account Holder: "<<name.getOwner()<<endl;
    cout<<"---------------------------------------"<<endl;
    BankAccount bank("Jake Peralta",100000);
    cout<<"Name of the Account Holder: "<<bank.getOwner()<<endl;
    cout<<"Balance: "<<bank.getBalance()<<endl;
    bank.deposit(50000);
    cout<<"Amount Deposited: 50000"<<endl;
    cout<<"Balance: "<<bank.getBalance()<<endl;
    bank.withdraw(20000);
    cout<<"Amount Withdrawn: 20000"<<endl;
    cout<<"Balance: "<<bank.getBalance()<<endl;
    cout<<"---------------------------------------"<<endl;
    return 0;
}
