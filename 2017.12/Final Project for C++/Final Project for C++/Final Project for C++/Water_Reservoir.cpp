#include "stdafx.h"
#include <iostream>
#include "Water_Reservoir.h"

using namespace std;

void Water_Reservoir::Tank_Checker() // checks the amount of water currently in the tank
{
	cout << "There is currently " << this->waterInTank << " ounces of water in the tank." << endl;
}
void Water_Reservoir::Fill_Tank(int waterInTank) // fills the tank with water.
{
	cout << "Filling water tank now." << endl;
	waterInTank= waterInTank + 6; // fills the tank with enough water to make one cup of coffee.
}
void Water_Reservoir::Thermometer() // checks the current temperature of the water and reads it out.
{
	cout << "The temperature is currently " << this->waterTemperature << " degrees Fahrenheit." << endl;
}
Water_Reservoir::Water_Reservoir(int waterTemperature, int waterInTank) //constructor needed to initialize the start state of the int. "if it exsists in your class, probably pass it through a constructor." Should always leave your class in a valid state.
{
	this->waterTemperature = waterTemperature;
	this->waterInTank = waterInTank;
}