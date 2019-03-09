#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const unsigned int ARGUMENT_COUNT = 4;
const unsigned int NOTATION_BASE = 10;
const char* ALLOWED_SYMBOLS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int isCorrectNotation(const char* notation, bool& wasError)
{
	if (!isdigit(strtol(notation, nullptr, NOTATION_BASE)))
	{
		wasError = true;
		return 1;
	}

	const int base = strtol(notation, nullptr, NOTATION_BASE);

	if (base > 1 && base < 36)
	{
		return base;
	}
	else
	{
		wasError = true;
		return 1;
	}
}

long long int StringToInt(const char* str, int radix, bool& wasError)
{
	const char* symbol = str;
	while (*symbol)
	{
		const char* position = strchr(ALLOWED_SYMBOLS, *symbol);
		if (position == NULL || position - ALLOWED_SYMBOLS + 1 >= radix)
		{
			wasError = true;
			return 1;
		}
			
		++symbol;
	}

	if (!wasError)
	{
		char *end;
		const long long int convertedValue = strtoull(str, &end, radix);

		if (convertedValue > LONG_MAX && convertedValue < LONG_MIN)
		{
			wasError = true;
			return 1;
		}
		else
		{
			return convertedValue;
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	bool wasError = false;

	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	const int sourceNotation = isCorrectNotation(argv[1], wasError);
	const int destinationNotation = isCorrectNotation(argv[2], wasError);

	if (wasError)
	{
		cout << "Invalid source notation\n"
			 << "The base should be from 2 to 36\n";
		return 1;
	}

	long long int inputValue = StringToInt(argv[3], sourceNotation, wasError);

	if (wasError)
	{
		cout << "Invalid value\n";
		return 1;
	}

	return 0;
}
