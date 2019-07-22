#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

# define M_PI           3.14159265358979323846  /* pi */

const double EulerConstant = std::exp(1.0);
bool DebugMode = false; // Sets up a mode to print out values for each iteration

int ProblemSelectChoice;

long float Xsub0; //initial point
long float Xsub1; //Result after 1 Newton's Run
long float fXsub0; // Function of x sub 0
long float fXsub0Prime; // Function of x sub 1

long float NMAX; // Variables used for iterations
long float x = 0; // ^ (Starts at 0 to indicated the first iteration)

long float a; // user input values that will be assigned to equation variables.
long float b; // ^

long float AbsX; // Returns the absolute values of x
long float AbsFx; // Returns the absolute values of Fx

bool NoZeros = true;

long float TOL1; // Input Tolerance value
long float TOL2; // Second Input Tolerance value

char ConfirmCheck;
char end;


double absvarX0andX1()
{
	AbsX = Xsub0 - Xsub1;
	AbsX = std::abs(AbsX);
	return 0;
}

double absvarFx0()
{
	AbsFx = std::abs(fXsub0);
	return 0;
}

double CheckZeros() // Needed to be true otherwise the program won't run.
{
	if ((fXsub0 == 0) && (fXsub0Prime == 0))
	{
		NoZeros = false;
	}
	return 0;
}

double Equation1()
{
	fXsub0 = pow(EulerConstant, Xsub0) + Xsub0 - 7.0;
	fXsub0Prime = pow(EulerConstant, Xsub0) + 1.0;
	return 0;
}

double Equation2()
{
	fXsub0 = ((4.0 / 3.0) * M_PI * (pow(Xsub0, 3.0))) - (10.0 * M_PI * (pow(Xsub0, 2.0))) - 400.0;
	fXsub0Prime = ((4.0 * M_PI * (pow(Xsub0, 2.0))) - (20.0 * M_PI * Xsub0));
	return 0;
}

double Equation3()
{
	fXsub0 = ((4.0 * pow(Xsub0, 3.0)) - 1.0 - (pow(EulerConstant, (pow(Xsub0, 2.0) / 2.0))));
	fXsub0Prime = ((12.0 * pow(Xsub0, 2.0)) - ((pow(EulerConstant, (pow(Xsub0, 2.0) / 2.0))) * Xsub0));
	return 0;
}


double NewtonsEquation()
{
	if (x == 0) // used to get an itial value for X sub 1.
	{
		Xsub1 = Xsub0 - (fXsub0 / fXsub0Prime);
		x++;
	}
	else
	{
		Xsub0 = Xsub1;
		switch (ProblemSelectChoice)
		{
		case 1:
			Equation1();
			break;
		case 2:
			Equation2();
			break;
		case 3:
			Equation3();
			break;
		}
	}
		Xsub1 = Xsub0 - (fXsub0 / fXsub0Prime);
	return 0;
}


double ProblemSelect()
{
	std::cout << "Which problem would you like to solve, '1', '2', or '3'?" << std::endl;
	std::cin >> ProblemSelectChoice;
	switch (ProblemSelectChoice)
	{
	case 1:
		Equation1();
		break;
	case 2:
		Equation2();
		break;
	case 3:
		Equation3();
		break;
	default:
		std::cout << "Invalid selection, please enter try again." << std::endl;
		ProblemSelect();
	}
	return 0;
}

double TOLCalculations()
{
	TOL1 = (0.5) * pow(10.0, (b * -1.0));
	return 0;
}

