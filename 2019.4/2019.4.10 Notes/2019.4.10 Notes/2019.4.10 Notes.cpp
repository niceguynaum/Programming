#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

/*
void foo(int a) {
	std::cout << a << std::endl; // why you don't wanna use std::endl in preformance critical software because it calls in a whole stream of shit. Instead use "\n" instead. :D
}

*/

 //all about lambda functions babeeeeee

bool is_greater(int lhs, int rhs) {
	return lhs > rhs;
}

struct myClass {
	bool operator()(int lhs, int rhs) { return lhs > rhs; }
} myObj;

void f(int i) {
	auto fn = [&, i](int a) -> int {return a + i; }; //auto for the lambda type ... to capture by value, you need to [=, *i] or [i]. You can only mention a capture once for a lambda capture
	int r = fn(10);
	std::cout << r << std::endl;
}


int main()
{
	myObj(10, 10);

	std::vector<int> myInts{ 1, 2,3,5,4,6,5,8 };

	bool(*fun_ptr)(int, int) = &is_greater;

	std::sort(myInts.begin(), myInts.end(), [](int a, int b) -> bool {return a > b; });

	

    std::cout << "Hello World!\n";
	return 0;
}