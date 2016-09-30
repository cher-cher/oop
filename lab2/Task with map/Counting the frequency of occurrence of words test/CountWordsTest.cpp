#include "stdafx.h"
#include <sstream>
#include <string>
#include <vector>
#include "../Counting the frequency of occurrence of words/CountWords.h"

using namespace std;

vector<string> StringInVector(string text)
{
	stringstream stream(text);
	vector<string> words;
	string buf;
	while (stream >> buf)
	{
		words.push_back(buf);
	}
	return words;
}


BOOST_AUTO_TEST_SUITE(CountWords_function)

BOOST_AUTO_TEST_CASE(should_make_empty_map_from_empty_string)
{
	string emptyString;
	vector<string> text;
	text = StringInVector(emptyString);
	map<string, size_t> checkedMap;
	checkedMap = CountWords(text);
	BOOST_CHECK(checkedMap.empty());
}

BOOST_AUTO_TEST_CASE(should_count_numb_occurrences_of_words)
{
	string inputString;
	inputString = "I ate green Apple and red apPLe";
	vector<string> text;
	text = StringInVector(inputString);
	map<string, size_t> rightMap = {
		{ "and", 1 },
		{ "apple", 2 },
		{ "ate", 1 },
		{ "green", 1 },
		{ "i", 1 },
		{ "red", 1 }
	};
	map<string, size_t> checkedMap;
	checkedMap = CountWords(text);
	BOOST_CHECK(checkedMap == rightMap);
}
BOOST_AUTO_TEST_SUITE_END()