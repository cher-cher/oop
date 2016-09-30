// Solve3Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Solve3/Solve3.h"

using namespace std;
void IsRootsEqual(const double roots[3], const double expectedRoots[3], const unsigned expectedNumbRoots)
{
	for (size_t i = 0; i < expectedNumbRoots; i++)
	{
		BOOST_CHECK_CLOSE(roots[i], expectedRoots[i], 0.001);
	}
}

void CheckRoots(EquationRoots3 const& result, const unsigned expectedNumbRoots, const double expectedRoots[])
{
	BOOST_CHECK_EQUAL(result.numRoots, expectedNumbRoots);
	IsRootsEqual(result.roots, expectedRoots, expectedNumbRoots);
}

BOOST_AUTO_TEST_SUITE(Solve3Test)

	BOOST_AUTO_TEST_CASE(coefficient_a_is_0)
	{
		BOOST_CHECK_THROW(Solve3(0, 1, 2, 3), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(equation_has_right_roots)
	{
		double expectedRoots1[3] = { 5, 1, -3 };
		CheckRoots(Solve3(3, -9, -39, 45), 3, expectedRoots1);
		
		double expectedRoots2[2] = { 3, -0.5 };
		CheckRoots(Solve3(2, -11, 12, 9), 2, expectedRoots2);
	}

BOOST_AUTO_TEST_SUITE_END()