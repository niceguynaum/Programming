#include "pch.h"
#include <iostream>
#include <string>
#include <memory>

template<typename T>
class Printer {
public:
	virtual void print(T& data);
};

template<typename T>
class ConsolePrinter : public Printer<T> {
public:
	void print(T& data) {
		std::cout << data << std::endl;
	}
};

template<typename T>
class PrintInvoker {
private:
	Printer<T> * m_printer;
public:
	explicit PrintInvoker(Printer<T> * printer) {
		this->m_printer = printer;
	}

	~PrintInvoker() {
		delete this->m_printer;
	}

	void invoke(T& data) {
		this->m_printer->print(data);
	}
};

class Fibbonacci {
private:
	PrintInvoker<int> * m_invoker;
public:
	explicit Fibbonacci(PrintInvoker<int> * invoker) {
		this->m_invoker = invoker;
	}

	~Fibbonacci() { //needs to specify the pointer invoker. (ie, this-> m_invoker)
		delete m_invoker;
	}

	int fib(int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		return fib(n - 1) + fib(n - 2);
	}
};


//For the first 3 templates there is WAY TOO MUCH FUCKING ABSTRACTION KARL.
//To make this as simple as possible, you could just have a fibinacci function that runs
//the algorithm. This whole mess could be rewritten in 3 lines of code.

void fib(int n, PrintInvoker<int> * invoker); //creating a new instance of fib, 
											  //and when it exits it unwinds the stack 
											  //which destructs invoker, that cascadingly 
											  //desctructs printer and then it is 
											  //used again. So it had already been 
											  //deallocated.

int main() {

	ConsolePrinter<int> * intPrinter = new ConsolePrinter<int>();
	PrintInvoker<int> * invoker = new PrintInvoker<int>(intPrinter);


	fib(10, invoker);

	fib(20, invoker);


	return 0;
}

void fib(int n, PrintInvoker<int> * invoker) {
	Fibbonacci fib(invoker);
	fib.fib(10);
}

//This is an example of a good premise gone horribly wrong.
//Level of abstraction are good, LEVELS are better! General oop princicple
//Evil memory managment and bad code design makes for a hard project to design.