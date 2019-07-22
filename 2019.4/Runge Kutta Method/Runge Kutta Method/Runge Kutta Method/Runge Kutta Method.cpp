#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>

# define M_PI           3.14159265358979323846  /* pi */

const double EulerConstant = std::exp(1.0);

int EquationSelect; //used to select the equation for the equation string

double RKFinalValue[100];



double a; // user input values that will be assigned to equation variables.
double b; // ^
double k1;
double k2;
double k3;
double k4;
double h; //variable in the equation
double initialcond;

int IterationNum;

double FinalOutput;

char ConfirmCheck;
char end;

int ClearVar()
{
	a = 0.0;
	b = 0.0;
	initialcond = 0;
	h = 0.0;
	return 0;
}



double Equation1(double t0, double y0)
{
	return (pow(y0, 2)) + 1;
}

double Equation2(double t0, double y0)
{
	return 5 * pow(t0, 4) * y0;
}

double RungeKutta(double t0, double y0, double h, double x)
{
	if (EquationSelect == 1)
	{
		int n = ((x - t0) / h);
		IterationNum = n;

		// Iterate for number of iterations 
		double y = y0;
		for (int i = 1; i <= n; i++)
		{
			// Apply Runge Kutta Formulas to find 
			// next value of y 
			k1 = h * Equation1(t0, y);
			k2 = h * Equation1(t0 + 0.5*h, y + 0.5*k1);
			k3 = h * Equation1(t0 + 0.5*h, y + 0.5*k2);
			k4 = h * Equation1(t0 + h, y + k3);

			// Update next value of y 
			y = y + (1.0 / 6.0)*(k1 + 2 * k2 + 2 * k3 + k4);

			// Update next value of x 
			t0 = t0 + h;
			RKFinalValue[i] = y;
		}
	}
	if (EquationSelect == 2)
	{
		{
			int n = ((x - t0) / h);
			IterationNum = n;

			// Iterate for number of iterations 
			double y = y0;
			for (int i = 1; i <= n; i++)
			{
				// Apply Runge Kutta Formulas to find 
				// next value of y 
				k1 = h * Equation2(t0, y);
				k2 = h * Equation2(t0 + 0.5*h, y + 0.5*k1);
				k3 = h * Equation2(t0 + 0.5*h, y + 0.5*k2);
				k4 = h * Equation2(t0 + h, y + k3);

				// Update next value of y 
				y = y + (1.0 / 6.0)*(k1 + 2 * k2 + 2 * k3 + k4);

				// Update next value of x 
				t0 = t0 + h;
				RKFinalValue[i] = y;
			}
		}
	}
	return 0;
}

double ProblemSelect()
{
	std::cout << "Which problem would you like to solve, '1' or '2'?" << std::endl;
	std::cin >> EquationSelect;

		switch (EquationSelect)
		{
		case 1:
			RungeKutta(a, initialcond, h, b);
			break;
		case 2:
			RungeKutta(a, initialcond, h, b);
			break;
		default:
			std::cout << "Invalid selection, please enter try again." << std::endl;
			ProblemSelect();
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
	std::cout << "Please enter the initial condition y(a) = (y0): " << std::endl;
	std::cin >> initialcond;
	std::cout << "Please enter length of subintervals. \n" << std::endl;
	std::cin >> h;

Confirm:

	std::cout << "Are these values correct? Please enter 'y' or 'n' for yes or no correspondingly.\n" << std::endl;
	std::cout << "Initial range is: " << a << " to " << b << "." << std::endl;
	std::cout << "Initial condition y(a) = (y0) is: " << initialcond << std::endl;
	std::cout << "Length of h is " << h << std::endl;
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
	for (int j = 0; j != (IterationNum+1); j++)
	{
		std::cout << "Approximated Integral Value for iteration " << j << " is: ";
		std::cout << std::setprecision(10) << RKFinalValue[j];
		std::cout << std::endl;
	}

	goto ProgramRestart;
}