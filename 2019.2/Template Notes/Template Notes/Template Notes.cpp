// Template Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//really only use these if you need a generic. Main example for this is something like vector.



template <class T> //takes in anything as long as it can be std::cout'd it'll work.
//Q: How does it work?
//A: At compile time it looks at every usage of this function and creates the functions for you with correct typing.

void generic_print(T item)
{
	std::cout << item << std:endl;
}

template <class T>
T get_greater(T lhs, T rhs) //
{
	return lhs > rhs ? rhs : lhs;
}

template <class T>
void print_length(T *thing) {
	int length = thing->length();
	std::cout << length << std::endl;
}

void print(int i)
{
	//prints int
}

void print(std::string str)
{
	//prints string
}

void print(bool b)
{
	//prints bool.
}

struct Point {
	int x;
	int y;

	Point operator>(const Point& p)
	{
		return x > p.x && y > p.y ? p : *this;
	}
};

int main()
{
	Point p1{10, 11};
	Point p2{12, 13};
	Point g = get_greater(p1, p2);


	std::string hello = "Hello";
	print_length(&hello);
//	print_length(&i); //will not compile because it has no implementation of length and no way to give it length. "Bad shit will happen" - Karl

}

//int main()
//{
//	int i = 10;
//	std::string s = "Hello";
//	bool b = true;
//
//	print(i);
//	print(s);
//	print(b);
//
//	generic_print(i);
//	generic_print(s);
//	generic_print(b);
//    std::cout << "Hello World!\n"; 
//
//
//
//	return 0;
//}


