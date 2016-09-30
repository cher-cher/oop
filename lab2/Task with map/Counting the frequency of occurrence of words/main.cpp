#include "stdafx.h"
#include "Counting the frequency of occurrence of words.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main()
{
	string text;
	getline(cin, text);
	
	stringstream stream(text);
	vector<string> words;
	string buf;
	while (stream >> buf)
	{
		words.push_back(buf);
	}

	map <string, size_t> result = CountWords(words);

	for (auto word : result)
	{
		cout << word.first << ": " << word.second << endl;
	}

	return 0;
}

