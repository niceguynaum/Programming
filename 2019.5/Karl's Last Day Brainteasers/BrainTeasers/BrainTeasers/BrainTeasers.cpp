// BrainTeasers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int sum;

int Math() {

		for (int i = 0; i < 1000; i++)
		{
			if (i % 3 == 0) {
				sum += i;
				std::cout << sum << std::endl;
			}
			else if (i % 5 == 0) {
				sum += i;
				std::cout << sum << std::endl;
			}
		}
		return 0;
}

int main()
{
	Math();
}

//if we list all the natural numbers below 10 that are multiples of 3 or 5 we get 3,5,6, and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
//233168