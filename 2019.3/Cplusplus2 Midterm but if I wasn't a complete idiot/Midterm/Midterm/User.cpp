#include "pch.h"
#include "User.h"
#include "Account.h"
#include <vector>
#include <iostream>

User::User()
{

}

User::User(std::string fname, std::string fadd, std::string pass) //paramaterized constructor, takes in Full name, address, password.
{
	this->accfullname = fname;
	this->accaddresss = fadd;
	this->accpassword = pass;
}

User::~User()
{

}
