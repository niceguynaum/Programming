// FinalProjectforC.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "SystemCheck.h"
using namespace std;

int coffeeCupsOrdered; // user input for how many coffee cups they would like.
int coffeeCupsMade;  // outputs how many coffee cups that have been made.

void CoffeeLoop(Bean_Holder bh, Water_Reservoir wr, Coffee_Grinder gr, Water_Heater wh) // main loop of the program. This is where all other classes' methods are to be referenced
{
	SystemCheck sys(false, false, false); //initializing initial error check values 
	wr.Fill_Tank(0);
	bh.Grind_Counter();
	wr.Tank_Checker();
	wr.Thermometer();
	sys.Check(wr.waterTemperature, &sys.waterBoiled , &bh.numberOfGrind, &sys.coffeeGround);
	sys.GrindCheck(&bh.numberOfBeans, &sys.beansAvailable);

	//start of run sequence, goes through the process of making the coffee.

	//starts by grinding the coffee beans and heating water
	gr.Grinder(&bh.numberOfGrind, &bh.numberOfBeans);
	wh.Heater(wr.waterTemperature);

	//checks to make sure there is enough to make cofffee
	sys.Check(wr.waterTemperature, &sys.waterBoiled, &bh.numberOfGrind, &sys.coffeeGround);
	sys.GrindCheck(&bh.numberOfBeans, &sys.beansAvailable);

	bh.Add_Beans(20);

	if (sys.waterBoiled == true && sys.coffeeGround == true)
	{
		coffeeCupsMade += 1;
	}
}

int main()
{
	Bean_Holder bh(0, 20); //initializing initial bean holder values 
						   //(int numberOfGrind, int numberOfBeans);
	Water_Reservoir wr(55, 0); //initializing initial water reservoir values 
							   //(int waterTemperature, int waterInTank);
	Coffee_Grinder gr;
	Water_Heater wh;
	cout << "Welcome to the Coffee Maker BIOS." << endl;
	cout << "Please enter the number of coffee cups you would like to make." << endl;
	cin >> coffeeCupsOrdered;
	cout << "Making " << coffeeCupsOrdered << " cups of coffee." << endl;
	for (int i = 0; i < coffeeCupsOrdered; ++i) // coffee loop makes 1 cup of coffee. This rigs 
												// the loop to continue for however many cups are ordered.

	{
		CoffeeLoop(bh, wr, gr, wh);
		cout << "There are now " << coffeeCupsMade << " made." << endl;
	}
}

//bool waterBoiled; // a bool to signal if water needs to be boiled.
//bool coffeeGround; // a bool to signal if coffee needs to be ground.
//bool beansAvailable; // a bool to signal if you have enough beans to grind into one tablespoon.

