// Midterm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "User.h"
#include "Bank.h"

Bank b; //initialized instance of bank (needed to access the variables in the bank class)
int UserSelect;
int AccountSelect;
int AccountSelect2;

void UserCreation()
{
	std::string fullname;
	std::string password;
	std::string password2;
	std::string address;
	std::string history; 
	char input; //inputs for a variety of yes/no questions

	std::cout << "Welcome to the Bank of Midterms!" << std::endl;
	std::cout << "Please create an account to start banking with us." << std::endl;
	std::cout << "Please enter your full name below." << std::endl;

	std::cin >> fullname;
	std::cout << "Is " << fullname << " correct? Y/N" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 'Y': std::cout << "Wonderful, next question." << std::endl;
		break;
	case 'y': std::cout << "Wonderful, next question." << std::endl;
		break;
	default:
		std::cout << "Incorrect input OR incorrect recorded answer. Please re-enter full name below." << std::endl;
		std::cin >> fullname;
		std::cout << "Is " << fullname << " correct? Y/N" << std::endl;
	}


	std::cout << "Please enter your full address below." << std::endl;

	std::cin >> address;
	std::cout << "Is " << address << " correct? Y/N" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 'Y': std::cout << "Wonderful, next question." << std::endl;
		break;
	case 'y': std::cout << "Wonderful, next question." << std::endl;
		break;
	default:
		std::cout << "Incorrect input OR incorrect recorded answer. Please re-enter full address below." << std::endl;
		std::cin >> address;
		std::cout << "Is " << address << " correct? Y/N" << std::endl;
	}


	std::cout << "Please enter your Password two times below.";
	std::cin >> password;
	std::cin >> password2;
	if (password == password2)
	{
		std::cout << "Thank you, your password has been accepted." << std::endl;
	}
	if (password != password2)
	{
		while (password != password2)
		{
			std::cout << "I'm sorry, the passwords didn't match. Please re-enter your password two times below." << std::endl;
			std::cin >> password;
			std::cin >> password2;
		}
	}

	User U(fullname, address, password); //pass in parameters to a new user U
	b.Users.push_back(&U); //new user stored to user vector.
}

//outputs the account select information to determine which user has logged in.
void Login() 
{
	std::cout << "Please select which user account you'd like to access." << std::endl;
	int c = 1; //used for notation for the user to select an account.
	for (int i = 0; i < b.Users.size(); i++)
	{
		std::cout << c << ". " << b.Users[i]->accfullname; //prints the list of full names that the user can select.
		c++;
	}
	std::cout << "Enter the number of which user you'd like to login to." << std::endl;
	std::cin >> UserSelect;
}

//based off of user selection has them enter a password. Where the input is UserSelect.
void Password(int UseSel)
{
	bool CorrectPass = false;
	std::string UserInput;
	while (CorrectPass == false)
	{
		std::cout << "You've selected the account belonging to " << b.Users[UseSel]->accfullname << "." << std::endl;
		std::cout << "Please enter the associated password with the account to continue." << std::endl;
		std::cin >> UserInput;
		if (UserInput == b.Users[UseSel]->accpassword)
		{
			CorrectPass = true;
		}
		else
		{
			std::cout << "Passwords do not match, please enter information again." << std::endl;
		}
	}
}

//creates a new account with the user specifying the name of the account and balance.
void AccountCreation()
{
	char input; //inputs for a variety of yes/no questions
	std::string name; 
	float balance; // used as an user input variable to determine balance.

	std::cout << "Please enter a name for your account as well as a starting balance in dollars." << std::endl;
	std::cin >> name;
	std::cin >> balance;

	std::cout << "Is " << name << " the correct name of the account and is " << balance << "$ the correct amount of money? Y/N" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 'Y': std::cout << "Wonderful! Now taking you to main menu." << std::endl;
		break;
	case 'y': std::cout << "Wonderful! Now taking you to main menu." << std::endl;
		break;
	default:
		std::cout << "Incorrect input OR incorrect recorded answer. Please re-enter account name and balance below." << std::endl;
		std::cin >> name;
		std::cin >> balance;
		std::cout << "Is " << name << " the correct name of the account and is " << balance << "$ the correct amount of money? Y/N" << std::endl;
		std::cin >> input;
	}

	Account A(name, balance);
	int i; //used to find the total size of Users vector in order to correctly order them.
	if (b.Users.size() == 1)
	{
		i = 0;
	}
	else
	{
		i = b.Users.size() - 1;
	}
	b.Users[i]->Accounts.push_back(&A); //used to keep track of instances
}

