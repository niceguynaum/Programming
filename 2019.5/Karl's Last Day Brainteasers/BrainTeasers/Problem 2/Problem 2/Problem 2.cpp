// Problem 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int fibsum = 0;
int fibsum2 = 0;
int Asum = 0;


int FibbySeq() {
	for (int i = 1; fibsum < 10; i = (fibsum + i)) {
		fibsum2 = fibsum + i;
		if (fibsum % 2 == 0)
		{
			Asum += fibsum;
		}
	}
	return 0;
}

int main()
{
	FibbySeq();
    std::cout << Asum; 
}

// Find the sum of the even valued terms of the fibonacci sequence.