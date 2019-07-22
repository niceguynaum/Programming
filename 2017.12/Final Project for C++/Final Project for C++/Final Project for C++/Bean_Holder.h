#pragma once

#include "stdafx.h"
#include <iostream>


using namespace std;



class Bean_Holder
{
public:
	int numberOfBeans; //number of coffee beans on hand
	int numberOfGrind; //number of tablespoons of coffee grind on hand

	void Bean_Counter();
	void Add_Beans(int numberOfBeans);
	void Grind_Counter();
	Bean_Holder(int numberOfGrind, int numberOfBeans);
};


