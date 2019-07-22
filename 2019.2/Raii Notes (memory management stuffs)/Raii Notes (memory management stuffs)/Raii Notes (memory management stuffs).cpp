// Raii Notes (memory management stuffs).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Disposable 
{
	int * myInt;
public:
	Disposable(const int input) 
	{
		myInt = new int(input);
	}

	~Disposable() 
	{
		delete(myInt);
	}
};

int main() //best way to handle memory allocation, basically kills the memory after the constructor has been constructed.
{
	Disposable * t = new Disposable(10);

	delete(t);
	return 0;
}


//int main() //bad way that leads to memory leaks
//{
//	int * myInt = new int(10);
//
//	delete(myInt);
//	return 0;
//}



//YOU should always code like your os will kill your code at any time.