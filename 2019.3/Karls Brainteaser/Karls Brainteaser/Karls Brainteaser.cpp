#include "pch.h"
#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[1] == target)
		{
			return i;
		}
	}

	//here be trouble yarrr

	if (nums[0] > target)
	{
		return 0;
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (i < nums.size() - 1)
		{
			if (target <= nums[i + 1] && target >= nums[i])
			{
				return i + 1;
			}
		}
	}
	return nums.size();
}

int main()
{
	std::vector<int> sortedInts{ 1,3,4,5,7,9,12 };
	const int n = 2;
	int result = searchInsert(sortedInts, n);
	std::cout << "The result is: " << result << "." << std::endl;
}