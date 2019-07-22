// Notes for Today.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

//template<class T>
//void foo(T entity)
//{
//	std::cout << entity << std::endl;
//}
//
//template<typename T> //you should use class for any user defined users/types. Template for any standardized types/users.
//void bar(T bar) {
//
//}
//
//template<> // specialized template
//void foo(int entity)
//{
//	std::cout << entity << std::endl;
//}

//struct Vehicle {};
//struct Car : public Vehicle {};


//dependancy inversion!

class SomeDependancy {
	virtual void foo() = 0;
};

class ConcreteDependancy : SomeDependancy {
	virtual void foo() {
		std::cout << "Hello" << std::endl;
	}
};

class OtherConcreteDependency : ConcreteDependancy {
	virtual void foo() {
		std::cout << "World" << std::endl;
	}
};

class HelloRunner {
private:
	ConcreteDependency *cd;
public:
	HelloRunner() {
		cd = new ConcreteDependancy();
	}
	void Run() {
		cd->foo();
	}
};

class Runner {
private:
	SomeDependancy * m_dependency;
public:
	Runner(SomeDependancy * Dependancy) {
		m_dependency = dependency;
	}

	void Run() {
		m_dependency->foo();
	}
};

int main()
{
	ConcreteDependancy * cd = new ConcreteDependancy();
	OtherConcreteDependency * ocd = new OtherConcreteDependency();
	Runner(a);
	Runner(b);
	return 0;

	a.Run();
	b.Run();
}

//int main()
//{
////	Vehicle * v{};
////	Car * c{}; //through liskovs substitution principle this is allowed.
//
//	v = c;
//
//	std::vector<Vehicle *> vehicles;
//	std::vector<Car *> cars;
//
//	std::cout << "ayy lmao" << std::endl;
//	return 0;
//}

//The proper ettiquette of templates. 

/*
Invariance
You may not substitute one class for another.

Examples:

Templates

Covariance
Is essentially contravariance backwards.
examples:

- pointers 



Contravariance
Essentially is specific -> generic classes.

*/