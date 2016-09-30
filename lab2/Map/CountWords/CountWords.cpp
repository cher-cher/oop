#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <boost/range/algorithm/transform.hpp>
#include "CountWords.h"

using namespace std;

map<string, size_t> CountWords(const vector<string> & words)
{
	map<string, size_t> result;
	for (auto word : words)
	{
		boost::transform(word, word.begin(), tolower);
		++result[word];
	}
	return result;
}