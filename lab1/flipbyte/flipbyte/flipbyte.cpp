/*
Разработайте приложение flipbyte.exe, выполняющее изменение порядка следования двоичных битов в 8-битовом целом числе (байте),
заданном в десятичном представлении, на противоположный. Для этого используйте операторы для работы с битами.
«Перевернутый» байт выводится в output также в десятичном представлении с завершающим символом перевода строки \n.
*/

#include "stdafx.h"
#include <iostream> 
#include <vector>
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi
#include <cstring> //для фнукции strlen
#include <cmath>
#include <vld.h>

using namespace std;

const size_t NUMBER_OF_BYTE = 8;

bool CheckingArg(const char *str)
{
	bool number = true;
	for (int i = 0; i < strlen(str); i++)
	{
		number = number * isdigit(str[i]);
	}
	return number;
}

size_t TranslationOnStrToNumb (const char *str)
{
	size_t errorStr;
	if (CheckingArg(str))
	{
		size_t inputByte = atoi(str);
		return inputByte;
	}
	else
	{
		return errorStr = -1;
	}
}

void DecOnBin(size_t inputByte, vector<size_t> &binBytes, size_t i = 0)
{
	if (inputByte)
	{
		while (inputByte > 0)
		{
			binBytes[i] = inputByte % 2;
			inputByte = inputByte / 2;
			i++;
		}
	}
}

size_t BinOnDec(const vector<size_t> &binBytes)
{
	size_t numberOfDec = 0;
	int x = 0;
	for (size_t i = 0; i < binBytes.size(); i++)
	{
		x = 2*x + binBytes[i];
	}
	numberOfDec = x;
	return numberOfDec;
}

int main(int argc, char * argv[])
{
	vector<size_t> bytes(NUMBER_OF_BYTE, 0);
	if (argc == 2)
	{
		size_t byte = TranslationOnStrToNumb(argv[1]);
		if ((byte < 256) && (byte >= 0))
		{
			DecOnBin(byte, bytes);
			cout << BinOnDec(bytes);
		}
		else
		{
			//cout << "Incorrect input data" << endl;
			return 1;
		}
	}
	else
	{
		//cout << "Error input\nExample input flipbyte.exe <input byte>\n";
		return 1;
	}
	system("pause");
    return 0;
}

