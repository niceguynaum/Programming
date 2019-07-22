// Brain Teaser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>

std::string test_string = "I Think C++ Is A Boring Class";

std::string reverse_words(std::string & s)
{
	int n = s.length();
	n++;
	char** p = new char*[n];
	cstring::strcopy(p, test_string);
	char** l = new char*[n];

	for (int x = 0; x < n; x++)
	{
		for (int y = n; y > n; y--)
		{
			l[x] = p[y];
		}
	}


	for (int x = 0; x < n; x++)
	{
		std::cout << l[x];
	}

	delete l;
	delete p;
}

int main()
{
	reverse_words(test_string);
}




//char(32) = " "

// "I think C++ is a boring Class" Input
// "ssalC gnirob a si ++C kniht I" Output

//my logic: find the space and reverse words based off of strings.