#include "stdafx.h"
#include <iostream>
#include "Coffee_Grinder.h"

using namespace std;

void Coffee_Grinder::Grinder
(
	int * numberOfGrind,
	int * numberOfBeans
) // Inputs 20 coffee beans and outputs 1 tbsp of grounds.
{
		if (*numberOfGrind < 2) // quick check to make sure that you don't have enough grinds
		{
			for (int i = 0; i < 20; i++) // loop that counts to 20 and outputs every bean being ground
			{
				cout << "The grinder grinds a coffee bean" << endl;
				--*numberOfBeans;
			}
		}
		else
		{
			cout << "You have enough grinds to make a cup of coffee." << endl;
		}
};