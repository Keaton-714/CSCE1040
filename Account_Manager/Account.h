#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
using namespace std;

class Account
{
   private:
        int* accountNumber; // start with 1000
        string name; // accounts name
        float balance; // account balance
        static int nextAccountNumber;

   public:
        //constructors & destructor
        Account(); // default
        Account(string name, float balance); // overloaded constructor
        Account(const Account& other); // copy constructor
        ~Account(); // destructor

        // static functions for account number
        static int GetNextAccountNumber();

        // setters & getters
        int GetAccountNumber() const;
        void SetName(string name);
        string GetName() const;
        void SetBalance(float amount);
        float GetBalance() const;

        // deposit & withdraw
        void Deposit(float amount);
        bool Withdraw(float amount);
};

#endif
