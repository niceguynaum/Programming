// BitShifting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	/*
	& bitwise AND (0 & 0 = 0) (0 & 1 = 0) (1 & 0 = 0) (1 & 1 = 1)
	| bitwise OR (inclusive)
	^ bitwise XOR (exclusive OR)
	<< left shift
	>> right shift
	~ bitwise NOT (unary) //unary takes in one argument
	
	*/

	//11001000 ^ 01110000 = 01110000

	//~1

	//00001110 >> 1 = 00000111 (7)

	int z = 7 >> 1;
	std::cout << z << std::endl;
	return 0;
}