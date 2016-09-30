#include "stdafx.h"
#include "vector2.h"
#include <vector>
#include <iterator>  
#include <iostream>
#include <algorithm>
#include <boost/range/algorithm/transform.hpp>

using namespace std;

vector<double> ReadVector(std::istream & input)
{
	return{ istream_iterator<double>(input), (istream_iterator<double>()) };
}

int main()
{
	auto number = ReadVector(std::cin);
	ProcessVector(number);
	copy(begin(number), end(number), ostream_iterator<double>(cout, " "));
	return 0;
}