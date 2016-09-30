#pragma once
#include "stdafx.h"

struct EquationRoots3
{
	unsigned numRoots = 0;
	double roots[3];
};

EquationRoots3 Solve3(double a, double b, double c, double d);