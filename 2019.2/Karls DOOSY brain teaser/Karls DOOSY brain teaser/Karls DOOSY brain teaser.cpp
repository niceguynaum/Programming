#include "pch.h"
#include <iostream>
#include <vector>



//Binary tree traversal (depth first tree traversal)

void gen(char curr[], int index, int l, int r, std::vector<std::string> * result)
{
	if (r == 0)
	{
		std::string str(curr);
		result->emplace_back(str);
	}
	if (l > 0)
	{
		curr[index] = '(';
		gen(curr, index + 1, l - 1, r, result);
	}
	if (r > 0)
	{
		curr[index] = ')';
		gen(curr, index + 1, l, r - 1, result);
	}
}

int main()
{
	const int n = 3;

	char input[n * 2]{};

	std::vector<std::string> result;
	gen(input, 0, n, n, &result);
	for (const std::string &r : result)
	{
		std::cout << r << std::endl;
	}
	return 0;
}


/*
Generate all possible perenthesis pairs
ex n = 3
((()))
()()()
(())()
()(())
)()()(
*/