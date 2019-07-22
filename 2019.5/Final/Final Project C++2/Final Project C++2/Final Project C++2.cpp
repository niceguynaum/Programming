#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

char InputCharArray[140];
std::string CoinType[4] = { "Pennies","Nickles","Dimes","Quarters"};
int CoinValue[4] = { 1, 5, 10, 25};
int NumberOfCoins[4] = { 0, 0, 0, 0 }; //default coin number generation
int DollarChange = 0;
std::string OrderInput;

double ItemPricing[4] = {1.00, 2.55, 3.75, 3.22};

double NumItemSelect[4] = {0.0,0.0,0.0,0.0}; // values for number of items ordered on the menu, where 0 = coffee, 1 = latte, ect.

int ItemSelectNum;
int UserPayment;
double TotalPrice;
std::string Menu[4] = { "Coffee | $1.00","Latte | $2.55","Egg Sandwhich | 3.75","Doughnut | $3.22" };

std::string Array[4] = { "!","!" ,"!" ,"!" }; //setting up a default value for each array to tell whether an array is used or not
char delimiter = ',';
int delimCount = 0;


int ChangeDispense(int WholeDollarInput, double TotalPrice) {
	int ChangeAmount;
	int CoinCalc;

	if ((WholeDollarInput - TotalPrice) > 1)
	{
		DollarChange = (int)(WholeDollarInput - TotalPrice);
		ChangeAmount = 100 *((WholeDollarInput - TotalPrice) - DollarChange);
	}
	else ChangeAmount = 100 * (WholeDollarInput - TotalPrice);

	for (int x = 3; x >= 0; x--)
	{
		if (ChangeAmount % CoinValue[x] != 0) //With x = 3 it's quarters, x = 2 dimes, ect.
		{
			CoinCalc = ChangeAmount;
			ChangeAmount = ChangeAmount % CoinValue[x];
			NumberOfCoins[x] = CoinCalc / CoinValue[x];
		}
		if (ChangeAmount % CoinValue[x] == 0)
		{
			NumberOfCoins[x] = ChangeAmount;
		}
	}
	return 0;
}

int OrderParse(std::string input) {
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == delimiter) delimCount++;
	}
	if (delimCount == 0)
	{
		Array[0] = input;
	}
	else
	{
		for (int x = 0; x <= delimCount; x++)
		{
			Array[x] = input.substr(0, input.find(delimiter));
			input.erase(0, input.find(delimiter) + 2); //the 2 is for both the delimiter and the space afterwards.
		}
	}
	std::string TempString;
	for (int i = 0; i <= delimCount; i++)
	{
		TempString = Array[i];
			switch (TempString.at(2))
			{
			case 'c': case 'C':
				NumItemSelect[0] = TempString.at(0) - '0';
				break;
			case 'l': case 'L':
				NumItemSelect[1] = TempString.at(0) - '0';
				break;
			case 'e': case 'E':
				NumItemSelect[2] = TempString.at(0) - '0';
				break;
			case 'd': case 'D':
				NumItemSelect[3] = TempString.at(0) - '0';
			default :
				break;
		}
	}
	return 0;
}

int OrderInterFace() {
	std::cout << "Welcome to the Coffee Shop!" << std::endl;
	std::cout << "Out Menu is as follows: " << std::endl;
	for (int x = 0; x <= 3; x++)
	{
		std::cout << Menu[x] << std::endl;
	}
	std::cout << "\nPlease make your selection in the following format: 'Quantity Item_Disired'" << std::endl;
	std::cout << "If multiple items are requested, please format your requast as: 'Quantity Item_Disired, Quantity Second_Item, ect." << std::endl;
	std::cin.getline(InputCharArray, sizeof(InputCharArray));
	OrderInput = InputCharArray;
	return 0;
}

double TransactionArith() {
	double Total = 0;
	for (int x = 0; x <= 3; x++)
	{
		Total = Total + (NumItemSelect[x] * ItemPricing[x]);
	}
	return Total;
}

int UserInputPayment() {
	std::cout << "Your total is ";
	std::cout << std::setprecision(4) << TransactionArith() << std::endl;
	std::cout << "\nPlease enter your payment in whole dollars: " << std::endl;
	std::cin >> UserPayment;
	return 0;
}

int TransactionInterFace(int WholeDollarInput, double TransactionTotal) {

	ChangeDispense(WholeDollarInput, TransactionTotal);
	for (int x = 3; x >= 0; x--)
	{
		std::cout << CoinType[x] << +" ";
		std::cout << NumberOfCoins[x] << std::endl;
	}
	if (DollarChange != 0)
	{
		std::cout << "\nand " << DollarChange << " dollars." << std::endl;
	}
	return 0;
}



int main()
{
	OrderInterFace();
	OrderParse(OrderInput);
	UserInputPayment();
	TransactionInterFace(UserPayment, TransactionArith());
}

/*
Your job is to create a cash register at a coffee shop

The inventory of the coffee shop is

Coffee | $1.00

Latte | $2.55

Egg Sandwich | $3.75

Doughnut | 3.22

Your program must take in their order in the following formats

1 Coffee, 1 Egg Sandwhich

2 Coffees, 3 Egg Sandwhiches. etc

You must return a total, and the user must be able to pay in whole dollar amounts

Once you receive payment you must return the correct change in as few coins as possible
*/