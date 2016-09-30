#include "stdafx.h"
#include "vector2.h"
#include <vector>
#include <iterator>  
#include <iostream>
#include <algorithm>
#include <boost/range/algorithm/transform.hpp>

using namespace std;

void ProcessVector(vector<double> &vector)
{
	if (vector.size())
	{
		double minElement = *std::min_element(begin(vector), end(vector));
		auto numberMultiplied = [minElement](double number)
		{
			return minElement * number;
		};
		boost::transform(vector, vector.begin(), numberMultiplied);
		sort(vector.begin(), vector.end());
	}
}