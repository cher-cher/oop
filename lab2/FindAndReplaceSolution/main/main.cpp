// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FindAndReplace.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "FindAndReplace.exe <search-string> <replace-string>" << endl;
		return 0;
	}
	cout << "Enter string: ";
	string subject;
	getline(cin, subject);
	cout << FindAndReplace(subject, argv[1], argv[2]) << endl;
    return 0;
}