double IterationsofNewtons()
{
	TOLCalculations();
	NewtonsEquation();
	absvarX0andX1();
	while ((AbsX > TOL1)
		//|| AbsFx > TOL2		// Uncomment when you figure out how to implement TOL2
		 && (x < NMAX))
	{
		switch (ProblemSelectChoice)
		{
		case 1:

			Equation1();
			NewtonsEquation();
			absvarX0andX1();
			break;
		case 2:
			Equation2();
			NewtonsEquation();
			absvarX0andX1();
			break;
		case 3:
			Equation3();
			NewtonsEquation();
			absvarX0andX1();
			break;
		}
		if (DebugMode == true)
		{
			std::cout << "Iteration number " << x;
			std::cout << std::endl;
			std::cout << "Values for X Sub 0: ";
			std::cout << std::setprecision((b + 3)) << Xsub0;
			std::cout << std::endl;
			std::cout << "Values for X Sub 1: ";
			std::cout << std::setprecision((b + 3)) << Xsub1;
			std::cout << std::endl;
			std::cout << "Values for FxSub0: ";
			std::cout << std::setprecision((b + 3)) << fXsub0;
			std::cout << std::endl;
			std::cout << "Values for Derivative of FxSub0: ";
			std::cout << std::setprecision((b + 3)) << fXsub0Prime;
			std::cout << std::endl;
			std::cout << "Absolute value of X sub 0 minus X sub 1: ";
			std::cout << std::setprecision((b + 3)) << AbsX;
			std::cout << "\n" << std::endl;
		}
		if (DebugMode == false)
		{
			std::cout << "Iteration number " << x;
			std::cout << std::endl;
			std::cout << "Values for X Sub 1: ";
			std::cout << std::setprecision((b + 3)) << Xsub1;
			std::cout << "\n" << std::endl;
		}
		x++;
	}
	return 0;
}

int main()
{
ProgramStart:

	std::cout << "Please enter intial guess.\n" << std::endl;
	std::cin >> a;
	std::cout << "Please enter number of decimal places needed for tolerance. \n" << std::endl;
	std::cin >> b;
	std::cout << "Please enter max number of iterations required." << std::endl;
	std::cin >> NMAX;

Confirm:

	std::cout << "Are these values correct? Please enter 'y' or 'n' for yes or no correspondingly.\n" << std::endl;
	std::cout << "Initial Guess is: " << a << std::endl;
	std::cout << "Number of Decimal Places needed for tolerance: " << b << std::endl;
	std::cout << "Max number of iterations required is " << NMAX << std::endl;
	std::cin >> ConfirmCheck;
	switch (ConfirmCheck)
	{
	case 'y':
		Xsub0 = a;
		goto StartMath;
	case 'n':
		goto ProgramStart;
	case 'd':
		Xsub0 = a;
		DebugMode = true;
		goto StartMath;
	default:
		std::cout << "Input not recognized, please try again." << std::endl;
		goto Confirm;
	}
StartMath:
	ProblemSelect();
//	if (DebugMode == true)
//	{
//		std::cout << "Value of function X sub 0:";
//		std::cout << std::setprecision((b + 2)) << fXsub0;
//		std::cout << std::endl;
//		std::cout << "Value of function X sub 0 Prime:";
//		std::cout << std::setprecision((b + 2)) << fXsub0Prime;
//		std::cout << std::endl;
//	}
////Debug used to check why programs weren't running due to zeros.
	CheckZeros();
	if (NoZeros == false)
	{
		std::cout << "Problem cannot be completed as there is either a 0 in the denominator or numerator." << std::endl;
	}
	else
	{
		IterationsofNewtons();
		if (((AbsX < TOL1) // Success Condition
			//&& AbsFx < TOL2		// Uncomment when you figure out how to implement TOL2
			) || (x < NMAX))
		{

			std::cout << "Initial Guess is ";
			std::cout << a;
			std::cout << std::endl;
			std::cout << "Last Value for Xn: ";
			std::cout << std::setprecision((b + 3)) << Xsub1;
			std::cout << std::endl;
			std::cout << "Last Iteration number " << x;
			std::cout << std::endl;
			std::cout << "\n" << std::endl;
			goto ProgramStart;
		}
		if (x = NMAX) //Fail case that sends the program to the start.
		{
			std::cout << "Maximum Number of iterations reached. Solution Failed.";
			goto ProgramStart;
		}
	}
}

/* 
Set initial values x(sub 0 ) = a, TOL1, TOL2
Compute f(x sub 0), first deriv (x sub 0).

If (f(x sub 0) /= 0) AND (first deriv (x sub 0) =/ 0)
Repeat
	set x sub 1 = x sub 0
	set x sub 0 = x sub 0 - (f(x sub 0) / first deriv (x sub 0))

Until (|x sub 0 - x sub 1| < TOL1)
	OR
(|f(x sub 0)| < TOL 2)

TOL1 and TOL2 are tolerance values.


*/