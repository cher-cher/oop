// Solve3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Solve3.h"

using boost::math::double_constants::pi;
using namespace std;

void ShowRoots(EquationRoots3 const & roots)
{
	for (size_t i = 0; i < roots.numRoots; i++)
	{
		cout << roots.roots[i] << " ";
	}
}

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	EquationRoots3 roots;
	if (a == 0)
	{
		throw invalid_argument("Argument 'a' can not be 0.");
	}
	else
	{
		b = b / a;
		c = c / a;
		d = d / a;
	}
	double q = (pow(b, 2) - 3.0 * c) / 9.0;
	double r = (2.0 * pow(b, 3) - 9.0 * b * c + 27.0 * d) / 54.0;
	double s = pow(q, 3) - pow(r, 2);
	if (s > 0)
	{
		double grad = r / sqrt(pow(q, 3));
		double fi = (1.0 / 3.0) * acos(grad);

		roots.roots[0] = -2 * sqrt(q) * cos(fi) - b / 3.0;
		roots.roots[1] = -2 * sqrt(q) * cos(fi + 2 * pi / 3.0) - b / 3.0;
		roots.roots[2] = -2 * sqrt(q) * cos(fi - 2 * pi / 3.0) - b / 3.0;
		roots.numRoots = 3;
	}
	else if(s == 0)
	{
		roots.roots[0] = -2 * ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(q) - b / 3;
		roots.roots[1] = ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(q) - b / 3;
		roots.numRoots = 2;
	}
	else if (s < 0)
	{
		if (q == 0)
		{
			roots.roots[0] = -pow(d - pow(b, 3) / 27, 1 / 3) - b / 3;
			roots.numRoots = 1;
		}
		else
		{
			double fi = (1.0 / 3.0) * (q > 0 ? acosh(abs(r) / sqrt(pow(abs(q), 3))) : asinh(abs(r) / sqrt(pow(abs(q), 3))));
			roots.roots[0] = -2 * ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(abs(q))*(q > 0 ? cosh(fi) : sinh(fi)) - b / 3.0;
			roots.numRoots = 1;
		}
	}
	sort(rbegin(roots.roots), rend(roots.roots));
	return roots;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Input coefficient a b c d: ";
	vector<double> number(istream_iterator<double>(cin), (istream_iterator<double>()));
	ShowRoots(Solve3(number[0], number[1], number[2], number[3]));
	return 0;
}

