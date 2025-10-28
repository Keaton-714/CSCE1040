/*
Author: Keaton Morales
Date completed: 15 April 2025
Description: Creating a program to store clients "money" in bank accounts.
*/
#include "Account.h"
#include "Project3.h"
using namespace std;

void displayHeader()
{
        cout << "+-----------------------------------------------------+\n";
        cout << "|         Computer Science and Engineering            |\n";
        cout << "|        CSCE 1040 - Computer Programming II          |\n";
        cout << "| Keaton Morales   ksm0281   keatonmorales@my.unt.edu |\n";
        cout << "+-----------------------------------------------------+\n";
}

void printAccounts(list<Account>& accounts)
{
        cout << "+---------------------------------------------------+\n";
        cout << "|  Acct Number   |      Name       |     Balance    |\n";
        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
           cout << "|  " << left << setw(13) << it->GetAccountNumber() << " | " << setw(16) << it->GetName() << "| $" << right << setw(12) << fixed << setprecision(2) << it->GetBalance() << "  |" << endl;
        }
        cout << "+---------------------------------------------------+\n";
}

void displayMenu()
{
        cout << "+----------------------------+\n";
        cout << "|        Enter selection     |\n";
        cout << "+----------------------------+\n";
        cout << "| 1.) Open new account       |\n";
        cout << "| 2.) Deposit into account   |\n";
        cout << "| 3.) Withdraw from account  |\n";
        cout << "| 4.) Print all accounts     |\n";
        cout << "| 5.) End transaction        |\n";
        cout << "+----------------------------+\n";

}


int main()
{
        displayHeader();
        list<Account> accounts;
        int choice;

do
{
        displayMenu();
        cout << "-->";
        cin >> choice;

        switch (choice)
	{
           case 1:
           {
                string name;
                float deposit;
                //int accountNumber = Account::GetNextAccountNumber();

                //Get info
                cout << "Enter your name: ";
                cin.ignore(); //maybe
                getline(cin, name);
                cout << "Initial deposit: ";
                cin >> deposit;
                Account newAccount(name, deposit);
                accounts.push_back(newAccount); //NEED A CUSTOM COPY CONSTRUCTOR
                cout << "**Account opened successfully**" << endl;
                cout << "Account #: " << accounts.back().GetAccountNumber() << " -- " << accounts.back().GetName() << ": " << fixed << setprecision(2) << "$" << accounts.back().GetBalance() << endl;
                break;
           }
           case 2:
           {
                if(accounts.empty()) // Check if empty before searching
                {
                   cout << "Error: no accounts found" << endl;
                   break;
                }

		string name;
                int num;
                float amount;
                bool found = false;
                cout << "Enter account number: ";
                cin >> num;
		cout << "For security purposes, enter name on account: ";
		cin.ignore(); // TEST
		getline(cin, name);


                for (auto it = accounts.begin(); it != accounts.end(); ++it)
                {
                   if (num == it->GetAccountNumber() && name == it->GetName())
                   {
                        found = true;
                        cout << "Enter deposit amount: $";
                        cin >> amount;
                        if (amount < 0) // Adding a check to see if amount is positive
                        {
                           cout << "Transaction Failed: Enter a positive amount\n";
                           break;
                        }
                        it->Deposit(amount);
                        cout << "Deposit successful -- New balance: $" << fixed << setprecision(2) << it->GetBalance() << endl;
                        break;
                   }
                }
                if (!found)
                {
                        cout << "Transaction failed: Account number or name not found." << endl;
                }
                break;
           }
           case 3:
           {
                if(accounts.empty()) // Check if empty before searching
                {
                   cout << "Error: no accounts found" << endl;
                   break;
                }

		string name;
                int num = 0;
                float amount = 0;
                bool found = false;
                cout << "Enter account number: ";
                cin >> num;
		cout << "For security purposes, enter name on account: ";
		cin.ignore(); // TEST
                getline(cin, name);

                for (auto it = accounts.begin(); it != accounts.end(); ++it)
                {
                   if (num == it->GetAccountNumber() && name == it->GetName())
                   {
                        found = true;
                        cout << "Enter withdrawal amount: ";
                        cin >> amount;
                        bool withdrew = it->Withdraw(amount); // Function returns a bool
                        if(!withdrew)
                        {
                                cout << "Transaction failed: Insufficient funds\n";
                                break;
                        }
                        else
                        {
                                cout << "Withdrawal successful -- New balance: " << it->GetBalance() << endl;
                                break;
                        }
                   }
                }
                if(!found)
                {
                        cout << "Transaction failed: Account number or name not found.\n";
                }
                break;

           }
           case 4:
           {
                if(accounts.empty()) // Check if empty before searching
                {
                   cout << "Error: no accounts found" << endl;
                   break;
                }
                printAccounts(accounts);
                break;
           }
           case 5:
           {
                cout << "Thank you for your business and have a good day!\n";
                return 0;
           }
           default:
           {
                cout << "Transaction failed: Please enter a valid number\n";
                break;
           }
        }

} while(choice != 5);


return 0;
}
