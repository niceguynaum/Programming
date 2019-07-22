#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

//The object of this is to Dedupplicate a vector. If a vector array has a value
//make sure it does not have a value that it already has.

std::vector<int> dedup(std::vector<int>& ints)
{
	std::set<int> deuplicated;
	std::vector<int> ret;
	//space compllexity is o(n^2)
	//time complexity is o(n^2)
	for (auto i : ints)
	{
		deuplicated.insert(i);
	}
	for (auto&i : deuplicated)
	{
		ret.push_back(i);
	}
	return ret;
}


int main()
{
	std::vector<int> myVector{ 1, 2, 3, 4, 5, 5, 5, 6, 7, 9, 9 };
	std::vector<int> result = dedup(myVector);

	for (int i : result)
	{
		std::cout << i << std::endl;
	}

	return 0;
}