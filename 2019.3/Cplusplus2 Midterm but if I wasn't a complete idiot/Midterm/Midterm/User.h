#pragma once
class User
{
public:
	std::vector<Account *> Accounts;
	std::string accfullname; //used to store full names corresponding with accounts.
	std::string accpassword; //used to store the password associated with an instance of user.
	std::string accaddresss; //stores address values of a given instance of User.
	User();
	User(std::string fname, std::string fadd, std::string pass);
	~User();
};

