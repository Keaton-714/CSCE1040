[READ_ME.md](https://github.com/user-attachments/files/23194870/READ_ME.md)
Author: Keaton Morales Date: 08JUL25 Class: CSCE 1040 Computer Programming II

This program implements an interactive bank account management system using a list of Account objects.

Each Account stores:
	* A unique account number (starting at 1000 and auto-incrementing) 
	* The owner’s name 
	* The accounts balance

The user can:

	1.) Open a new account (with an initial deposit)
	2.) Deposit money into an existing account
	3.) Withdraw money from an existing account
	4.) Print a table of all accounts
	5.) Exit the program

Files:
	* Project3.h
	* Project3.cpp
	* Account.h
	* Account.cpp

Compilation:

	* g++ Project3.h Project3.cpp Account.h Account.cpp
	* ./a.out

	* g++ Project3.h Project3.cpp Account.h Account.cpp -o bank
	* ./bank.exe

