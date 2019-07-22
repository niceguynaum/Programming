#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;



class Water_Reservoir
{
public:

	int waterInTank; // amount of water (in ounces) in the tank
	int waterTemperature; // the current temperature of the water ( defaults to 55 degrees when filled )

	Water_Reservoir(int waterTemperature, int waterInTank); //constructor does not need to have a referenced passed due to being the original value to be referenced.

	void Tank_Checker();
	void Fill_Tank(int waterInTank);
	void Thermometer();
};

