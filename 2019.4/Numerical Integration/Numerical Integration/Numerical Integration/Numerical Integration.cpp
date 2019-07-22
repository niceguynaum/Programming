#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

# define M_PI           3.14159265358979323846  /* pi */

const double EulerConstant = std::exp(1.0);

int EquationSelect; //used to select the equation for the equation string
std::string EquationUsed[2] = { "Composite Trapazoid Rule", "Composite Simpson's Rule" };


int ProblemSelectChoice;



double a; // user input values that will be assigned to equation variables.
double b; // ^

double h; //variable in the equation

int subIntCount; //number of subintervals, otherwise utilized as n

double FinalOutput;

char ConfirmCheck;
char end;

int ClearVar()
{
	a = 0.0;
	b = 0.0;
	h = 0.0;
	subIntCount = 0.0;
	FinalOutput = 0.0;
	return 0;
}

double Equation1(double x) //function for the equation x^2 times natural log of x
{
	return (pow(x, 2.0) * log(x));
}

double Equation2(double x) //function for the equation x/(x^2 + 9)^1/2
{
	return x / pow((pow(x, 2.0) + 9.0), 0.5);
}


double CompTrapRule()
{
	if (ProblemSelectChoice == 1)
	{
		h = (b - a) / subIntCount;s
		FinalOutput = 0.5 * (Equation1(a) + Equation1(b)); //Outer bounds of the integral calculated first then the FinalOutput will take into account the middle values
		for (int i = 0.0; i < subIntCount; i++)
		{	
			FinalOutput = FinalOutput + Equation1(a + h * i);
		}
		FinalOutput = FinalOutput * h;
	}
	if (ProblemSelectChoice == 2)
	{
		h = (b - a) / subIntCount;
		FinalOutput = 0.5 * (Equation2(a) + Equation2(b));
		for (int i = 0; i < subIntCount; i++)
		{
			FinalOutput = FinalOutput + Equation2(a + h * i);
		}
		FinalOutput = FinalOutput * h;
	}
	return 0;
}

double CompSimpRule()
{
	if (ProblemSelectChoice == 1)
	{
		h = (b - a) / (2 * subIntCount);
		FinalOutput = (Equation1(a) + Equation1(b)); //Outer bounds of the integral calculated first then the FinalOutput will take into account the middle values
		//the following is for the odd portions of the simpsons formula
		for (int i = 1; i <= (2 * (subIntCount))-1; i++)
		{
			FinalOutput = FinalOutput + (2 * Equation1(a + h * i));
			if (i % 2 != 0)
			{
				FinalOutput = FinalOutput + (2 * Equation1(a + h * i));
			}
		}
		FinalOutput = FinalOutput * (h/3); //satisfies the h/3 constant of the equation
	}
	if (ProblemSelectChoice == 2)
	{
		h = (b - a) / (2 * subIntCount);
		FinalOutput = (Equation2(a) + Equation2(b)); //Outer bounds of the integral calculated first then the FinalOutput will take into account the middle values
		//the following is for the odd portions of the simpsons formula
		for (int i = 1; i <= (2 * (subIntCount)) - 1; i++)
		{
			FinalOutput = FinalOutput + (2 * Equation2(a + h * i));

			if (i % 2 != 0)
			{
				FinalOutput = FinalOutput + (2 * Equation2(a + h * i));
			}
		}
		FinalOutput = FinalOutput * (h / 3); //satisfies the h/3 constant of the equation
	}
	return 0;
}



double ProblemSelect()
{
	std::cout << "Which problem would you like to solve, '1' or '2'?" << std::endl;
	std::cin >> ProblemSelectChoice;
	std::cout << "Which equation would you like to use?\n1. Composite Trapazoid Rule \n2. Composite Simpsons Rule" << std::endl;
	std::cin >> EquationSelect;
	if (EquationSelect == 1)
	{
		switch (ProblemSelectChoice)
		{
		case 1:
			CompTrapRule();
			break;
		case 2:
			CompTrapRule();
			break;
		default:
			std::cout << "Invalid selection, please enter try again." << std::endl;
			ProblemSelect();
		}
	}
	if (EquationSelect == 2)
	{
		switch (ProblemSelectChoice)
		{
		case 1:
			CompSimpRule();
			break;
		case 2:
			CompSimpRule();
			break;
		default:
			std::cout << "Invalid selection, please enter try again." << std::endl;
			ProblemSelect();
		}
	}
	return 0;
}

int main()
{
ProgramRestart:

	ClearVar();

ProgramStart:

	std::cout << "Please enter intial interval a.\n" << std::endl;
	std::cin >> a;
	std::cout << "Please enter intial interval b.\n" << std::endl;
	std::cin >> b;
	std::cout << "Please enter number of subintervals. \n" << std::endl;
	std::cin >> subIntCount;

Confirm:

	std::cout << "Are these values correct? Please enter 'y' or 'n' for yes or no correspondingly.\n" << std::endl;
	std::cout << "Initial range is: " << a << " to " << b << "." << std::endl;
	std::cout << "Number of Decimal Places needed for tolerance: " << b << std::endl;
	std::cout << "Max number of number of subintervals required is " << subIntCount << std::endl;
	std::cin >> ConfirmCheck;
	switch (ConfirmCheck)
	{
	case 'y':
		goto StartMath;
	case 'n':
		goto ProgramStart;
	case 'd':
		goto StartMath;
	default:
		std::cout << "Input not recognized, please try again." << std::endl;
		goto Confirm;
	}
StartMath:
		
		ProblemSelect();

		std::cout << "Approximated Integral Value is ";
		std::cout << std::setprecision(10) << FinalOutput;
		std::cout << std::endl;
		std::cout << "Equation used to solve is the " << EquationUsed[(EquationSelect - 1)] << std::endl;
		std::cout << "The number of subintervals used was: " << subIntCount << std::endl;
		std::cout << "The length of each subinterval h was: "; 
		std::cout << std::setprecision(10) << h << std::endl;
		std::cout << "\n" << std::endl;
		goto ProgramRestart;
}