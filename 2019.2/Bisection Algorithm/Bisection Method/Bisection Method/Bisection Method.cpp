#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


const double EulerConstant = std::exp(1.0);

double long a; //variable a
double long b; //variable b
double long c; //variable c

double long startInta;
double long startIntb;
double long INTOL;
double long TOL;
int NMAX;
int n;


double long fa; //function a
double long fc; //function c
char ProblemSelect;

bool Solution = false;
bool StartMath = false;
char ConfirmCheck;

float update() //based off of user selction determines which equation will run
{
	switch (ProblemSelect)
	{
	case 'a':
		fc = ((cos(c))*(cos(c)) - c + 6.0);
		fa = ((cos(a))*(cos(a)) - a + 6.0);
		break;
	case 'b':
		fc = (1.0 + 5.0 * c - 6.0 * (pow(c, 3.0)) - pow((EulerConstant), (2.0 * c)));
		fa = (1.0 + 5.0 * a - 6.0 * (pow(a, 3.0)) - pow((EulerConstant), (2.0 * a)));
		break;
	case 'c':
		fc = (pow(c, 3.0)) - 5.0;
		fa = (pow(a, 3.0)) - 5.0;
		break;
	default:
		fc = 5.0 - 6.0 * c - (sin(c));
		fa = 5.0 - 6.0 * a - (sin(a));
		break;
	}
	return 0;
}

float EquationFunction()
{
	n = 1;
	TOL = 0.5 * (pow(10.0, (INTOL * -1)));
	while (n <= NMAX)
	{
		c = (a + b) / 2.0; //finds the new midpoint
//		update fc and fa
		update();
		if ((fc == 0.0) || (((b - a) / 2.0) < TOL))
		{
			Solution = true;
			break;
		}
		n++; //increments counter
		if (((fc < 0.0) && (fa < 0.0)) || (((fc > 0.0)) && (fa > 0.0)))
		{
			a = c;
			std::cout << n << std::endl;
			std::cout << "a = c" << std::endl;
			std::cout << std::setprecision(INTOL + 2) << a << std::endl;
			std::cout << std::setprecision(INTOL + 2) << b << std::endl;
			std::cout << std::setprecision(INTOL + 2) << c << std::endl;
		}
		else
		{
			b = c;
			std::cout << n << std::endl;
			std::cout << "b = c" << std::endl;
			std::cout << std::setprecision(INTOL + 2) << a << std::endl;
			std::cout << std::setprecision(INTOL + 2) << b << std::endl;
			std::cout << std::setprecision(INTOL + 2) << c << std::endl;
		}
	}
	if (n >= NMAX)
	{
		std::cout << "Solution Failed. Max numbner of steps exceeded to find solution within given parameters." << std::endl;
		std::cout << std::setprecision(INTOL + 2) << a << std::endl;
		std::cout << std::setprecision(INTOL + 2) << b << std::endl;
		std::cout << std::setprecision(INTOL + 2) << c << std::endl;
		Solution = false;
	}
	return 0.0;
}

int main()
{

ProgramStart:

	std::cout << "Please enter endpoint a\n" << std::endl;
	std::cin >> a;
	startInta = a;
	std::cout << "Please enter endpoint b\n" << std::endl;
	std::cin >> b;
	startIntb = b;
	std::cout << "Please enter number of decimal places needed for tolerance. \n" << std::endl;
	std::cin >> INTOL;
	std::cout << "Please enter number of iterations required." << std::endl;
	std::cin >> NMAX;

Confirm:

	std::cout << "Are these values correct? Please enter 'y' or 'n' for yes or no correspondingly.\n" << std::endl;
	std::cout << "Endpoint a: " << a << std::endl;
	std::cout << "Endpoint b: " << b << std::endl;
	std::cout << "Tolerance level is to the " << INTOL << " decimal place." << std::endl;
	std::cout << "Number of iterations required is " << NMAX << std::endl;
	std::cin >> ConfirmCheck;
	switch (ConfirmCheck)
	{
	case 'y':
		StartMath = true;
		break;
	case 'n':
		goto ProgramStart;
	default:
		std::cout << "Input not recognized, please try again." << std::endl;
		goto Confirm;
	}

	if (StartMath == true)
	{
		MathChoice:
		std::cout << "Which problem would you like to solve, 'a', 'b', 'c', or 'd'?\n" << std::endl;
		std::cin >> ProblemSelect;
		EquationFunction();
	}
	if (Solution == true)
	{
		std::cout << "Solution Found!" << std::endl;
		std::cout << "The starting Intervals were [ " << startInta << ", " << startIntb << "]." << std::endl;
		std::cout << "The Final Intervals were [ "; 
		std::cout << std::setprecision(INTOL + 2) << a;
		std::cout << ", "; 
		std::cout << std::setprecision(INTOL + 2) << b;
		std::cout << "]." << std::endl;

		std::cout << "The approximate solution is ";
		std::cout << std::setprecision(INTOL + 2) << c;
		std::cout << "; It took " << n << " iterations to get the answer." << std::endl;
		std::cout << std::endl;
		goto ProgramStart;
	}
	if (Solution == false)
	{
		std::cout << std::endl;
		goto ProgramStart;
	}
	return 0;
}
