#pragma once
class Account
{
public:

	std::vector<std::string> acchistory; // Used to save transaction/account history acctions
	std::string accname; // Used to create new account names/reference different accounts
	float accBalance; //stores the account balance for an instance of account.

	Account();
	Account(std::string name, float balance);
	void AddFunds(float balance, float amount);
	void SubtractFunds(float balance, float amount);
	void ShowHistory();
	~Account();
};

