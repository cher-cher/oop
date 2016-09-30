#include "stdafx.h"
#include <iostream> //std::
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <io.h>
#include <locale.h>
#include <cstring>
#include <windows.h>

using namespace std;

size_t PrefFunc(const string &findString)
{
	int lenPref = 0; //длина префикса
	int lenFindStr = findString.length();
	vector<int> pref(lenFindStr);
	pref[0] = 0;//наибольший собственный префикс

	for (size_t i = 1; i < findString.length(); ++i)
	{
		while ((lenPref > 0) && (findString[i] != findString[lenPref]))
		{
			lenPref = pref[lenPref - 1];
		}
		if (findString[lenPref] == findString[i])
		{
			lenPref++;
		}
		pref[i] = lenPref;
	}
	return lenPref;
}


bool KMP(const string &findString, const string &str)
{
	size_t lenStr = str.length();
	size_t lenFindStr = findString.length();
	size_t lenPref = PrefFunc(findString);
	vector<int> pref(lenFindStr);
	if (lenStr < lenFindStr)
		return false;
	else
	{
		for (size_t i = 0; i < lenStr; ++i)
		{
			while ((lenPref > 0) && (findString[lenPref] != str[i]))
				lenPref = pref[lenPref - 1];
			if (str[i] == findString[lenPref])
				lenPref++;
			if (lenPref == lenFindStr)
			{
				return true;
			}
		}
		return false;
	}
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Rus");
	string fileName;
	string str;
	string findStr;
	int counterStr = 1;
	bool result;
	vector<size_t> listStr;
	int i = 0;

	fileName = argv[1];
	ifstream fin;
	fin.open(fileName);

	char *tmp = new char[1000];
	cout << "Введите слово/подстроку, которую необходимо найти -> ";
	cin.getline(tmp, 1000);
	OemToCharA(tmp, tmp);
	findStr = tmp;
	delete[] tmp;
	result = KMP(findStr, str);
	cout << result;
	cout << "\n";

	if (fin)
	{
		while (getline(fin, str))
		{
			if (result)
			{
				cout << "Номер строки, в которой нашли подстроку " << counterStr<< "\n";
			}
			counterStr++;
		}
	}
	else
		cout << "ERROR! CAN'T OPEN THE FILE!";
    return 0;
}