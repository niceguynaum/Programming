#include "stdafx.h"
#include <iostream>
#include "SystemCheck.h"
#include "Water_Heater.h"
#include "Coffee_Grinder.h"

using namespace std;

void SystemCheck::Check
(
	int waterTemperature,
	bool * waterBoiled,
	int * numberOfGrind,
	bool * coffeeGround
)
{
	if (waterTemperature == 205)
	{
		cout << "The water is boiled to 205 Degrees." << endl;
		*waterBoiled = true;
	}
	if (*numberOfGrind == 2)
	{
		cout << "There are 2 tablespoons of coffee grinds." << endl;
		*coffeeGround = true;
	}
	else if (waterTemperature /= 205)
	{
		cout << "ERROR: The water is not boiled yet." << endl;
		*waterBoiled = false;
	}
	else if (*numberOfGrind /= 2)
	{
		cout << "ERROR: There is not enough coffee ground." << endl;
		*coffeeGround = false;
	}
}
void SystemCheck::GrindCheck
(
	int * numberOfBeans,
	bool * beansAvailable
)
{
	if (*numberOfBeans == 20)
	{
		cout << "There is enough beans to grind 1 tablespoon" << endl;
		*beansAvailable = true;
	}
	else
	{
		cout << "ERROR: More coffee beans needed to grind 1 tablespoon." << endl;
		*beansAvailable = false;
	}
}
SystemCheck::SystemCheck(bool waterBoiled, bool coffeeGround, bool beansAvailable)
{
	this->waterBoiled = waterBoiled;
	this->coffeeGround = coffeeGround;
	this->beansAvailable = beansAvailable;
}