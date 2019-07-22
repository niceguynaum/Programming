#include "stdafx.h"
#include <iostream>
#include "Water_Heater.h"
#include "Coffee_Grinder.h"



class SystemCheck
{
public:
	bool waterBoiled; // a bool to signal if water needs to be boiled.
	bool coffeeGround; // a bool to signal if coffee needs to be ground.
	bool beansAvailable; // a bool to signal if you have enough beans to grind into one tablespoon.

	void Check
	(
		int waterTemperature,
		bool * waterBoiled,
		int * numberOfGrind,
		bool * coffeeGround
	);
	void GrindCheck
	(
		int * numberOfBeans,
		bool * beansAvailable
	);
	SystemCheck
	(
		bool waterBoiled, 
		bool coffeeGround, 
		bool beansAvailable
	);
};
