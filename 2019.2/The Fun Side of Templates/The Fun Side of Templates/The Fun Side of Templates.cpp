#include "pch.h"
#include <vector>
#include <iostream>

//template<class T> //when passing in something use class
//void foo(T in)
//{
 
//}

template<typename T> //use when it's a build in c++ type
void foo(T in)
{
	std::cout << in << std::endl;
}

template<>
void foo(std::vector<int>& ints)
{
	for (auto i : ints)
	{
		std::cout << i << std::endl;
	}
}

int main()
{
	foo(10);
	foo("hello boyo.");
	foo(false);
	std::vector<int> myints{ 1, 2, 3, 4, 5, 6 };
	return 0;
}