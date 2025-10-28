#include "Account.h"

//static member variable initialization
int Account::nextAccountNumber = 1000;

//constructors & destructor
Account::Account()
{
        accountNumber = new int(nextAccountNumber);
        nextAccountNumber++; // increment for next account
        name = "Unknown";
        balance = 0.00;
}
Account::Account(string name, float balance)
{
        accountNumber = new int(nextAccountNumber);
        nextAccountNumber++; //increment
        this-> name = name;
        this-> balance = balance;
}
Account::Account(const Account& other) //copy constructor
{
        //cout << "Copy Constructor Called" << endl; // for testing
        accountNumber = new int(*other.accountNumber); // deep copy
        name = other.name;
        balance = other.balance;
}
Account::~Account()
{
        //cout << "Destructor Called" << endl; //for testing
        delete accountNumber;
}

//static function
int Account::GetNextAccountNumber()
{
        return nextAccountNumber;
}

//setters & getters
int Account::GetAccountNumber() const
{
        return *accountNumber;
}
void Account::SetName(string name)
{
        this-> name = name;
}
string Account::GetName() const
{
        return name;
}
void Account::SetBalance(float amount)
{
        balance = amount;
}
float Account::GetBalance() const
{
        return balance;
}
void Account::Deposit(float amount)
{
        balance += amount;
}
bool Account::Withdraw(float amount)
{
        if (amount > balance)
        {
           return false;
        }
        else
        {
           balance -= amount;
           return true;
        }
}
