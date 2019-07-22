#include "pch.h"
#include "Account.h"
#include "User.h"
#include <vector>
#include <iostream>
#include <string>



Account::Account()
{

}


Account::Account(std::string name, float balance)
{
	this->accname = name;
	this->accBalance = balance;
}

void Account::AddFunds(float balance, float amount)
{
	this->accBalance = balance;
	balance = balance + amount;
}

void Account::SubtractFunds(float balance, float amount)
{
	this->accBalance = balance;
	balance = balance - amount;
}

void Account::ShowHistory()
{
	for (int i = acchistory.size(); i > 0; i--)
	{
		std::cout << acchistory[i];
	}
}

Account::~Account()
{
	
}