//checks if a user can create an account based on if a user has at least 1 account with 25 dollars in it.
void AccountCreationCheck() 
{
	bool CanCreateNewAcc = false;
	if (b.Users[UserSelect]->Accounts.size() == 0) //basically says that if a user has no accounts they may create one.
	{
		AccountCreation();
	}
	if (b.Users[UserSelect]->Accounts.size() > 0)
	{
		for (int i = 0; i < b.Users[UserSelect]->Accounts.size(); i++)
		{
			if (b.Users[UserSelect]->Accounts[i]->accBalance > 25) //scrolls through every users account and basically figures out if they have an account with at least 25$ in it.
			{
				CanCreateNewAcc = true;
			}
		}
	}
	if (CanCreateNewAcc == true)
	{
		AccountCreation();
	}
}

void AccountSelector()
{
	int c = 1; //used to notate selections
	std::cout << "Which Account would you like to choose?" << std::endl;
	for (int i = 0; i < b.Users[UserSelect]->Accounts.size(); i++)
	{

		std::cout << c << ". " << b.Users[UserSelect]->Accounts[i]->accname << " with a balance of " << b.Users[UserSelect]->Accounts[i]->accBalance << std::endl;
		c++;
	}
	std::cin >> AccountSelect;
	std::cout << "Account " << b.Users[UserSelect]->Accounts[AccountSelect]->accname << " selected." << std::endl;
}

//used in an instance where a user wants to transfer money.
void MultipleAccountSelector()
{
	int c = 1; //used to notate selections
	std::cout << "Which Accounts would you like to choose? You may choose up to 2." << std::endl;
	std::cout << "If transfering, please select the account you'd like to transfer from and then the account you'd like to transfer to." << std::endl;
	for (int i = 0; i < b.Users[UserSelect]->Accounts.size(); i++)
	{

		std::cout << c << ". " << b.Users[UserSelect]->Accounts[i]->accname << " with a balance of " << b.Users[UserSelect]->Accounts[i]->accBalance << std::endl;
		c++;
	}
	std::cin >> AccountSelect;
	std::cin >> AccountSelect2;
	std::cout << "Account " << b.Users[UserSelect]->Accounts[AccountSelect]->accname << " and " << b.Users[UserSelect]->Accounts[AccountSelect2]->accname << " selected." << std::endl;
}

//used to withdraw from a specified account
void Withdraw(float MoneyAmnt) //withdraw function that also stores the transaction into history.
{
	std::string withdraw;
	std::string moneyamount;
	b.Users[UserSelect]->Accounts[AccountSelect]->AddFunds(b.Users[UserSelect]->Accounts[AccountSelect]->accBalance, MoneyAmnt);
	withdraw = "Withdrew " + std::to_string(MoneyAmnt) + " from account " + b.Users[UserSelect]->Accounts[AccountSelect]->accname;
	b.Users[UserSelect]->Accounts[AccountSelect]->acchistory.push_back(withdraw);
}

//used to deposit from a specified account
void Deposit(float MoneyAmnt)
{
	std::string deposit;
	b.Users[UserSelect]->Accounts[AccountSelect]->SubtractFunds(b.Users[UserSelect]->Accounts[AccountSelect]->accBalance, MoneyAmnt);
	deposit = "Deposit " + std::to_string(MoneyAmnt) + " from account " + b.Users[UserSelect]->Accounts[AccountSelect]->accname;
	b.Users[UserSelect]->Accounts[AccountSelect]->acchistory.push_back(deposit);
}

//used to transfer to specified accounts and the amount
void Transfer(int Selection1, int Selection2, float MoneyAmnt)
{
	std::string transfer;
	b.Users[UserSelect]->Accounts[Selection1]->SubtractFunds(b.Users[UserSelect]->Accounts[Selection1]->accBalance, MoneyAmnt);
	b.Users[UserSelect]->Accounts[Selection2]->AddFunds(b.Users[UserSelect]->Accounts[Selection2]->accBalance, MoneyAmnt);
	transfer = "Transfer " + std::to_string(MoneyAmnt) + " from account " + b.Users[UserSelect]->Accounts[Selection1]->accname + " to " + b.Users[UserSelect]->Accounts[Selection2]->accname;
	b.Users[UserSelect]->Accounts[Selection1]->acchistory.push_back(transfer);
	b.Users[UserSelect]->Accounts[Selection2]->acchistory.push_back(transfer);
}

