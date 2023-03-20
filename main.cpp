#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <chrono>
#include <algorithm>


//Variant 21
// f = sin(x) - x + 2.0
// x0 = 2.55
// Calc an integral function from it

double f(double x)
{
	return cos(x) + x * x / 2.0 - 2.0 * x;
}

double ff(double x)
{
	return -(sin(x) - x + 2.0);
}

double fff(double x)
{
	return -cos(x) + 1.0;
}

/*
double f(double x)
{
	return sin(x) - x + 2.0;
}

double ff(double x)
{
	return cos(x) - 1.0;
}

double fff(double x)
{
	return -sin(x);
}*/



void calcSecant(double L, double R)
{
	double z;
	double ffz;

	double Lprev;
	double Rprev;

	double eps = 0.0000000001;
	int m = 0;

	do
	{
		double ffR = ff(R);
		double ffL = ff(L);
		z = R - (ffR * (R - L)) / (ffR - ffL);

		ffz = ff(z);

		Lprev = L;
		Rprev = R;

		if (ffz < 0)
		{
			L = z;
		}
		else
		{
			R = z;
		}

		m++;

		std::cout << "Iteration just pased: " << m
			<< " L = " << Lprev
			<< " R = " << Rprev
			<< " ff(L) = " << ffL
			<< " ff(R) = " << ffR
			<< " z = " << z
			<< " ffz = " << ffz
			<< " eps = " << abs(ffz)
			<< std::endl;

	} while (abs(ffz) > eps);

	std::cout << " For eps = " << eps << " m = " << m << std::endl;
	std::cout << "Result: X=" << z << std::endl;


}


int main()
{
	double x0 = 2.55;

	calcSecant(x0 - 1.0, x0 + 1.0);

}