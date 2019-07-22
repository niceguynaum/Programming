#include "stdafx.h"
#include <iostream>
#include "Water_Heater.h"

using namespace std;


void Water_Heater::Heater(int waterTemperature) // you need to pass your references to modify them.
{
	for (int i = 0; i < 10; ++i) // for loop that shows the water heating up
	{
		waterTemperature += 15;
		cout << "The water heats up." << endl;
		cout << "The temperature of the water is currently " << waterTemperature << " degrees Fahrenheit." << endl;
	}
}