//Where the user navigates to in order to withdraw/deposit funds
void AccountArith()
{
	int i;
	float UserInputMoney;
	std::cout << "Welcome " << b.Users[UserSelect]->accfullname << ", \nWhat would you like to do?" << std::endl;
	std::cout << "\n1. Withdraw Money " << std::endl;
	std::cout << "\n2. Deposit Money." << std::endl;
	std::cout << "\n3. Return." << std::endl;
	switch (i)
	{
	case 1:
		std::cout << "How much money would you like to withdraw?" << std::endl;
		std::cin >> UserInputMoney;
		if (UserInputMoney <= b.Users[UserSelect]->Accounts[AccountSelect]->accBalance)
		{
			Withdraw(UserInputMoney);
			std::cout << "Withdrawal has been accepted. You have made a withdrawal of " << UserInputMoney << "$." << std::endl;
			std::cout << "This Withdrawal was made to " << b.Users[UserSelect]->Accounts[AccountSelect]->accname << std::endl;
			std::cout << "Returning to User Menu." << std::endl;
		}
		else
		{
			std::cout << "Insufficient Funds, returning to User Menu." << std::endl;
		}
		break;
	case 2:
		std::cout << "How much money would you like to deposit?" << std::endl;
		std::cin >> UserInputMoney;
		Deposit(UserInputMoney);
		std::cout << "Deposit has been accepted. You have made a deposit of " << UserInputMoney << "$." << std::endl;
		std::cout << "This Deposit was made to " << b.Users[UserSelect]->Accounts[AccountSelect]->accname << std::endl;
		std::cout << "Returning to User Menu." << std::endl;
		break;
	case 3:
		UserMenu();
		break;
	default:
		std::cout << "Invalid selection please try again." << std::endl;
		AccountArith();
	}
	UserMenu();
}

//The menu the user navigates to in order to transfer funds
void TransferMenu()
{
	int i;
	float UserInputMoney;
	
	std::cout << "How much money would you like to transfer?" << std::endl;
	std::cin >> UserInputMoney;
	if (UserInputMoney <= b.Users[UserSelect]->Accounts[AccountSelect]->accBalance)
	{
		Transfer(AccountSelect, AccountSelect2, UserInputMoney);
		std::cout << "Transfer has been accepted. You have made a transfer of " << UserInputMoney << "$ from account " << b.Users[UserSelect]->Accounts[AccountSelect]->accname << " to account " << b.Users[UserSelect]->Accounts[AccountSelect2]->accname << std::endl;
		std::cout << "This Withdrawal was made to " << b.Users[UserSelect]->Accounts[AccountSelect]->accname << std::endl;
		std::cout << "Returning to User Menu." << std::endl;
	}
	else
	{
		std::cout << "Insufficient Funds, returning to User Menu." << std::endl;
	}

	UserMenu();
}

//Outputs various balances of the user
void ManageAccounts()
{
	int i;
	int c = 1;
	std::cout << "Welcome " << b.Users[UserSelect]->accfullname << ", \nWhat would you like to do?" << std::endl;
	std::cout << "\n1. View account balances " << std::endl;
	std::cout << "\n2. Add an account " << std::endl;
	switch (i)
	{
	case 1:
		std::cout << "Below are your accounts and account balances: " << std::endl;
		for (int i = 0; i < b.Users[UserSelect]->Accounts.size(); i++)
		{

			std::cout << c << ". " << b.Users[UserSelect]->Accounts[i]->accname << " with a balance of " << b.Users[UserSelect]->Accounts[i]->accBalance << std::endl;
			c++;
		}
		std::cout << "Returning to User Menu." << std::endl;
		break;
	case 2:
		AccountCreationCheck();
		std::cout << "Returning to User Menu." << std::endl;
		break;
	default:
		std::cout << "Invalid selection please try again." << std::endl;
	}
	UserMenu();
}

void UserMenu()
{
	int i;
	std::cout << "Welcome " << b.Users[UserSelect]->accfullname << ", \nWhat would you like to do?" << std::endl;
	std::cout << "\n1. Withdraw/Deposite Money " << std::endl;
	std::cout << "\n2. Transfer Money." << std::endl;
	std::cout << "\n3. Manage Accounts and View Balances." << std::endl;
	std::cin >> i;
	switch (i)
	{
	case 1:
		AccountSelector();
		AccountArith();
		break;
	case 2:
		MultipleAccountSelector();
		TransferMenu();
		break;
	case 3:
		ManageAccounts();
		break;
	default:
		std::cout << "Invalid selection please try again."  << std::endl;
	}
}


//Basic menu interface to select Login or Create an Account.
void MainMenu()
{
	int i;
	std::cout << "Welcome to the Bank of Midterms" << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Create an Account." << std::endl;
	std::cout << "2. Login to an existing account." << std::endl;
	std::cout << "3. Exit program." << std::endl;
	switch (i)
	{
	case 1:
		UserCreation();
		break;
	case 2:
		Login();
		Password(UserSelect);
		UserMenu();
		break;
	}
}

int main()
{
	MainMenu();
	delete &Account();
	delete &User();
	delete &b;
}
