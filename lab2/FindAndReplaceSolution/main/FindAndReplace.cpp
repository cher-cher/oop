#include "stdafx.h"
#include "FindAndReplace.h"
#include <string>
#include <iostream>

using namespace std;

string FindAndReplace(string const& subject, string const& search, string  const& replace)
{
	size_t searchLength = search.length();
	size_t subjectLength = subject.length();
	if (searchLength == 0 || searchLength > subjectLength)
	{
		return subject;
	}
	
	string newStr = subject;
	size_t newStrLength = newStr.length();
	size_t foundPos = 0;

	while (foundPos <= newStrLength)
	{
		foundPos = newStr.find(search, foundPos);
		if (foundPos != string::npos)
		{
			newStr.replace(foundPos, searchLength, replace);
			foundPos += replace.length();
			newStrLength = newStr.length();
		}
	}
	return newStr;
}