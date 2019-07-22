#include "stdafx.h"
#include <iostream>
#include "Bean_Holder.h"

void Bean_Holder::Bean_Counter()
{
	cout << "There are " << this->numberOfBeans << " coffee beans." << endl;
}
void Bean_Holder::Grind_Counter()
{
	cout << "There are " << this->numberOfGrind << " ounces of coffee ground." << endl;
}
void Bean_Holder::Add_Beans(int numberOfBeans)
{
	cout << "Adding more beans." << endl;
}
Bean_Holder::Bean_Holder(int numberOfGrind, int numberOfBeans)
{
	this->numberOfGrind = numberOfGrind;
	this->numberOfBeans = numberOfBeans;
}